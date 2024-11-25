/*******************************************************************************
* File Name: BLUELED.h  
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

#if !defined(CY_PINS_BLUELED_H) /* Pins BLUELED_H */
#define CY_PINS_BLUELED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BLUELED_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BLUELED__PORT == 15 && ((BLUELED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    BLUELED_Write(uint8 value) ;
void    BLUELED_SetDriveMode(uint8 mode) ;
uint8   BLUELED_ReadDataReg(void) ;
uint8   BLUELED_Read(void) ;
uint8   BLUELED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BLUELED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BLUELED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BLUELED_DM_RES_UP          PIN_DM_RES_UP
#define BLUELED_DM_RES_DWN         PIN_DM_RES_DWN
#define BLUELED_DM_OD_LO           PIN_DM_OD_LO
#define BLUELED_DM_OD_HI           PIN_DM_OD_HI
#define BLUELED_DM_STRONG          PIN_DM_STRONG
#define BLUELED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BLUELED_MASK               BLUELED__MASK
#define BLUELED_SHIFT              BLUELED__SHIFT
#define BLUELED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BLUELED_PS                     (* (reg8 *) BLUELED__PS)
/* Data Register */
#define BLUELED_DR                     (* (reg8 *) BLUELED__DR)
/* Port Number */
#define BLUELED_PRT_NUM                (* (reg8 *) BLUELED__PRT) 
/* Connect to Analog Globals */                                                  
#define BLUELED_AG                     (* (reg8 *) BLUELED__AG)                       
/* Analog MUX bux enable */
#define BLUELED_AMUX                   (* (reg8 *) BLUELED__AMUX) 
/* Bidirectional Enable */                                                        
#define BLUELED_BIE                    (* (reg8 *) BLUELED__BIE)
/* Bit-mask for Aliased Register Access */
#define BLUELED_BIT_MASK               (* (reg8 *) BLUELED__BIT_MASK)
/* Bypass Enable */
#define BLUELED_BYP                    (* (reg8 *) BLUELED__BYP)
/* Port wide control signals */                                                   
#define BLUELED_CTL                    (* (reg8 *) BLUELED__CTL)
/* Drive Modes */
#define BLUELED_DM0                    (* (reg8 *) BLUELED__DM0) 
#define BLUELED_DM1                    (* (reg8 *) BLUELED__DM1)
#define BLUELED_DM2                    (* (reg8 *) BLUELED__DM2) 
/* Input Buffer Disable Override */
#define BLUELED_INP_DIS                (* (reg8 *) BLUELED__INP_DIS)
/* LCD Common or Segment Drive */
#define BLUELED_LCD_COM_SEG            (* (reg8 *) BLUELED__LCD_COM_SEG)
/* Enable Segment LCD */
#define BLUELED_LCD_EN                 (* (reg8 *) BLUELED__LCD_EN)
/* Slew Rate Control */
#define BLUELED_SLW                    (* (reg8 *) BLUELED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BLUELED_PRTDSI__CAPS_SEL       (* (reg8 *) BLUELED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BLUELED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BLUELED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BLUELED_PRTDSI__OE_SEL0        (* (reg8 *) BLUELED__PRTDSI__OE_SEL0) 
#define BLUELED_PRTDSI__OE_SEL1        (* (reg8 *) BLUELED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BLUELED_PRTDSI__OUT_SEL0       (* (reg8 *) BLUELED__PRTDSI__OUT_SEL0) 
#define BLUELED_PRTDSI__OUT_SEL1       (* (reg8 *) BLUELED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BLUELED_PRTDSI__SYNC_OUT       (* (reg8 *) BLUELED__PRTDSI__SYNC_OUT) 


#if defined(BLUELED__INTSTAT)  /* Interrupt Registers */

    #define BLUELED_INTSTAT                (* (reg8 *) BLUELED__INTSTAT)
    #define BLUELED_SNAP                   (* (reg8 *) BLUELED__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BLUELED_H */


/* [] END OF FILE */
