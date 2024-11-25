/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
 */

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main() performs following functions:
*  1: 
*  2: 
*  3:
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/

/* PSoC5 */
#include <device.h>
#include <stdio.h>
#include <math.h>
/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* API */
#include "I2C_CLCD.h"
#include "rot.h"
#include "key.h"

/* Project Defines */
#define FALSE  0
#define TRUE   1

/* Frequency Defines */
#define STATION_MAX 4
                                  /* 0123456789012345 */
char *STATION_NAME[STATION_MAX] = { "NHK1            ",
                                    "NHK2            ",
                                    "TBC             ",
                                    "BEACON          " };
uint32 STATION_FREQ[STATION_MAX] = { 891000, 1089000, 1260000, 457000};
uint32 ADJ_FREQ[STATION_MAX]     = {   0,    0,    0,    800};

/* Resources for FreeRTOS */
#define TASK_STACK_LED   128
#define TASK_STACK_KEY   128
#define TASK_STACK_ROT   256
#define TASK_STACK_DDR   512
#define TASK_STACK_RADIO 1024

#define TASK_PRIORITY_LED (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_KEY (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_ROT (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_DDR (tskIDLE_PRIORITY + 2)
#define TASK_PRIORITY_RADIO (tskIDLE_PRIORITY + 1)

void Task_LED   (void *pvParameters);
void Task_KEY   (void *pvParameters);
void Task_ROT   (void *pvParameters);
void Task_DDR   (void *pvParameters);
void Task_RADIO (void *pvParameters);

xSemaphoreHandle xMutex_CLCD;       /* Mutex for CLCD Port */

xQueueHandle xQueue_KEY[2];
xQueueHandle xQueue_ROT;    /* Queue Data from Task_ROT(ROT_ENC_Handler) */
xQueueHandle xQueue_IQ[2];  /* Queue Data from CY_ISR(Filter_Handler) */

/* Function Prototypes */
void prvHardwareSetup(void);
void CORDIC(int32 x, int32 y, int32 *radius);
void Filter_Handler(void);


/***************************************************************************
*	main()
****************************************************************************/

