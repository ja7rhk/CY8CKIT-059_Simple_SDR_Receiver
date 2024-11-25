/*******************************************************************************
* File Name: REDLED.h  
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

#if !defined(CY_PINS_REDLED_H) /* Pins REDLED_H */
#define CY_PINS_REDLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "REDLED_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 REDLED__PORT == 15 && ((REDLED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    REDLED_Write(uint8 value) ;
void    REDLED_SetDriveMode(uint8 mode) ;
uint8   REDLED_ReadDataReg(void) ;
uint8   REDLED_Read(void) ;
uint8   REDLED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define REDLED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define REDLED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define REDLED_DM_RES_UP          PIN_DM_RES_UP
#define REDLED_DM_RES_DWN         PIN_DM_RES_DWN
#define REDLED_DM_OD_LO           PIN_DM_OD_LO
#define REDLED_DM_OD_HI           PIN_DM_OD_HI
#define REDLED_DM_STRONG          PIN_DM_STRONG
#define REDLED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define REDLED_MASK               REDLED__MASK
#define REDLED_SHIFT              REDLED__SHIFT
#define REDLED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define REDLED_PS                     (* (reg8 *) REDLED__PS)
/* Data Register */
#define REDLED_DR                     (* (reg8 *) REDLED__DR)
/* Port Number */
#define REDLED_PRT_NUM                (* (reg8 *) REDLED__PRT) 
/* Connect to Analog Globals */                                                  
#define REDLED_AG                     (* (reg8 *) REDLED__AG)                       
/* Analog MUX bux enable */
#define REDLED_AMUX                   (* (reg8 *) REDLED__AMUX) 
/* Bidirectional Enable */                                                        
#define REDLED_BIE                    (* (reg8 *) REDLED__BIE)
/* Bit-mask for Aliased Register Access */
#define REDLED_BIT_MASK               (* (reg8 *) REDLED__BIT_MASK)
/* Bypass Enable */
#define REDLED_BYP                    (* (reg8 *) REDLED__BYP)
/* Port wide control signals */                                                   
#define REDLED_CTL                    (* (reg8 *) REDLED__CTL)
/* Drive Modes */
#define REDLED_DM0                    (* (reg8 *) REDLED__DM0) 
#define REDLED_DM1                    (* (reg8 *) REDLED__DM1)
#define REDLED_DM2                    (* (reg8 *) REDLED__DM2) 
/* Input Buffer Disable Override */
#define REDLED_INP_DIS                (* (reg8 *) REDLED__INP_DIS)
/* LCD Common or Segment Drive */
#define REDLED_LCD_COM_SEG            (* (reg8 *) REDLED__LCD_COM_SEG)
/* Enable Segment LCD */
#define REDLED_LCD_EN                 (* (reg8 *) REDLED__LCD_EN)
/* Slew Rate Control */
#define REDLED_SLW                    (* (reg8 *) REDLED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define REDLED_PRTDSI__CAPS_SEL       (* (reg8 *) REDLED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define REDLED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) REDLED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define REDLED_PRTDSI__OE_SEL0        (* (reg8 *) REDLED__PRTDSI__OE_SEL0) 
#define REDLED_PRTDSI__OE_SEL1        (* (reg8 *) REDLED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define REDLED_PRTDSI__OUT_SEL0       (* (reg8 *) REDLED__PRTDSI__OUT_SEL0) 
#define REDLED_PRTDSI__OUT_SEL1       (* (reg8 *) REDLED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define REDLED_PRTDSI__SYNC_OUT       (* (reg8 *) REDLED__PRTDSI__SYNC_OUT) 


#if defined(REDLED__INTSTAT)  /* Interrupt Registers */

    #define REDLED_INTSTAT                (* (reg8 *) REDLED__INTSTAT)
    #define REDLED_SNAP                   (* (reg8 *) REDLED__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_REDLED_H */


/* [] END OF FILE */
