/*******************************************************************************
* File Name: ICHAN.c  
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
#include "ICHAN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ICHAN__PORT == 15 && ((ICHAN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ICHAN_Write
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
void ICHAN_Write(uint8 value) 
{
    uint8 staticBits = (ICHAN_DR & (uint8)(~ICHAN_MASK));
    ICHAN_DR = staticBits | ((uint8)(value << ICHAN_SHIFT) & ICHAN_MASK);
}


/*******************************************************************************
* Function Name: ICHAN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ICHAN_DM_STRONG     Strong Drive 
*  ICHAN_DM_OD_HI      Open Drain, Drives High 
*  ICHAN_DM_OD_LO      Open Drain, Drives Low 
*  ICHAN_DM_RES_UP     Resistive Pull Up 
*  ICHAN_DM_RES_DWN    Resistive Pull Down 
*  ICHAN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ICHAN_DM_DIG_HIZ    High Impedance Digital 
*  ICHAN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ICHAN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ICHAN_0, mode);
}


/*******************************************************************************
* Function Name: ICHAN_Read
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
*  Macro ICHAN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ICHAN_Read(void) 
{
    return (ICHAN_PS & ICHAN_MASK) >> ICHAN_SHIFT;
}


/*******************************************************************************
* Function Name: ICHAN_ReadDataReg
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
uint8 ICHAN_ReadDataReg(void) 
{
    return (ICHAN_DR & ICHAN_MASK) >> ICHAN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ICHAN_INTSTAT) 

    /*******************************************************************************
    * Function Name: ICHAN_ClearInterrupt
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
    uint8 ICHAN_ClearInterrupt(void) 
    {
        return (ICHAN_INTSTAT & ICHAN_MASK) >> ICHAN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
