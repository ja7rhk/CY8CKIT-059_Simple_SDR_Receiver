/*******************************************************************************
* File Name: MON_OUT.c  
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
#include "MON_OUT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MON_OUT__PORT == 15 && ((MON_OUT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MON_OUT_Write
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
void MON_OUT_Write(uint8 value) 
{
    uint8 staticBits = (MON_OUT_DR & (uint8)(~MON_OUT_MASK));
    MON_OUT_DR = staticBits | ((uint8)(value << MON_OUT_SHIFT) & MON_OUT_MASK);
}


/*******************************************************************************
* Function Name: MON_OUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MON_OUT_DM_STRONG     Strong Drive 
*  MON_OUT_DM_OD_HI      Open Drain, Drives High 
*  MON_OUT_DM_OD_LO      Open Drain, Drives Low 
*  MON_OUT_DM_RES_UP     Resistive Pull Up 
*  MON_OUT_DM_RES_DWN    Resistive Pull Down 
*  MON_OUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MON_OUT_DM_DIG_HIZ    High Impedance Digital 
*  MON_OUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MON_OUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MON_OUT_0, mode);
}


/*******************************************************************************
* Function Name: MON_OUT_Read
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
*  Macro MON_OUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MON_OUT_Read(void) 
{
    return (MON_OUT_PS & MON_OUT_MASK) >> MON_OUT_SHIFT;
}


/*******************************************************************************
* Function Name: MON_OUT_ReadDataReg
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
uint8 MON_OUT_ReadDataReg(void) 
{
    return (MON_OUT_DR & MON_OUT_MASK) >> MON_OUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MON_OUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: MON_OUT_ClearInterrupt
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
    uint8 MON_OUT_ClearInterrupt(void) 
    {
        return (MON_OUT_INTSTAT & MON_OUT_MASK) >> MON_OUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
