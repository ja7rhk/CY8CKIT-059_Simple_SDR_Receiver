/*******************************************************************************
* File Name: IQMUX_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "IQMUX.h"

/* Check for removal by optimization */
#if !defined(IQMUX_Sync_ctrl_reg__REMOVED)

static IQMUX_BACKUP_STRUCT  IQMUX_backup = {0u};

    
/*******************************************************************************
* Function Name: IQMUX_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IQMUX_SaveConfig(void) 
{
    IQMUX_backup.controlState = IQMUX_Control;
}


/*******************************************************************************
* Function Name: IQMUX_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void IQMUX_RestoreConfig(void) 
{
     IQMUX_Control = IQMUX_backup.controlState;
}


/*******************************************************************************
* Function Name: IQMUX_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IQMUX_Sleep(void) 
{
    IQMUX_SaveConfig();
}


/*******************************************************************************
* Function Name: IQMUX_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IQMUX_Wakeup(void)  
{
    IQMUX_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
