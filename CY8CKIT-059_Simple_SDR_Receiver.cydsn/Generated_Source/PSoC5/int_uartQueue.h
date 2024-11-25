/*******************************************************************************
* File Name: int_uartQueue.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_int_uartQueue_H)
#define CY_ISR_int_uartQueue_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void int_uartQueue_Start(void);
void int_uartQueue_StartEx(cyisraddress address);
void int_uartQueue_Stop(void);

CY_ISR_PROTO(int_uartQueue_Interrupt);

void int_uartQueue_SetVector(cyisraddress address);
cyisraddress int_uartQueue_GetVector(void);

void int_uartQueue_SetPriority(uint8 priority);
uint8 int_uartQueue_GetPriority(void);

void int_uartQueue_Enable(void);
uint8 int_uartQueue_GetState(void);
void int_uartQueue_Disable(void);

void int_uartQueue_SetPending(void);
void int_uartQueue_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the int_uartQueue ISR. */
#define int_uartQueue_INTC_VECTOR            ((reg32 *) int_uartQueue__INTC_VECT)

/* Address of the int_uartQueue ISR priority. */
#define int_uartQueue_INTC_PRIOR             ((reg8 *) int_uartQueue__INTC_PRIOR_REG)

/* Priority of the int_uartQueue interrupt. */
#define int_uartQueue_INTC_PRIOR_NUMBER      int_uartQueue__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable int_uartQueue interrupt. */
#define int_uartQueue_INTC_SET_EN            ((reg32 *) int_uartQueue__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the int_uartQueue interrupt. */
#define int_uartQueue_INTC_CLR_EN            ((reg32 *) int_uartQueue__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the int_uartQueue interrupt state to pending. */
#define int_uartQueue_INTC_SET_PD            ((reg32 *) int_uartQueue__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the int_uartQueue interrupt. */
#define int_uartQueue_INTC_CLR_PD            ((reg32 *) int_uartQueue__INTC_CLR_PD_REG)


#endif /* CY_ISR_int_uartQueue_H */


/* [] END OF FILE */
