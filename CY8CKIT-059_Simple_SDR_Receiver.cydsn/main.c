//----------------------------------------------------------------------------
//
//	SIMPLE SDR RECEIVER PSoC3 FIRMWARE for Hardware Rev -
//
//	Copyright 2011 Simple Circuits Inc.
//
//	06/03/2011	Original release.
//
//
//
//	ADC sample rate is 32068 sps total, or 16034 sps per channel
//
//----------------------------------------------------------------------------
//
// PSoC3 => PSoC5LP
// Inner PLL => SI5351 DPLL module
//  Sumio Koseki (JA7RHK)
//	09/23/2017
//
//----------------------------------------------------------------------------
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
// API
#include "key.h"
#include "USBUART_FIFO.h"
// SI5351 DPLL
#include "si5351.h"


//----------------------------------------------------------------------------
//
//	Constants
//
//----------------------------------------------------------------------------
// PSoC3 => PSoC5LP
#define	FREQ_START			"00891000"			// in ASCII BCD chars
#define	FREQ_PLL_TEST		"00457000"			// pll lock test frequency
#define	FREQ_LOW			20000               // 20kHz
#define	FREQ_HIGH		    30000000            // 30MHz
#define USBUART_TIMEOUT 2000000                 // Timeout for USB Connection (adjustment might be required)
// SI5351 DPLL
#define SI5351_I2C_ADDR 0x060

const uint8 HEX2ASCII [] = {"0123456789ABCDEF"};
extern const uint8 CYCODE Filter_data_b_2500[];	// FIR coefficients
extern const uint8 CYCODE Filter_data_b_2000[];	// FIR coefficients
extern const uint8 CYCODE Filter_data_b_1500[];	// FIR coefficients
extern const uint8 CYCODE Filter_data_b_cw[];	// FIR coefficients
extern const uint8 CYCODE Filter_data_b_am[];	// FIR coefficients
extern const int32 CYCODE Hilbert [];			// Hilbert tranformer coefficients

// PSoC3 => PSoC5LP
#define PARAM_MAX  8
reg8 *pFREQ_ERROR = (reg8*)(CYDEV_EE_BASE + 16 * FQ_ROW);
reg8 *pSERIAL_NUM = (reg8*)(CYDEV_EE_BASE + 16 * SN_ROW);
uint8 FREQ_ERROR[PARAM_MAX];    // freq offset is 1st row of eeprom
uint8 SERIAL_NUM[PARAM_MAX];    // serial number is 2nd row of eeprom

// PSoC3 => PSoC5LP
volatile uint32 gUSBUART_Ready;

//----------------------------------------------------------------------------
//
// Channel Selecton
//
//----------------------------------------------------------------------------
#define STATION_MAX 5
#define BFO         800     // CW BFO = 800Hz
typedef struct
{
    char    Name[5];
    uint32  Freq;
    uint32  Offset;
    uint32  Step;
    uint8   Mode;
    uint8   Filter;
} Station;

Station station[STATION_MAX] = 
{
    {"NHK1 ", 891000, 0, 1, MODE_USB, FILTER_AM },
    {"NHK2 ", 1089000, 0, 1, MODE_USB, FILTER_AM },
    {"TBC  ", 1260000, 0, 1, MODE_USB, FILTER_AM },
    {"BCON ", 456200, 0, 1, MODE_USB, FILTER_FL3 },       // CW BFO = 800Hz
    {"10MHz", 10000000, 0, 1, MODE_USB, FILTER_AM },        // Calibration @ 10MHz
};

//
//----------------------------------------------------------------------------
//
//	Global variables
//
//----------------------------------------------------------------------------
uint8	Freq [8];					// receive frequency in ASCII BCD
uint8	LastFreq [8];				// copy of last tuned rx frequency
int32	Frequency;					// receive frequency in binary
int32	FrequencyError;				// frequency error at 10 MHz

uint8	ComRxCmd [32];				// remote command rx buffer
uint8	ComRxPtr;					// pointer into com rx buffer
uint8	UsbTxBuffer [80];			// USB transmit buffer
uint8	UsbRxBuffer [256];			// USB receive buffer

