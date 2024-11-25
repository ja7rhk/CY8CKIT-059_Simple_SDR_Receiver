/*******************************************************************************
* File Name: BLUELED.c  
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
#include "BLUELED.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BLUELED__PORT == 15 && ((BLUELED__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BLUELED_Write
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
void BLUELED_Write(uint8 value) 
{
    uint8 staticBits = (BLUELED_DR & (uint8)(~BLUELED_MASK));
    BLUELED_DR = staticBits | ((uint8)(value << BLUELED_SHIFT) & BLUELED_MASK);
}


/*******************************************************************************
* Function Name: BLUELED_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BLUELED_DM_STRONG     Strong Drive 
*  BLUELED_DM_OD_HI      Open Drain, Drives High 
*  BLUELED_DM_OD_LO      Open Drain, Drives Low 
*  BLUELED_DM_RES_UP     Resistive Pull Up 
*  BLUELED_DM_RES_DWN    Resistive Pull Down 
*  BLUELED_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BLUELED_DM_DIG_HIZ    High Impedance Digital 
*  BLUELED_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BLUELED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BLUELED_0, mode);
}


/*******************************************************************************
* Function Name: BLUELED_Read
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
*  Macro BLUELED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BLUELED_Read(void) 
{
    return (BLUELED_PS & BLUELED_MASK) >> BLUELED_SHIFT;
}


/*******************************************************************************
* Function Name: BLUELED_ReadDataReg
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
uint8 BLUELED_ReadDataReg(void) 
{
    return (BLUELED_DR & BLUELED_MASK) >> BLUELED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BLUELED_INTSTAT) 

    /*******************************************************************************
    * Function Name: BLUELED_ClearInterrupt
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
    uint8 BLUELED_ClearInterrupt(void) 
    {
        return (BLUELED_INTSTAT & BLUELED_MASK) >> BLUELED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
