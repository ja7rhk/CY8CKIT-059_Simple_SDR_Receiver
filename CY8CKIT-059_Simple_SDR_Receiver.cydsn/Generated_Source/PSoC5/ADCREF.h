/*******************************************************************************
* File Name: ADCREF.h  
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

#if !defined(CY_PINS_ADCREF_H) /* Pins ADCREF_H */
#define CY_PINS_ADCREF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADCREF_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADCREF__PORT == 15 && ((ADCREF__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADCREF_Write(uint8 value) ;
void    ADCREF_SetDriveMode(uint8 mode) ;
uint8   ADCREF_ReadDataReg(void) ;
uint8   ADCREF_Read(void) ;
uint8   ADCREF_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADCREF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADCREF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADCREF_DM_RES_UP          PIN_DM_RES_UP
#define ADCREF_DM_RES_DWN         PIN_DM_RES_DWN
#define ADCREF_DM_OD_LO           PIN_DM_OD_LO
#define ADCREF_DM_OD_HI           PIN_DM_OD_HI
#define ADCREF_DM_STRONG          PIN_DM_STRONG
#define ADCREF_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADCREF_MASK               ADCREF__MASK
#define ADCREF_SHIFT              ADCREF__SHIFT
#define ADCREF_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADCREF_PS                     (* (reg8 *) ADCREF__PS)
/* Data Register */
#define ADCREF_DR                     (* (reg8 *) ADCREF__DR)
/* Port Number */
#define ADCREF_PRT_NUM                (* (reg8 *) ADCREF__PRT) 
/* Connect to Analog Globals */                                                  
#define ADCREF_AG                     (* (reg8 *) ADCREF__AG)                       
/* Analog MUX bux enable */
#define ADCREF_AMUX                   (* (reg8 *) ADCREF__AMUX) 
/* Bidirectional Enable */                                                        
#define ADCREF_BIE                    (* (reg8 *) ADCREF__BIE)
/* Bit-mask for Aliased Register Access */
#define ADCREF_BIT_MASK               (* (reg8 *) ADCREF__BIT_MASK)
/* Bypass Enable */
#define ADCREF_BYP                    (* (reg8 *) ADCREF__BYP)
/* Port wide control signals */                                                   
#define ADCREF_CTL                    (* (reg8 *) ADCREF__CTL)
/* Drive Modes */
#define ADCREF_DM0                    (* (reg8 *) ADCREF__DM0) 
#define ADCREF_DM1                    (* (reg8 *) ADCREF__DM1)
#define ADCREF_DM2                    (* (reg8 *) ADCREF__DM2) 
/* Input Buffer Disable Override */
#define ADCREF_INP_DIS                (* (reg8 *) ADCREF__INP_DIS)
/* LCD Common or Segment Drive */
#define ADCREF_LCD_COM_SEG            (* (reg8 *) ADCREF__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADCREF_LCD_EN                 (* (reg8 *) ADCREF__LCD_EN)
/* Slew Rate Control */
#define ADCREF_SLW                    (* (reg8 *) ADCREF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADCREF_PRTDSI__CAPS_SEL       (* (reg8 *) ADCREF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADCREF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADCREF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADCREF_PRTDSI__OE_SEL0        (* (reg8 *) ADCREF__PRTDSI__OE_SEL0) 
#define ADCREF_PRTDSI__OE_SEL1        (* (reg8 *) ADCREF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADCREF_PRTDSI__OUT_SEL0       (* (reg8 *) ADCREF__PRTDSI__OUT_SEL0) 
#define ADCREF_PRTDSI__OUT_SEL1       (* (reg8 *) ADCREF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADCREF_PRTDSI__SYNC_OUT       (* (reg8 *) ADCREF__PRTDSI__SYNC_OUT) 


#if defined(ADCREF__INTSTAT)  /* Interrupt Registers */

    #define ADCREF_INTSTAT                (* (reg8 *) ADCREF__INTSTAT)
    #define ADCREF_SNAP                   (* (reg8 *) ADCREF__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADCREF_H */


/* [] END OF FILE */