uint8	AdcTick;					// ADC interrupt flag every 6.521 msec
int16	IDCOffset, QDCOffset;		// DC offset values for ADC input
int16	AdcPeak, AdcPeakAve;		// ADC input peak value, and its average
uint8	AgcDisable;					// Agc disable flag
uint8	AgcGain;					// AGC for ADC input
uint8	AgcTimer;					// AGC processing timer
uint8	AgcIntegrator;				// AGC integrator
uint32	AgcIndicator;				// AGC signal strength indicatior
uint8	AgcTimeConstant;			// AGC time constant

uint8	LedTimer;					// LED on timer
uint8	DisplayIndex;				// index for status display

uint8	Filter;						// audio filter bandwidth selection
uint8	Mode;						// operating mode
uint8	UpperSideBand;				// upper side band mode selection
uint8	AttenuatorOn;				// rx attenuator on/off flag
uint8	Squelch;					// squelch level, 0 - 250.
uint8	Debug;						// debug mode flag, turns off boundary checks
uint8   Ch;                         // channel number (2017.5.31)koseki

// ADC Interrupt Handler
uint8	AdcState;					// IQ channel processing flag
int16	IDelay [64];
uint8	IDelayPtr;

//----------------------------------------------------------------------------
//
//	Resources for FreeRTOS
//
//----------------------------------------------------------------------------
#define TASK_STACK_LED   128
#define TASK_STACK_KEY   128
#define TASK_STACK_CLCD  512
#define TASK_STACK_USBUART  512
#define TASK_STACK_RADIO    512

#define TASK_PRIORITY_LED   (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_KEY   (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_CLCD  (tskIDLE_PRIORITY + 2)
#define TASK_PRIORITY_USBUART   (tskIDLE_PRIORITY + 2)
#define TASK_PRIORITY_RADIO     (tskIDLE_PRIORITY + 2)

void Task_LED   (void *pvParameters);
void Task_KEY   (void *pvParameters);     // .\Utility\key.c
void Task_CLCD  (void *pvParameters);
void Task_USBUART   (void *pvParameters);
void Task_RADIO     (void *pvParameters);

xSemaphoreHandle xMutex_DPLL;    // Mutex for Parameter Control

xQueueHandle xQueue_KEY[2];     // Task_KEY -> Task_CLCD
xQueueHandle xQueue_FREQ;       // Task_USB -> Task_CLCD

// Function Prototypes
void prvHardwareSetup(void);
void CORDIC(int32 x, int32 y, int32 *radius);

