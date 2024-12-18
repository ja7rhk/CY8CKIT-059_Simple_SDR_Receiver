/*******************************************************************************
* File Name: QOUT.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "QOUT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 QOUT__PORT == 15 && ((QOUT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: QOUT_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void QOUT_Write(uint8 value) 
{
    uint8 staticBits = (QOUT_DR & (uint8)(~QOUT_MASK));
    QOUT_DR = staticBits | ((uint8)(value << QOUT_SHIFT) & QOUT_MASK);
}


/*******************************************************************************
* Function Name: QOUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  QOUT_DM_STRONG     Strong Drive 
*  QOUT_DM_OD_HI      Open Drain, Drives High 
*  QOUT_DM_OD_LO      Open Drain, Drives Low 
*  QOUT_DM_RES_UP     Resistive Pull Up 
*  QOUT_DM_RES_DWN    Resistive Pull Down 
*  QOUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  QOUT_DM_DIG_HIZ    High Impedance Digital 
*  QOUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void QOUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(QOUT_0, mode);
}


/*******************************************************************************
* Function Name: QOUT_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro QOUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 QOUT_Read(void) 
{
    return (QOUT_PS & QOUT_MASK) >> QOUT_SHIFT;
}


/*******************************************************************************
* Function Name: QOUT_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 QOUT_ReadDataReg(void) 
{
    return (QOUT_DR & QOUT_MASK) >> QOUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(QOUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: QOUT_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 QOUT_ClearInterrupt(void) 
    {
        return (QOUT_INTSTAT & QOUT_MASK) >> QOUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
