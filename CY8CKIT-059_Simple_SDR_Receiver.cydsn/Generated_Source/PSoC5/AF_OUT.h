/*******************************************************************************
* File Name: AF_OUT.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_AF_OUT_H) /* Pins AF_OUT_H */
#define CY_PINS_AF_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AF_OUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AF_OUT__PORT == 15 && ((AF_OUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    AF_OUT_Write(uint8 value) ;
void    AF_OUT_SetDriveMode(uint8 mode) ;
uint8   AF_OUT_ReadDataReg(void) ;
uint8   AF_OUT_Read(void) ;
uint8   AF_OUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AF_OUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define AF_OUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define AF_OUT_DM_RES_UP          PIN_DM_RES_UP
#define AF_OUT_DM_RES_DWN         PIN_DM_RES_DWN
#define AF_OUT_DM_OD_LO           PIN_DM_OD_LO
#define AF_OUT_DM_OD_HI           PIN_DM_OD_HI
#define AF_OUT_DM_STRONG          PIN_DM_STRONG
#define AF_OUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define AF_OUT_MASK               AF_OUT__MASK
#define AF_OUT_SHIFT              AF_OUT__SHIFT
#define AF_OUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AF_OUT_PS                     (* (reg8 *) AF_OUT__PS)
/* Data Register */
#define AF_OUT_DR                     (* (reg8 *) AF_OUT__DR)
/* Port Number */
#define AF_OUT_PRT_NUM                (* (reg8 *) AF_OUT__PRT) 
/* Connect to Analog Globals */                                                  
#define AF_OUT_AG                     (* (reg8 *) AF_OUT__AG)                       
/* Analog MUX bux enable */
#define AF_OUT_AMUX                   (* (reg8 *) AF_OUT__AMUX) 
/* Bidirectional Enable */                                                        
#define AF_OUT_BIE                    (* (reg8 *) AF_OUT__BIE)
/* Bit-mask for Aliased Register Access */
#define AF_OUT_BIT_MASK               (* (reg8 *) AF_OUT__BIT_MASK)
/* Bypass Enable */
#define AF_OUT_BYP                    (* (reg8 *) AF_OUT__BYP)
/* Port wide control signals */                                                   
#define AF_OUT_CTL                    (* (reg8 *) AF_OUT__CTL)
/* Drive Modes */
#define AF_OUT_DM0                    (* (reg8 *) AF_OUT__DM0) 
#define AF_OUT_DM1                    (* (reg8 *) AF_OUT__DM1)
#define AF_OUT_DM2                    (* (reg8 *) AF_OUT__DM2) 
/* Input Buffer Disable Override */
#define AF_OUT_INP_DIS                (* (reg8 *) AF_OUT__INP_DIS)
/* LCD Common or Segment Drive */
#define AF_OUT_LCD_COM_SEG            (* (reg8 *) AF_OUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define AF_OUT_LCD_EN                 (* (reg8 *) AF_OUT__LCD_EN)
/* Slew Rate Control */
#define AF_OUT_SLW                    (* (reg8 *) AF_OUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AF_OUT_PRTDSI__CAPS_SEL       (* (reg8 *) AF_OUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AF_OUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AF_OUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AF_OUT_PRTDSI__OE_SEL0        (* (reg8 *) AF_OUT__PRTDSI__OE_SEL0) 
#define AF_OUT_PRTDSI__OE_SEL1        (* (reg8 *) AF_OUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AF_OUT_PRTDSI__OUT_SEL0       (* (reg8 *) AF_OUT__PRTDSI__OUT_SEL0) 
#define AF_OUT_PRTDSI__OUT_SEL1       (* (reg8 *) AF_OUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AF_OUT_PRTDSI__SYNC_OUT       (* (reg8 *) AF_OUT__PRTDSI__SYNC_OUT) 


#if defined(AF_OUT__INTSTAT)  /* Interrupt Registers */

    #define AF_OUT_INTSTAT                (* (reg8 *) AF_OUT__INTSTAT)
    #define AF_OUT_SNAP                   (* (reg8 *) AF_OUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AF_OUT_H */


/* [] END OF FILE */