//----------------------------------------------------------------------------
//
//	MAIN
//
//----------------------------------------------------------------------------
//void main()
int main()
{
    prvHardwareSetup();

	Initialize ();

    /* Create Tasks */
    xMutex_DPLL = xSemaphoreCreateMutex();
    xQueue_KEY[0] = xQueueCreate(1, 1);     // 1 x 1byte
    xQueue_KEY[1] = xQueueCreate(1, 1);     // 1 x 1byte
    xQueue_FREQ  = xQueueCreate(1, 1);      // 1 x 1bytes

    CyDelay(1000u);

    xTaskCreate(Task_LED, "LED", TASK_STACK_LED, NULL, TASK_PRIORITY_LED, NULL);
    xTaskCreate(Task_KEY, "KEY", TASK_STACK_KEY, NULL, TASK_PRIORITY_KEY, NULL);
    xTaskCreate(Task_CLCD, "CLCD", TASK_STACK_CLCD, NULL, TASK_PRIORITY_CLCD, NULL);
    xTaskCreate(Task_USBUART, "USBUART", TASK_STACK_USBUART, NULL, TASK_PRIORITY_USBUART, NULL);
    xTaskCreate(Task_RADIO, "RADIO", TASK_STACK_RADIO, NULL, TASK_PRIORITY_RADIO, NULL);

    /* Start RTOS Kernel */
    vTaskStartScheduler();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

//----------------------------------------------------------------------------
//
//	Initialize and configure hardware, initialize variables
//
//----------------------------------------------------------------------------
void Initialize (void)
{
    uint8 i;
   
	CyDelay (100);					// delay in msec
    
    // SI5351 DPLL control
    I2C_1_Start();
    si5351_init(SI5351_XTAL_FREQ, 0, SI5351_CRYSTAL_LOAD_10PF);
    si5351_clock_enable(SI5351_CLK0, 1);
    si5351_drive_strength(SI5351_CLK0, SI5351_DRIVE_4MA);

    // Start Input Comp
    //VDAC8_1_Start();
    //Comp_1_Start();
    
    CyDelay (1);					// delay in msec

	//CyPins_SetPin (TP2_OUT_0);
	//CyPins_SetPin (REDLED_0);		// red led off
    
	Filter_Start ();				// start FIR filter
	VDAC_Start ();					// start DAC output

    // Debug for USBUART
#if 1
	ADC_Start ();					// power up and start 16 bit ADC
	ADC_IRQ_Enable ();
    isr_adc_StartEx(ADC_ISR_Handler);
	ADC_StartConvert ();			// start conversions
#endif    
	CyDelay (100);					// delay in msec

	// initialize vars
	Filter = FILTER_FL2;			// selects 2000 Hz LPF
	SetMode (MODE_USB);
	IDCOffset = QDCOffset = 0x500;	// preset offset for better settling time
    AgcTimeConstant = 4;            // Default AGC Time constant

	EEPROM_Start ();				// power up eeprom

	CyDelay (100);					// delay in msec
    
    // PSoC3 => PSoC5LP
    for (i = 0; i < PARAM_MAX; i++)
        SERIAL_NUM[i] = pSERIAL_NUM[i];

    if (SERIAL_NUM [0] != '0')
	{
		CySetTemp ();				// acquire die temperature before writing eeprom
		EEPROM_Write ((uint8*)"00000000", SN_ROW);	// write and wait for completion
        // AD9850_DDS
		EEPROM_Write ((uint8*)"10000000", FQ_ROW);	// write and wait for completion
	}

	FrequencyError = 0;
	//memcpy (Freq, FREQ_PLL_TEST, 8);// initialize the clock generator output frequency
	//SetFrequency ();

	CyDelay (200);					// delay in msec
	CYGlobalIntEnable;
	
    // PSoC3 => PSoC5LP
    for (i = 0; i < PARAM_MAX; i++)
        FREQ_ERROR[i] = pFREQ_ERROR[i];
        
    // SI5351 DPLL
    FrequencyError = 10000000 - BinaryFrequency (FREQ_ERROR);	// compute binary value from string
    if ((FrequencyError > 1000) || (FrequencyError < -1000))	// bounds checking
		FrequencyError = 0;
	memcpy (Freq, FREQ_START, 8);			// initialize the clock generator output frequency
	SetFrequency ();
}

//----------------------------------------------------------------------------
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
//----------------------------------------------------------------------------

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	/* The stack space has been execeeded for a task, considering allocating more. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
//----------------------------------------------------------------------------

void vApplicationMallocFailedHook( void )
{
	/* The heap space has been execeeded. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
//----------------------------------------------------------------------------

//
// SI5351 DPLL control functions
//
static void si5351_start_xfer(uint8_t reg)
{
    (void) I2C_1_MasterSendStart(SI5351_I2C_ADDR, I2C_1_WRITE_XFER_MODE);
    (void) I2C_1_MasterWriteByte(reg); /* write register address */
}

void si5351_write_xfer(uint8_t reg, uint8_t *data, int count)
{
    /* if data is NULL, write 0x00 instead */
#if 1
    si5351_start_xfer(reg);
    while (count-- > 0)
        (void) I2C_1_MasterWriteByte(data ? *data++ : 0x00);
    I2C_1_MasterSendStop();
#else
    while (count-- > 0) {
        si5351_start_xfer(reg++);
        (void) I2C_1_MasterWriteByte(data ? *data++ : 0x00);
        I2C_1_MasterSendStop();
    }
#endif
}

void si5351_read_xfer(uint8_t reg, uint8_t *data, int count)
{
    si5351_start_xfer(reg);
    I2C_1_MasterSendStop();
    (void) I2C_1_MasterSendStart(SI5351_I2C_ADDR, I2C_1_READ_XFER_MODE);
    
    while (count > 1) {
        *data++ = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
        count--;
    }
    
    if (count == 1) {
        *data++ = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
    }
    I2C_1_MasterSendStop();
}

void si5351_write_byte(uint8_t reg, uint8_t val)
{
    si5351_write_xfer(reg, &val, 1);
}

uint8_t si5351_read_byte(uint8_t reg)
{
    uint8_t data;
    
    si5351_read_xfer(reg, &data, 1);
    return (data);
}
//----------------------------------------------------------------------------


