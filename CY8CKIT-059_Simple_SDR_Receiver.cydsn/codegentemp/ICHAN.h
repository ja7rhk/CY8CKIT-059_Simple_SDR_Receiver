/*******************************************************************************
* File Name: ICHAN.h  
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

#if !defined(CY_PINS_ICHAN_H) /* Pins ICHAN_H */
#define CY_PINS_ICHAN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ICHAN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ICHAN__PORT == 15 && ((ICHAN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ICHAN_Write(uint8 value) ;
void    ICHAN_SetDriveMode(uint8 mode) ;
uint8   ICHAN_ReadDataReg(void) ;
uint8   ICHAN_Read(void) ;
uint8   ICHAN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ICHAN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ICHAN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ICHAN_DM_RES_UP          PIN_DM_RES_UP
#define ICHAN_DM_RES_DWN         PIN_DM_RES_DWN
#define ICHAN_DM_OD_LO           PIN_DM_OD_LO
#define ICHAN_DM_OD_HI           PIN_DM_OD_HI
#define ICHAN_DM_STRONG          PIN_DM_STRONG
#define ICHAN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ICHAN_MASK               ICHAN__MASK
#define ICHAN_SHIFT              ICHAN__SHIFT
#define ICHAN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ICHAN_PS                     (* (reg8 *) ICHAN__PS)
/* Data Register */
#define ICHAN_DR                     (* (reg8 *) ICHAN__DR)
/* Port Number */
#define ICHAN_PRT_NUM                (* (reg8 *) ICHAN__PRT) 
/* Connect to Analog Globals */                                                  
#define ICHAN_AG                     (* (reg8 *) ICHAN__AG)                       
/* Analog MUX bux enable */
#define ICHAN_AMUX                   (* (reg8 *) ICHAN__AMUX) 
/* Bidirectional Enable */                                                        
#define ICHAN_BIE                    (* (reg8 *) ICHAN__BIE)
/* Bit-mask for Aliased Register Access */
#define ICHAN_BIT_MASK               (* (reg8 *) ICHAN__BIT_MASK)
/* Bypass Enable */
#define ICHAN_BYP                    (* (reg8 *) ICHAN__BYP)
/* Port wide control signals */                                                   
#define ICHAN_CTL                    (* (reg8 *) ICHAN__CTL)
/* Drive Modes */
#define ICHAN_DM0                    (* (reg8 *) ICHAN__DM0) 
#define ICHAN_DM1                    (* (reg8 *) ICHAN__DM1)
#define ICHAN_DM2                    (* (reg8 *) ICHAN__DM2) 
/* Input Buffer Disable Override */
#define ICHAN_INP_DIS                (* (reg8 *) ICHAN__INP_DIS)
/* LCD Common or Segment Drive */
#define ICHAN_LCD_COM_SEG            (* (reg8 *) ICHAN__LCD_COM_SEG)
/* Enable Segment LCD */
#define ICHAN_LCD_EN                 (* (reg8 *) ICHAN__LCD_EN)
/* Slew Rate Control */
#define ICHAN_SLW                    (* (reg8 *) ICHAN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ICHAN_PRTDSI__CAPS_SEL       (* (reg8 *) ICHAN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ICHAN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ICHAN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ICHAN_PRTDSI__OE_SEL0        (* (reg8 *) ICHAN__PRTDSI__OE_SEL0) 
#define ICHAN_PRTDSI__OE_SEL1        (* (reg8 *) ICHAN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ICHAN_PRTDSI__OUT_SEL0       (* (reg8 *) ICHAN__PRTDSI__OUT_SEL0) 
#define ICHAN_PRTDSI__OUT_SEL1       (* (reg8 *) ICHAN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ICHAN_PRTDSI__SYNC_OUT       (* (reg8 *) ICHAN__PRTDSI__SYNC_OUT) 


#if defined(ICHAN__INTSTAT)  /* Interrupt Registers */

    #define ICHAN_INTSTAT                (* (reg8 *) ICHAN__INTSTAT)
    #define ICHAN_SNAP                   (* (reg8 *) ICHAN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ICHAN_H */


/* [] END OF FILE */