int main()
{
    prvHardwareSetup();
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Initializes the I2C CLCD. */
    I2C_1_Start();
    I2C_CLCD_Start();
   /* Initialize API */
    Init_ROT();
    Init_Key();
    /* Initialize the SPI Master */
    SPIM_Start();

    /* Create Tasks */
    xMutex_CLCD = xSemaphoreCreateMutex();
    xQueue_ROT    = xQueueCreate(8, 1);     /* 8 x 1byte */
    xQueue_KEY[0] = xQueueCreate(1, 1);     /* 1 x 1byte */
    xQueue_KEY[1] = xQueueCreate(1, 1);     /* 1 x 1byte */

    xQueue_IQ[0]  = xQueueCreate(8, 4); // 8 x 4bytes
    xQueue_IQ[1]  = xQueueCreate(8, 4); // 8 x 4bytes

    I2C_CLCD_Position(0u,0u);
    /*                    0123456789012345 */
    I2C_CLCD_PrintString("Simple_SDR_Rx");
    I2C_CLCD_Position(1u,0u);
    I2C_CLCD_PrintString("get started");

    CyDelay(1000u);

    xTaskCreate(Task_LED, "LED", TASK_STACK_LED, NULL, TASK_PRIORITY_LED, NULL);
    xTaskCreate(Task_ROT, "ROT", TASK_STACK_ROT, NULL, TASK_PRIORITY_ROT, NULL);
    xTaskCreate(Task_KEY, "KEY", TASK_STACK_KEY, NULL, TASK_PRIORITY_KEY, NULL);
    xTaskCreate(Task_DDR, "DDR", TASK_STACK_DDR, NULL, TASK_PRIORITY_DDR, NULL);
    xTaskCreate(Task_RADIO, "RADIO", TASK_STACK_RADIO, NULL, TASK_PRIORITY_RADIO, NULL);

    /* Start RTOS Kernel */
    vTaskStartScheduler();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/*---------------------------------------------------------------------------*/
void prvHardwareSetup( void )
{
    /* Port layer functions that need to be copied into the vector table. */
    extern void xPortPendSVHandler( void );
    extern void xPortSysTickHandler( void );
    extern void vPortSVCHandler( void );
    extern cyisraddress CyRamVectors[];

	/* Install the OS Interrupt Handlers. */
	CyRamVectors[ 11 ] = ( cyisraddress ) vPortSVCHandler;
	CyRamVectors[ 14 ] = ( cyisraddress ) xPortPendSVHandler;
	CyRamVectors[ 15 ] = ( cyisraddress ) xPortSysTickHandler;
    
}
/*---------------------------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	/* The stack space has been execeeded for a task, considering allocating more. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*---------------------------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* The heap space has been execeeded. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*---------------------------------------------------------------------------*/


/***************************************************************************
*	Task_LED
****************************************************************************/

void Task_LED(void *pvParameters)
{
    /* Block time in (ms) */
    const portTickType OnDelay = 100 / portTICK_RATE_MS;
    const portTickType OffDelay = 900 / portTICK_RATE_MS;

    while(1)
    {
        LED_Write(1);
        vTaskDelay(OnDelay);
        
        LED_Write(0);
        vTaskDelay(OffDelay);
    }
}


/***************************************************************************
*	Task_DDR
****************************************************************************/

#define BUFSIZE 20

void Task_DDR(void *pvParameters)
{
    uint8  ch = 0;          /* station number */
    int32  freq;            /* target Freq(kHz) 1kHz ~ 40MHz */
    int32  newfreq;
    int64  wdata;           /* set value of AD9850 using 125MHz X-tal */
    uint8  w[5] = {0xf8u, 0x08u, 0x4cu, 0x07u, 0x00u};

    char   str[BUFSIZE];
    uint8  qmsg;
    int8   click;
    uint32 i;

    /* Block for 50ms */
    const portTickType xDelay = 100 / portTICK_RATE_MS;
    
    /* set DDS to default frequency */
    SPIM_WriteTxData(w[0]);
    SPIM_WriteTxData(w[1]);
    SPIM_WriteTxData(w[2]);
    SPIM_WriteTxData(w[3]);
    SPIM_WriteTxData(w[4]);

    vTaskDelay(xDelay);

    /* Take xMutex_CLCD */
    xSemaphoreTake(xMutex_CLCD, portMAX_DELAY);

    /* Show the initial station and Frequency */
    sprintf(str, "%s", STATION_NAME[0u]);
    I2C_CLCD_Position(0u, 0u);
    I2C_CLCD_PrintString(str);
    I2C_CLCD_Position(1u, 0u);
    I2C_CLCD_PrintString("Freq:");
    /* newfreq will set the Main Loop */
    freq = 0u;
    //newfreq = STATION_FREQ[ch] + ADJ_FREQ[ch];
    newfreq = (STATION_FREQ[ch] + ADJ_FREQ[ch]) * 4;
    
    xSemaphoreGive(xMutex_CLCD);
    vTaskDelay(xDelay);    
    
    /* Main Loop */
    for(;;)
    {
        xSemaphoreTake(xMutex_CLCD, portMAX_DELAY);
        
        /* Get click count of ROT */
        if (uxQueueMessagesWaiting(xQueue_ROT) > 0)
        {
            xQueueReceive(xQueue_ROT, &click, 0);
            /* the target frequency */
            newfreq += (click * 1);
        }
        
        if (xQueueReceive(xQueue_KEY[0], &qmsg, 0))
        {
            ch++;
            if (ch >= STATION_MAX)
                ch = 0;
            /* setup the new station */
            I2C_CLCD_PrintString("                ");
            sprintf(str, "%s", STATION_NAME[ch]);
            I2C_CLCD_Position(0u, 0u);
            I2C_CLCD_PrintString(str);
            /* the target frequency */
            newfreq = (STATION_FREQ[ch] + ADJ_FREQ[ch]) * 4;
        }
        
        if (newfreq != freq)
        {
            wdata = newfreq * 0x100000000u;
            wdata /= 125000000;

            for (i = 0; i < 4; i++)
                w[i] = (uint8)((wdata >> i*8) & 0x000000FFu);
                /* if recieved expected string (number)? */
            if ((newfreq < 40000000) && (newfreq > 0))
            {
                /* writing data to the SPIM software buffer */
                SPIM_WriteTxData(w[0]);
                SPIM_WriteTxData(w[1]);
                SPIM_WriteTxData(w[2]);
                SPIM_WriteTxData(w[3]);
                SPIM_WriteTxData(w[4]);

                /* We need to know the moment when SPI communication is complete
                * to display received data. SPIS_SPI_DONE status should be polled. 
                */
                while(!(SPIM_ReadTxStatus() & SPIM_STS_SPI_DONE));
                
                freq = newfreq;
                sprintf(str, "%7ld[Hz]", freq/4);
            }
            else
            {
                sprintf(str, "Error  [Hz]");
            }
            I2C_CLCD_Position(1u, 5u);
            I2C_CLCD_PrintString(str);
        }
        xSemaphoreGive(xMutex_CLCD);

        vTaskDelay(xDelay);
    }
}



/***************************************************************************
*	Task_RADIO
****************************************************************************/
/* Define AGC Parameter */
#define AGC_TIM_MAX (25000 * 2) // 2sec
#define AGC_TIM_INI (AGC_TIM_MAX - 25000 / 4) // 1.75sec

#define V_OFFSET    125    /* 2V = 125 * 16 (mV/bit) */

/*********************************
*	CORDIC Routine (16bits)*
*	(calculate amplitude)
**********************************/
/* 1/1.6467602 * 65536 */
const int32 K = 39797;

void CORDIC(int32 x, int32 y, int32 *radius)
{
    int32 i;
    int32 u;

    for (i = 0; i < 16; i++)
    {
        if (y >= 0) {u = x + (y >> i); y = y - (x >> i);}
        else        {u = x - (y >> i); y = y + (x >> i);}
        x = u;
    }

    /* x = xqrt(x^2 + y^2) * K  (K=1.6467602) */
    *radius = x;
}

/*********************************
*	Filter Interrupt Handler
**********************************/
CY_ISR(Filter_Handler)
{
    int32 filter_I;
    int32 filter_Q;

    if (Filter_1_IsInterruptChannelA())
    {
        filter_I = (int32)((int16)Filter_1_Read16(Filter_1_CHANNEL_A));
        /* clear flags except INTR_HOLDB */
        Filter_1_SR_REG = Filter_1_ALL_INTR & (~Filter_1_CHANNEL_B_INTR);
        /* Send the Data to Queue */
        xQueueSendFromISR(xQueue_IQ[0], &filter_I, NULL);
    }
    if (Filter_1_IsInterruptChannelB())
    {
        filter_Q = (int32)((int16)Filter_1_Read16(Filter_1_CHANNEL_B));
        /* clear flags except INTR_HOLDA */
        Filter_1_SR_REG = Filter_1_ALL_INTR & (~Filter_1_CHANNEL_A_INTR);
        /* Send the Data to Queue */
        xQueueSendFromISR(xQueue_IQ[1], &filter_Q, NULL);
    }
}

/*---------------------------------------------------------------------------*/

/*******************************************************************************
* Function Name: DMA_1_Config, DMA_2_Config
********************************************************************************
*
* Summary:
*  Initializes and sets up DMA for use (generated by DMA Wizard)
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DMA_1_Config(void)
{
/* Defines for DMA_1 */
#define DMA_1_BYTES_PER_BURST 2
#define DMA_1_REQUEST_PER_BURST 1
#define DMA_1_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_1_DST_BASE (CYDEV_PERIPH_BASE)

/* Variable declarations for DMA_1 */
/* Move these variable declarations to the top of the function */
uint8 DMA_1_Chan;
uint8 DMA_1_TD[1];

/* DMA Configuration for DMA_1 */
DMA_1_Chan = DMA_1_DmaInitialize(DMA_1_BYTES_PER_BURST, DMA_1_REQUEST_PER_BURST, 
    HI16(DMA_1_SRC_BASE), HI16(DMA_1_DST_BASE));
DMA_1_TD[0] = CyDmaTdAllocate();
CyDmaTdSetConfiguration(DMA_1_TD[0], 2, DMA_INVALID_TD, DMA_1__TD_TERMOUT_EN | TD_INC_SRC_ADR | TD_INC_DST_ADR);
CyDmaTdSetAddress(DMA_1_TD[0], LO16((uint32)ADC_SAR_1_SAR_WRK0_PTR), LO16((uint32)Filter_1_STAGEA_PTR));
CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
CyDmaChEnable(DMA_1_Chan, 1);
}

