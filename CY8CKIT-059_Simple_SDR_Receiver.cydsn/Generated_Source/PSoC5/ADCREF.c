/*******************************************************************************
* File Name: ADCREF.c  
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
#include "ADCREF.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADCREF__PORT == 15 && ((ADCREF__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADCREF_Write
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
void ADCREF_Write(uint8 value) 
{
    uint8 staticBits = (ADCREF_DR & (uint8)(~ADCREF_MASK));
    ADCREF_DR = staticBits | ((uint8)(value << ADCREF_SHIFT) & ADCREF_MASK);
}


/*******************************************************************************
* Function Name: ADCREF_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ADCREF_DM_STRONG     Strong Drive 
*  ADCREF_DM_OD_HI      Open Drain, Drives High 
*  ADCREF_DM_OD_LO      Open Drain, Drives Low 
*  ADCREF_DM_RES_UP     Resistive Pull Up 
*  ADCREF_DM_RES_DWN    Resistive Pull Down 
*  ADCREF_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ADCREF_DM_DIG_HIZ    High Impedance Digital 
*  ADCREF_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ADCREF_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADCREF_0, mode);
}


/*******************************************************************************
* Function Name: ADCREF_Read
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
*  Macro ADCREF_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADCREF_Read(void) 
{
    return (ADCREF_PS & ADCREF_MASK) >> ADCREF_SHIFT;
}


/*******************************************************************************
* Function Name: ADCREF_ReadDataReg
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
uint8 ADCREF_ReadDataReg(void) 
{
    return (ADCREF_DR & ADCREF_MASK) >> ADCREF_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADCREF_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADCREF_ClearInterrupt
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
    uint8 ADCREF_ClearInterrupt(void) 
    {
        return (ADCREF_INTSTAT & ADCREF_MASK) >> ADCREF_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
