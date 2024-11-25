/*******************************************************************************
* File Name: IOUT.h  
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

#if !defined(CY_PINS_IOUT_H) /* Pins IOUT_H */
#define CY_PINS_IOUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IOUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IOUT__PORT == 15 && ((IOUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    IOUT_Write(uint8 value) ;
void    IOUT_SetDriveMode(uint8 mode) ;
uint8   IOUT_ReadDataReg(void) ;
uint8   IOUT_Read(void) ;
uint8   IOUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IOUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define IOUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define IOUT_DM_RES_UP          PIN_DM_RES_UP
#define IOUT_DM_RES_DWN         PIN_DM_RES_DWN
#define IOUT_DM_OD_LO           PIN_DM_OD_LO
#define IOUT_DM_OD_HI           PIN_DM_OD_HI
#define IOUT_DM_STRONG          PIN_DM_STRONG
#define IOUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define IOUT_MASK               IOUT__MASK
#define IOUT_SHIFT              IOUT__SHIFT
#define IOUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IOUT_PS                     (* (reg8 *) IOUT__PS)
/* Data Register */
#define IOUT_DR                     (* (reg8 *) IOUT__DR)
/* Port Number */
#define IOUT_PRT_NUM                (* (reg8 *) IOUT__PRT) 
/* Connect to Analog Globals */                                                  
#define IOUT_AG                     (* (reg8 *) IOUT__AG)                       
/* Analog MUX bux enable */
#define IOUT_AMUX                   (* (reg8 *) IOUT__AMUX) 
/* Bidirectional Enable */                                                        
#define IOUT_BIE                    (* (reg8 *) IOUT__BIE)
/* Bit-mask for Aliased Register Access */
#define IOUT_BIT_MASK               (* (reg8 *) IOUT__BIT_MASK)
/* Bypass Enable */
#define IOUT_BYP                    (* (reg8 *) IOUT__BYP)
/* Port wide control signals */                                                   
#define IOUT_CTL                    (* (reg8 *) IOUT__CTL)
/* Drive Modes */
#define IOUT_DM0                    (* (reg8 *) IOUT__DM0) 
#define IOUT_DM1                    (* (reg8 *) IOUT__DM1)
#define IOUT_DM2                    (* (reg8 *) IOUT__DM2) 
/* Input Buffer Disable Override */
#define IOUT_INP_DIS                (* (reg8 *) IOUT__INP_DIS)
/* LCD Common or Segment Drive */
#define IOUT_LCD_COM_SEG            (* (reg8 *) IOUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define IOUT_LCD_EN                 (* (reg8 *) IOUT__LCD_EN)
/* Slew Rate Control */
#define IOUT_SLW                    (* (reg8 *) IOUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IOUT_PRTDSI__CAPS_SEL       (* (reg8 *) IOUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IOUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IOUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IOUT_PRTDSI__OE_SEL0        (* (reg8 *) IOUT__PRTDSI__OE_SEL0) 
#define IOUT_PRTDSI__OE_SEL1        (* (reg8 *) IOUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IOUT_PRTDSI__OUT_SEL0       (* (reg8 *) IOUT__PRTDSI__OUT_SEL0) 
#define IOUT_PRTDSI__OUT_SEL1       (* (reg8 *) IOUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IOUT_PRTDSI__SYNC_OUT       (* (reg8 *) IOUT__PRTDSI__SYNC_OUT) 


#if defined(IOUT__INTSTAT)  /* Interrupt Registers */

    #define IOUT_INTSTAT                (* (reg8 *) IOUT__INTSTAT)
    #define IOUT_SNAP                   (* (reg8 *) IOUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IOUT_H */


/* [] END OF FILE */