void DMA_2_Config(void)
{
/* Defines for DMA_2 */
#define DMA_2_BYTES_PER_BURST 2
#define DMA_2_REQUEST_PER_BURST 1
#define DMA_2_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_2_DST_BASE (CYDEV_PERIPH_BASE)

/* Variable declarations for DMA_2 */
/* Move these variable declarations to the top of the function */
uint8 DMA_2_Chan;
uint8 DMA_2_TD[1];

/* DMA Configuration for DMA_2 */
DMA_2_Chan = DMA_2_DmaInitialize(DMA_2_BYTES_PER_BURST, DMA_2_REQUEST_PER_BURST, 
    HI16(DMA_2_SRC_BASE), HI16(DMA_2_DST_BASE));
DMA_2_TD[0] = CyDmaTdAllocate();
CyDmaTdSetConfiguration(DMA_2_TD[0], 2, DMA_INVALID_TD, DMA_2__TD_TERMOUT_EN | TD_INC_SRC_ADR | TD_INC_DST_ADR);
CyDmaTdSetAddress(DMA_2_TD[0], LO16((uint32)ADC_SAR_2_SAR_WRK0_PTR), LO16((uint32)Filter_1_STAGEB_PTR));
CyDmaChSetInitialTd(DMA_2_Chan, DMA_2_TD[0]);
CyDmaChEnable(DMA_2_Chan, 1);
}

