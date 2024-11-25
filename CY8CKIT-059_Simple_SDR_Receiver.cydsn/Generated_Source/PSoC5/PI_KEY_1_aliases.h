/*******************************************************************************
* File Name: PI_KEY_1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PI_KEY_1_ALIASES_H) /* Pins PI_KEY_1_ALIASES_H */
#define CY_PINS_PI_KEY_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define PI_KEY_1_0			(PI_KEY_1__0__PC)
#define PI_KEY_1_0_INTR	((uint16)((uint16)0x0001u << PI_KEY_1__0__SHIFT))

#define PI_KEY_1_INTR_ALL	 ((uint16)(PI_KEY_1_0_INTR))

#endif /* End Pins PI_KEY_1_ALIASES_H */


/* [] END OF FILE */
