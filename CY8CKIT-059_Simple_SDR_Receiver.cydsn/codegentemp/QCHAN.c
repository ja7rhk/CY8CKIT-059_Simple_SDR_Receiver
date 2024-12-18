/*******************************************************************************
* File Name: QCHAN.c  
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
#include "QCHAN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 QCHAN__PORT == 15 && ((QCHAN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: QCHAN_Write
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
void QCHAN_Write(uint8 value) 
{
    uint8 staticBits = (QCHAN_DR & (uint8)(~QCHAN_MASK));
    QCHAN_DR = staticBits | ((uint8)(value << QCHAN_SHIFT) & QCHAN_MASK);
}


/*******************************************************************************
* Function Name: QCHAN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  QCHAN_DM_STRONG     Strong Drive 
*  QCHAN_DM_OD_HI      Open Drain, Drives High 
*  QCHAN_DM_OD_LO      Open Drain, Drives Low 
*  QCHAN_DM_RES_UP     Resistive Pull Up 
*  QCHAN_DM_RES_DWN    Resistive Pull Down 
*  QCHAN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  QCHAN_DM_DIG_HIZ    High Impedance Digital 
*  QCHAN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void QCHAN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(QCHAN_0, mode);
}


/*******************************************************************************
* Function Name: QCHAN_Read
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
*  Macro QCHAN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 QCHAN_Read(void) 
{
    return (QCHAN_PS & QCHAN_MASK) >> QCHAN_SHIFT;
}


/*******************************************************************************
* Function Name: QCHAN_ReadDataReg
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
uint8 QCHAN_ReadDataReg(void) 
{
    return (QCHAN_DR & QCHAN_MASK) >> QCHAN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(QCHAN_INTSTAT) 

    /*******************************************************************************
    * Function Name: QCHAN_ClearInterrupt
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
    uint8 QCHAN_ClearInterrupt(void) 
    {
        return (QCHAN_INTSTAT & QCHAN_MASK) >> QCHAN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
