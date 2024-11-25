/*******************************************************************************
* File Name: MON_OUT.h  
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

#if !defined(CY_PINS_MON_OUT_H) /* Pins MON_OUT_H */
#define CY_PINS_MON_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MON_OUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MON_OUT__PORT == 15 && ((MON_OUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MON_OUT_Write(uint8 value) ;
void    MON_OUT_SetDriveMode(uint8 mode) ;
uint8   MON_OUT_ReadDataReg(void) ;
uint8   MON_OUT_Read(void) ;
uint8   MON_OUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MON_OUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MON_OUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MON_OUT_DM_RES_UP          PIN_DM_RES_UP
#define MON_OUT_DM_RES_DWN         PIN_DM_RES_DWN
#define MON_OUT_DM_OD_LO           PIN_DM_OD_LO
#define MON_OUT_DM_OD_HI           PIN_DM_OD_HI
#define MON_OUT_DM_STRONG          PIN_DM_STRONG
#define MON_OUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MON_OUT_MASK               MON_OUT__MASK
#define MON_OUT_SHIFT              MON_OUT__SHIFT
#define MON_OUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MON_OUT_PS                     (* (reg8 *) MON_OUT__PS)
/* Data Register */
#define MON_OUT_DR                     (* (reg8 *) MON_OUT__DR)
/* Port Number */
#define MON_OUT_PRT_NUM                (* (reg8 *) MON_OUT__PRT) 
/* Connect to Analog Globals */                                                  
#define MON_OUT_AG                     (* (reg8 *) MON_OUT__AG)                       
/* Analog MUX bux enable */
#define MON_OUT_AMUX                   (* (reg8 *) MON_OUT__AMUX) 
/* Bidirectional Enable */                                                        
#define MON_OUT_BIE                    (* (reg8 *) MON_OUT__BIE)
/* Bit-mask for Aliased Register Access */
#define MON_OUT_BIT_MASK               (* (reg8 *) MON_OUT__BIT_MASK)
/* Bypass Enable */
#define MON_OUT_BYP                    (* (reg8 *) MON_OUT__BYP)
/* Port wide control signals */                                                   
#define MON_OUT_CTL                    (* (reg8 *) MON_OUT__CTL)
/* Drive Modes */
#define MON_OUT_DM0                    (* (reg8 *) MON_OUT__DM0) 
#define MON_OUT_DM1                    (* (reg8 *) MON_OUT__DM1)
#define MON_OUT_DM2                    (* (reg8 *) MON_OUT__DM2) 
/* Input Buffer Disable Override */
#define MON_OUT_INP_DIS                (* (reg8 *) MON_OUT__INP_DIS)
/* LCD Common or Segment Drive */
#define MON_OUT_LCD_COM_SEG            (* (reg8 *) MON_OUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define MON_OUT_LCD_EN                 (* (reg8 *) MON_OUT__LCD_EN)
/* Slew Rate Control */
#define MON_OUT_SLW                    (* (reg8 *) MON_OUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MON_OUT_PRTDSI__CAPS_SEL       (* (reg8 *) MON_OUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MON_OUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MON_OUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MON_OUT_PRTDSI__OE_SEL0        (* (reg8 *) MON_OUT__PRTDSI__OE_SEL0) 
#define MON_OUT_PRTDSI__OE_SEL1        (* (reg8 *) MON_OUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MON_OUT_PRTDSI__OUT_SEL0       (* (reg8 *) MON_OUT__PRTDSI__OUT_SEL0) 
#define MON_OUT_PRTDSI__OUT_SEL1       (* (reg8 *) MON_OUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MON_OUT_PRTDSI__SYNC_OUT       (* (reg8 *) MON_OUT__PRTDSI__SYNC_OUT) 


#if defined(MON_OUT__INTSTAT)  /* Interrupt Registers */

    #define MON_OUT_INTSTAT                (* (reg8 *) MON_OUT__INTSTAT)
    #define MON_OUT_SNAP                   (* (reg8 *) MON_OUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MON_OUT_H */


/* [] END OF FILE */