/*---------------------------------------------------------------------------*/
void Task_RADIO(void *pvParameters)
{
    int32  filter_I;
    int32  filter_Q;
    uint32  level_I;
    uint32  level_Q;
    uint8  dac;
    int32  radius;

    /* DMA Configuration */
    DMA_1_Config();
    DMA_2_Config();
    
    /* Start Input PGA/Comp */
    PGA_1_Start();
    PGA_2_Start();
    
    /* Start Input Comp */
    Comp_1_Start();

    /* Start Audio DAC */
    VDAC8_1_Start();
    VDAC8_2_Start();

    /* Start Filters */
    Filter_1_Start();
    Filter_1_INT_CTRL_REG = Filter_1_INT_CTRL_REG | 0x03;    /* to enable software polling */
    /*
     *  STAGEA, STAGEB : L/M written by DMAC (key byte lane is M, need 8bit alignment)
     *  HOLDA,  HOLDB  : M/H read by CPU     (key byte lane is H, no need alignment)
     */
    Filter_1_SetCoherencyEx(Filter_1_STAGEA_COHER, Filter_1_KEY_MID);
    Filter_1_SetCoherencyEx(Filter_1_STAGEB_COHER, Filter_1_KEY_MID);
    Filter_1_SetCoherencyEx(Filter_1_HOLDA_COHER, Filter_1_KEY_HIGH);
    Filter_1_SetCoherencyEx(Filter_1_HOLDB_COHER, Filter_1_KEY_HIGH);

    Filter_1_SetDalign(Filter_1_STAGEA_DALIGN, Filter_1_ENABLED);
    Filter_1_SetDalign(Filter_1_STAGEB_DALIGN, Filter_1_ENABLED);

    /* Enable Filter Interrupt */
    isr_filter_StartEx(Filter_Handler);    

    /* Start ADC (ensure the origin of events should be started last) */
    ADC_SAR_1_Start();
    ADC_SAR_2_Start();
    
    /* Initialize AGC Control */
    //agc_tim = AGC_TIM_INI;
    //agc_max = 0;
    //agc_mag = 0;
    
    /* Main Loop */
    while(1)
    {
        /*****************************
        *  Radio Data Processing
        ******************************/

        /* Get Bandpass Result from Queue and Generate Audio Output */
        if ((uxQueueMessagesWaiting(xQueue_IQ[0]) > 0) && (uxQueueMessagesWaiting(xQueue_IQ[1]) > 0))
        {
#if 1
            MON_1_Write(1u);        // debug
            xQueueReceive(xQueue_IQ[0], &filter_I, 0);        
            xQueueReceive(xQueue_IQ[1], &filter_Q, 0);
            
            //filter_I = abs(filter_I);
            //filter_Q = abs(filter_Q);
            //if (filter_I < 0)
            //    filter_I = -filter_I;
            //if (filter_Q < 0)
            //    filter_Q = -filter_Q;
            /* Calculation of Amplitude */
            //CORDIC(filter_I, filter_Q, &radius);
            radius = sqrt((filter_I ^2) + (filter_Q ^2));
            //radius = filter_I;
            /* Audio Output */
            //dac = (uint8) radius;
            VDAC8_1_SetValue((uint16)((radius >> 1) + V_OFFSET));
            VDAC8_2_SetValue((uint16)((radius >> 1) + V_OFFSET));
            MON_1_Write(0u);        // debug
#else            
            MON_1_Write(1u);        // debug
            xQueueReceive(xQueue_IQ[0], &filter_I, 0);        
            xQueueReceive(xQueue_IQ[1], &filter_Q, 0);

            VDAC8_1_SetValue((uint8)filter_I);
            VDAC8_2_SetValue((uint8)filter_Q);
            MON_1_Write(0u);        // debug
#endif
        }
    }
}