//============================================================================
//
//	Task_LED
//
//============================================================================
void Task_LED(void *pvParameters)
{
    /* Block time in (ms) */
    const portTickType OnDelay = 1000 / portTICK_RATE_MS;
    const portTickType OffDelay = 1000 / portTICK_RATE_MS;

    while(1)
    {
        LED_Write(1u);
        vTaskDelay(OnDelay);
        
        LED_Write(0u);
        vTaskDelay(OffDelay);
    }
}


//============================================================================
//
//	Task_CLCD
//
//============================================================================
void Task_CLCD(void *pvParameters)
{
    uint8  qmsg;
    const portTickType xDelay = 100 / portTICK_RATE_MS;

    // Default channel set
    Ch = 0;
    ChannelSet(Ch);
    
    // Main Loop
 	while (1)
	{
        xSemaphoreTake(xMutex_DPLL, portMAX_DELAY);
        
        if (xQueueReceive(xQueue_KEY[0], &qmsg, 0))
        {
            Ch++;
            if (Ch >= STATION_MAX)
                Ch = 0;
            ChannelSet(Ch);
        }
        if (xQueueReceive(xQueue_KEY[1], &qmsg, 0))
        {
            if (Ch == 0)
                Ch = STATION_MAX - 1;
            else
                Ch--;
            ChannelSet(Ch);
        }
        xSemaphoreGive(xMutex_DPLL);

        vTaskDelay(xDelay);
    }
}

//
//	Update the selected channel
//
void ChannelSet(uint8 ch)
{
    // setup the new station
    sprintf((char*)Freq, "%08ld", station[ch].Freq);
    SetFrequency();
    Mode = station[ch].Mode;
	SetMode(Mode);
    Filter = station[ch].Filter;
    LoadFilter(Filter);
    AgcIndicator = 0;   // reset signal strength indicatior
}

//
//	Load DFB filter data into coefficient RAM
//
void LoadFilter (uint8 fltr)
{
	uint8 i, j;
	int32 x;
	uint8 xbuf [256];

	// Put DFB RAM on the bus
    Filter_RAM_DIR_REG = Filter_RAM_DIR_BUS;

	if (fltr == FILTER_FL1)
        cymemcpy(Filter_DB_RAM, Filter_data_b_2500, Filter_DB_RAM_SIZE);
	else if (fltr == FILTER_FL2)
        cymemcpy(Filter_DB_RAM, Filter_data_b_2000, Filter_DB_RAM_SIZE);
	else if (fltr == FILTER_FL3)
        cymemcpy(Filter_DB_RAM, Filter_data_b_1500, Filter_DB_RAM_SIZE);
	else if (fltr == FILTER_FL4)
        cymemcpy(Filter_DB_RAM, Filter_data_b_cw, Filter_DB_RAM_SIZE);
	else if (fltr == FILTER_AM)
        cymemcpy(Filter_DB_RAM, Filter_data_b_am, Filter_DB_RAM_SIZE);
	else if (fltr == FILTER_RST)
        cymemcpy(Filter_DB_RAM, Filter_data_b, Filter_DB_RAM_SIZE);

    // copy Hilbert filter coefficients into filter channel B ram
	j = 0;
	for (i = 0; i < 64; i++) 
	{
		x = Hilbert [i];
		xbuf [j++] = x & 0xFF;
		xbuf [j++] = (x >> 8) & 0xFF;
		xbuf [j++] = (x >> 16) & 0xFF;
		xbuf [j++] = 0;
	}
	cymemcpy(Filter_DB_RAM + 256, xbuf, Filter_DB_RAM_SIZE / 2);
		
	// Take DFB RAM off the bus
	Filter_RAM_DIR_REG = Filter_RAM_DIR_DFB;
}

