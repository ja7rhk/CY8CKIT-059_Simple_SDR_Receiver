/*******************************************************************************
* File Name: QCHAN.h  
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

#if !defined(CY_PINS_QCHAN_H) /* Pins QCHAN_H */
#define CY_PINS_QCHAN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "QCHAN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 QCHAN__PORT == 15 && ((QCHAN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    QCHAN_Write(uint8 value) ;
void    QCHAN_SetDriveMode(uint8 mode) ;
uint8   QCHAN_ReadDataReg(void) ;
uint8   QCHAN_Read(void) ;
uint8   QCHAN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define QCHAN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define QCHAN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define QCHAN_DM_RES_UP          PIN_DM_RES_UP
#define QCHAN_DM_RES_DWN         PIN_DM_RES_DWN
#define QCHAN_DM_OD_LO           PIN_DM_OD_LO
#define QCHAN_DM_OD_HI           PIN_DM_OD_HI
#define QCHAN_DM_STRONG          PIN_DM_STRONG
#define QCHAN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define QCHAN_MASK               QCHAN__MASK
#define QCHAN_SHIFT              QCHAN__SHIFT
#define QCHAN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define QCHAN_PS                     (* (reg8 *) QCHAN__PS)
/* Data Register */
#define QCHAN_DR                     (* (reg8 *) QCHAN__DR)
/* Port Number */
#define QCHAN_PRT_NUM                (* (reg8 *) QCHAN__PRT) 
/* Connect to Analog Globals */                                                  
#define QCHAN_AG                     (* (reg8 *) QCHAN__AG)                       
/* Analog MUX bux enable */
#define QCHAN_AMUX                   (* (reg8 *) QCHAN__AMUX) 
/* Bidirectional Enable */                                                        
#define QCHAN_BIE                    (* (reg8 *) QCHAN__BIE)
/* Bit-mask for Aliased Register Access */
#define QCHAN_BIT_MASK               (* (reg8 *) QCHAN__BIT_MASK)
/* Bypass Enable */
#define QCHAN_BYP                    (* (reg8 *) QCHAN__BYP)
/* Port wide control signals */                                                   
#define QCHAN_CTL                    (* (reg8 *) QCHAN__CTL)
/* Drive Modes */
#define QCHAN_DM0                    (* (reg8 *) QCHAN__DM0) 
#define QCHAN_DM1                    (* (reg8 *) QCHAN__DM1)
#define QCHAN_DM2                    (* (reg8 *) QCHAN__DM2) 
/* Input Buffer Disable Override */
#define QCHAN_INP_DIS                (* (reg8 *) QCHAN__INP_DIS)
/* LCD Common or Segment Drive */
#define QCHAN_LCD_COM_SEG            (* (reg8 *) QCHAN__LCD_COM_SEG)
/* Enable Segment LCD */
#define QCHAN_LCD_EN                 (* (reg8 *) QCHAN__LCD_EN)
/* Slew Rate Control */
#define QCHAN_SLW                    (* (reg8 *) QCHAN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define QCHAN_PRTDSI__CAPS_SEL       (* (reg8 *) QCHAN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define QCHAN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) QCHAN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define QCHAN_PRTDSI__OE_SEL0        (* (reg8 *) QCHAN__PRTDSI__OE_SEL0) 
#define QCHAN_PRTDSI__OE_SEL1        (* (reg8 *) QCHAN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define QCHAN_PRTDSI__OUT_SEL0       (* (reg8 *) QCHAN__PRTDSI__OUT_SEL0) 
#define QCHAN_PRTDSI__OUT_SEL1       (* (reg8 *) QCHAN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define QCHAN_PRTDSI__SYNC_OUT       (* (reg8 *) QCHAN__PRTDSI__SYNC_OUT) 


#if defined(QCHAN__INTSTAT)  /* Interrupt Registers */

    #define QCHAN_INTSTAT                (* (reg8 *) QCHAN__INTSTAT)
    #define QCHAN_SNAP                   (* (reg8 *) QCHAN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_QCHAN_H */


/* [] END OF FILE */
