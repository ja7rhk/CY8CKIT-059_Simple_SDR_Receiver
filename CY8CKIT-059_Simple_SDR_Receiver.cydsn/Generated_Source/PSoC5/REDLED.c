/*******************************************************************************
* File Name: REDLED.c  
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
#include "REDLED.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 REDLED__PORT == 15 && ((REDLED__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: REDLED_Write
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
void REDLED_Write(uint8 value) 
{
    uint8 staticBits = (REDLED_DR & (uint8)(~REDLED_MASK));
    REDLED_DR = staticBits | ((uint8)(value << REDLED_SHIFT) & REDLED_MASK);
}


/*******************************************************************************
* Function Name: REDLED_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  REDLED_DM_STRONG     Strong Drive 
*  REDLED_DM_OD_HI      Open Drain, Drives High 
*  REDLED_DM_OD_LO      Open Drain, Drives Low 
*  REDLED_DM_RES_UP     Resistive Pull Up 
*  REDLED_DM_RES_DWN    Resistive Pull Down 
*  REDLED_DM_RES_UPDWN  Resistive Pull Up/Down 
*  REDLED_DM_DIG_HIZ    High Impedance Digital 
*  REDLED_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void REDLED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(REDLED_0, mode);
}


/*******************************************************************************
* Function Name: REDLED_Read
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
*  Macro REDLED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 REDLED_Read(void) 
{
    return (REDLED_PS & REDLED_MASK) >> REDLED_SHIFT;
}


/*******************************************************************************
* Function Name: REDLED_ReadDataReg
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
uint8 REDLED_ReadDataReg(void) 
{
    return (REDLED_DR & REDLED_MASK) >> REDLED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(REDLED_INTSTAT) 

    /*******************************************************************************
    * Function Name: REDLED_ClearInterrupt
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
    uint8 REDLED_ClearInterrupt(void) 
    {
        return (REDLED_INTSTAT & REDLED_MASK) >> REDLED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