//
//	Frequency synthesizer set frequency
//	Freq (MHz)  = (24/9) * (N + Frac/16384) / (4 * IQDividerRatio)
//				= 2 * (N + Frac/16384) / (3 * IQDividerRatio)
//
void SetFrequency (void)
{
	//uint8 pllN, iqDivider, fracLo, fracHi;
	double frq;
    // SI5351 DPLL
	uint32 newfreq;
	
	if (!memcmp (Freq, LastFreq, 8))	// check if already tuned to that frequency
		return;							// ignore set frequency command and return

	frq = BinaryFrequency (Freq);		// compute binary value from string

	if ((!Debug) && ((frq < FREQ_LOW) || (frq > FREQ_HIGH))) // ignore frequencies outside tuning range
	{
		memcpy (Freq, LastFreq, 8);	// restore last frequency allowed
		return;
	}
	memcpy (LastFreq, Freq, 8);
	Frequency = (int32)frq;				// save new receive frequency (binary form)
    
    // PSoC3 PLL => SI5351 DPLL control

    // offset by frequency error (factory adjusted)
	frq -= frq * FrequencyError / 10000000;

    // DDS frequency is quadruple of Rx frequency 
    newfreq = (uint32)frq * 4;
    
    //pll_freq = si5351_set_frequency(155000000, 0, SI5351_CLK0, 1);
    si5351_set_frequency(newfreq, 0, SI5351_CLK0, 1);

#if 1    
    if ((frq < 40000000) && (frq > 0))
    {
        // mute the input signal during frequency changes
    	AgcGain = 0;
    }
#endif
    CyDelay (1);
}

//
//	Set operating mode
//
void SetMode (uint8 md)
{
	Mode = md;					// save operating mode
    
	UpperSideBand = ((Mode == MODE_USB) || (Mode == MODE_CW) || (Mode == MODE_RTTY));
		
	if ((Mode == MODE_CW) || (Mode == MODE_CWREV))
		Filter = FILTER_FL3;
	//else if ((Mode <= MODE_USB) && (Filter == FILTER_FL4))
	else if ((Mode == MODE_USB) || (Mode == MODE_LSB))
		Filter = FILTER_FL2;
    else
        Filter = FILTER_AM;
    // (2017.6.1)koseki
	//LoadFilter (Filter);
}

//
//	Compute binary frequency value from ASCII character string
//
uint32 BinaryFrequency (uint8 *ptr)
{
	uint8 i;
	uint32 frq, dec;
	
	frq = 0;
	dec = 10000000;					// 10's of MHz
	for (i = 0; i < 8; i++)
	{
		frq += (*ptr++ - '0') * dec;
		dec /= 10;
	}
	return (frq);
}

			
//============================================================================
//
//	Task_USBUART
//
//============================================================================
//
// ISR of int_uartQueue(2kHz clock) interrupt.
//
CY_ISR(int_uartQueue_isr)
{
    uartTxIsr();
    uartRxIsr();
}

void Task_USBUART(void *pvParameters)
{
    USBUART_Start(0, USBUART_DWR_VDDD_OPERATION);
    // start 2kHz timer interrupt
    int_uartQueue_StartEx(int_uartQueue_isr);

    // Main Loop
 	while (1)
	{
        // Wait until the intialization is done.
        while (USBUART_GetConfiguration() == 0);

        USBUART_IsConfigurationChanged();       // Clear CHANGE flag
        USBUART_CDC_Init();                     // Start CDC function
        for (;;)
        {
            // If the confoguration is changed, then initialize USB again.
            if (USBUART_IsConfigurationChanged())
                break;

            // Read USB port for COM data
    		ReadUSB();
            
            // Ignore the control comands
            (void)USBUART_IsLineChanged();
        }
    }
}

//
//	Read USB port for COM data
//
void ReadUSB (void)
{
#if PSoC3            
	uint8 bCount, rx, i;

    bCount = USBUART_bGetRxCount();		// get the USB Rx data size
	if( bCount )
	{
		USBUART_ReadAll(UsbRxBuffer);	// read usb rx data

		for (i = 0; i < bCount; i++)
		{
			rx = UsbRxBuffer [i];
			ComRxCmd [ComRxPtr++] = rx;	// save in command buffer
			if (rx == ';')				// command string terminator
			{
				ProcessComRx ();
				ComRxPtr = 0;
			}
			else if ((rx == CR) && (ComRxCmd [0] == '$') && (ComRxCmd [1] == '*'))
			{
				FactorySetup ();
				ComRxPtr = 0;
			}
			else
				ComRxPtr &= sizeof(ComRxCmd) - 1;
		}
	}
#else // PSoC5LP
	uint8 rx;

    rx = getch();
    //if (rx >= 0)      // always true!!
    if (rx < 0x80)
    {
        ComRxCmd[ComRxPtr++] = rx;	// save in command buffer
		if (rx == ';')				// command string terminator
		{
            xSemaphoreTake(xMutex_DPLL, portMAX_DELAY);
			ProcessComRx();
            xSemaphoreGive(xMutex_DPLL);
			ComRxPtr = 0;
        }
        else if (rx == '\n' && (ComRxCmd[0] == '$') && (ComRxCmd[1] == '*'))
        {
            xSemaphoreTake(xMutex_DPLL, portMAX_DELAY);
			FactorySetup();
            xSemaphoreGive(xMutex_DPLL);
			ComRxPtr = 0;
        }
		else
			ComRxPtr &= sizeof(ComRxCmd) - 1;
	}
#endif
}

