/*******************************************************************************
* File Name: QOUT.h  
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

#if !defined(CY_PINS_QOUT_H) /* Pins QOUT_H */
#define CY_PINS_QOUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "QOUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 QOUT__PORT == 15 && ((QOUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    QOUT_Write(uint8 value) ;
void    QOUT_SetDriveMode(uint8 mode) ;
uint8   QOUT_ReadDataReg(void) ;
uint8   QOUT_Read(void) ;
uint8   QOUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define QOUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define QOUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define QOUT_DM_RES_UP          PIN_DM_RES_UP
#define QOUT_DM_RES_DWN         PIN_DM_RES_DWN
#define QOUT_DM_OD_LO           PIN_DM_OD_LO
#define QOUT_DM_OD_HI           PIN_DM_OD_HI
#define QOUT_DM_STRONG          PIN_DM_STRONG
#define QOUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define QOUT_MASK               QOUT__MASK
#define QOUT_SHIFT              QOUT__SHIFT
#define QOUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define QOUT_PS                     (* (reg8 *) QOUT__PS)
/* Data Register */
#define QOUT_DR                     (* (reg8 *) QOUT__DR)
/* Port Number */
#define QOUT_PRT_NUM                (* (reg8 *) QOUT__PRT) 
/* Connect to Analog Globals */                                                  
#define QOUT_AG                     (* (reg8 *) QOUT__AG)                       
/* Analog MUX bux enable */
#define QOUT_AMUX                   (* (reg8 *) QOUT__AMUX) 
/* Bidirectional Enable */                                                        
#define QOUT_BIE                    (* (reg8 *) QOUT__BIE)
/* Bit-mask for Aliased Register Access */
#define QOUT_BIT_MASK               (* (reg8 *) QOUT__BIT_MASK)
/* Bypass Enable */
#define QOUT_BYP                    (* (reg8 *) QOUT__BYP)
/* Port wide control signals */                                                   
#define QOUT_CTL                    (* (reg8 *) QOUT__CTL)
/* Drive Modes */
#define QOUT_DM0                    (* (reg8 *) QOUT__DM0) 
#define QOUT_DM1                    (* (reg8 *) QOUT__DM1)
#define QOUT_DM2                    (* (reg8 *) QOUT__DM2) 
/* Input Buffer Disable Override */
#define QOUT_INP_DIS                (* (reg8 *) QOUT__INP_DIS)
/* LCD Common or Segment Drive */
#define QOUT_LCD_COM_SEG            (* (reg8 *) QOUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define QOUT_LCD_EN                 (* (reg8 *) QOUT__LCD_EN)
/* Slew Rate Control */
#define QOUT_SLW                    (* (reg8 *) QOUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define QOUT_PRTDSI__CAPS_SEL       (* (reg8 *) QOUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define QOUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) QOUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define QOUT_PRTDSI__OE_SEL0        (* (reg8 *) QOUT__PRTDSI__OE_SEL0) 
#define QOUT_PRTDSI__OE_SEL1        (* (reg8 *) QOUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define QOUT_PRTDSI__OUT_SEL0       (* (reg8 *) QOUT__PRTDSI__OUT_SEL0) 
#define QOUT_PRTDSI__OUT_SEL1       (* (reg8 *) QOUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define QOUT_PRTDSI__SYNC_OUT       (* (reg8 *) QOUT__PRTDSI__SYNC_OUT) 


#if defined(QOUT__INTSTAT)  /* Interrupt Registers */

    #define QOUT_INTSTAT                (* (reg8 *) QOUT__INTSTAT)
    #define QOUT_SNAP                   (* (reg8 *) QOUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_QOUT_H */


/* [] END OF FILE */