//
//	Factory setup commands
//
void FactorySetup (void)
{
	uint8 sendUsb = FALSE;
    uint8 i;
	
	switch (ComRxCmd [2])
	{
		//case 'b':						// bootloader mode
		//	CyBtldr_Load();				// enter USB boot loader mode
		//	break;
			
		case 'c':						// calibrate frequency mode
			memcpy (LastFreq, "12345678", 8);	// force frequency change
            // SI5351 DPLL
    		memcpy (Freq, "10000000", 8);		// set frequency to 10MHz
			FrequencyError = 0;
			SetFrequency ();
			memcpy (UsbTxBuffer, "Calibrate", 9);
			sendUsb = 9;
			break;
			
		case 'd':						// debug mode
			Debug = TRUE;
			memcpy (UsbTxBuffer, "Debug Mode", 10);
			sendUsb = 10;
			break;
			
		case 'n':						// store serial number in eeprom
			CySetTemp ();				// acquire die temperature before writing eeprom
			if (EEPROM_Write (&ComRxCmd [3], SN_ROW) == CYRET_SUCCESS)
				LedTimer = LED_BLINK;	// if successful write, blink the LED
			break;
			
		case 'f':						// store frequency offset in eeprom
			CySetTemp ();				// acquire die temperature before writing eeprom
			if (EEPROM_Write (&ComRxCmd [3], FQ_ROW) == CYRET_SUCCESS)
			{
				LedTimer = LED_BLINK;	// if successful write, blink the LED
				memcpy (LastFreq, "12345678", 8);	// force frequency change
				memcpy (Freq, "10000000", 8);		// set frequency to 10MHz
                // PSoC3 => PSoC5LP
                for (i = 0; i < PARAM_MAX; i++)
                    FREQ_ERROR[i] = pFREQ_ERROR[i];
                // SI5351 DPLL
				FrequencyError = 10000000 - BinaryFrequency (FREQ_ERROR);	// compute binary value from string
				SetFrequency ();
			}
//			break;

		case '?':						// status command, reply with eeprom data
            // PSoC3 => PSoC5LP
			//memcpy (UsbTxBuffer, SERIAL_NUM, 8);		// serial number
            for (i = 0; i < PARAM_MAX; i++)
                UsbTxBuffer[i] = pSERIAL_NUM[i];
			UsbTxBuffer [8] = ' ';
			//memcpy (&UsbTxBuffer [9], FREQ_ERROR, 8);	// frequency offset at 10MHz
            for (i = 0; i < PARAM_MAX; i++)
                UsbTxBuffer[9 + i] = pFREQ_ERROR[i];
			sendUsb = 17;
			break;
	}

	if (sendUsb)
	{
#ifdef PSoC3 // original code
		USBUART_Write(UsbTxBuffer, sendUsb);	// send response
#else
        UsbTxBuffer [sendUsb] = '\0';   // 2017.11.4(koseki)
        putstr((char*)UsbTxBuffer);
        putch('\n');
#endif
	}
}



//============================================================================
//
//	Task_RADIO
//
//============================================================================
void Task_RADIO(void *pvParameters)
{
    const portTickType xDelay = 1 / portTICK_RATE_MS;

    // Main Loop
 	while (1)
	{
		AdjustAgc ();				// AGC adjustment		
        
        vTaskDelay(xDelay);
    }
}

//----------------------------------------------------------------------------
//
//	ADC interrupt processing
//
//	Interrupts every 31.18 usec, 32068 sps, 16034 sps per channel
//	TP2 is low for 8.5 to 11 usec (optimization 5), freq = 14.070 MHz = Fvco = 56.28 MHz
//----------------------------------------------------------------------------
CY_ISR(ADC_ISR_Handler)
{
	int16  rxRaw;		// must be signed int
	uint16 sample;		// less compiled code when using unsigned int
        
	//CyPins_ClearPin(TP2_OUT_0);

	if (AdcState & 1)			// I channel input processing
	{
		IQMUX_Control = 2;		// selects I channel of IQMUX, IQMUX_Write (2);
		
		// read ADC, subtract out DC offset, and multiply by gain
		rxRaw = ADC_GetResult16 () - IDCOffset;
		IDCOffset += (rxRaw & 0x8000) ? -1 : 1;	// calc new DC offset
		rxRaw = rxRaw * AgcGain;
        IDelay [IDelayPtr++] = rxRaw;			// store I channel in delay line
		IDelayPtr &= 31;
   		// Write Filter A output to PRS DAC
		VDAC_Data = Filter_HOLDAH_REG ^ 0x80;
    }
	else						// Q channel input processing
	{
		IQMUX_Control = 1;		// selects Q channel of IQMUX, IQMUX_Write (1);

		// read ADC, subtract out DC offset, and multiply by gain
		rxRaw = ADC_GetResult16 () - QDCOffset;
		QDCOffset += (rxRaw & 0x8000) ? -1 : 1;	// calc new DC offset before any gain adjust
		rxRaw = rxRaw * AgcGain;

        if (UpperSideBand)
			sample = IDelay [IDelayPtr] - Filter_Read16 (Filter_CHANNEL_B);
		else
			sample = IDelay [IDelayPtr] + Filter_Read16 (Filter_CHANNEL_B);

        // Filter_Write16 (Filter_CHANNEL_A, IDelay [IDelayPtr] +/- Filter_Read16 (Filter_CHANNEL_B));
		Filter_STAGEAM_REG = (uint8)(sample);
        Filter_STAGEAH_REG = (uint8)(sample >> 8);

		//  replace Filter_Write16 (Filter_CHANNEL_B, rxRaw);
        Filter_STAGEBM_REG = (uint8)(rxRaw);
        Filter_STAGEBH_REG = (uint8)(rxRaw >> 8);

        // AdcState == 0 ; 32086 / 256 = 125.33(Hz)= 7.98(ms)
		if (!AdcState)
			AdcTick = TRUE;
    }
	AdcState++;
	
	if (rxRaw > AdcPeak)
		AdcPeak = rxRaw;
	
	//CyPins_SetPin(TP2_OUT_0);		   

}

//
//	Adjust AGC by monitoring ADC peak signal level
//	Adjusts gain every 8 msec, rate of 32068 / 256 Hz
//
void AdjustAgc (void)
{
	uint16 atten;
	
	if (!AdcTick)					// 8 msec tick
		return;
	AdcTick = FALSE;
	
	if (LedTimer)
	{
		if (--LedTimer == 0)
			//CyPins_SetPin (REDLED_0);	// red led off
            BLUELED_Write(0u);
		else
			//CyPins_ClearPin (REDLED_0);	// red led on
            BLUELED_Write(1u);
	}	

	if (AgcDisable)
		AdcPeak = 0;				// disable AGC adjustments and go to max gain
	else if (AdcPeak > 0x3800)
	{
		AgcIntegrator = (AgcIntegrator >> 2) * 3;	// overloaded input, reduce gain to 75%
		AgcGain = 1 + (AgcIntegrator >> 2);	
		LedTimer = LED_SHORTBLINK;	// blink the LED for overload
	}
	AdcPeakAve = (AdcPeakAve + AdcPeak) / 2;		// compute average peak ADC value
	AdcPeak = 0;	
	
	if (--AgcTimer)
		return;
	//AgcTimer = 4;					// every 32 msec
	AgcTimer = AgcTimeConstant;		// controlled by GT command (AgcTimeConstant * 8 ms)
	
	atten = (AttenuatorOn) ? 0x1000 : 0x2800;
	if (AdcPeakAve < atten)			 // clips if higher than this number
	{
		if (AgcIntegrator != 0xFF)
			AgcIntegrator++;		// increase gain
	}
	else if (AgcIntegrator)
		AgcIntegrator--;			// decrease gain
		
	AgcGain = 1 + (AgcIntegrator >> 2);

}


// [] END OF FILE
