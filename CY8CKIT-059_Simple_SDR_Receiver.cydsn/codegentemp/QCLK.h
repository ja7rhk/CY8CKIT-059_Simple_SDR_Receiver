/*******************************************************************************
* File Name: QCLK.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_QCLK_H) /* Pins QCLK_H */
#define CY_PINS_QCLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "QCLK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 QCLK__PORT == 15 && ((QCLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    QCLK_Write(uint8 value);
void    QCLK_SetDriveMode(uint8 mode);
uint8   QCLK_ReadDataReg(void);
uint8   QCLK_Read(void);
void    QCLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   QCLK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the QCLK_SetDriveMode() function.
     *  @{
     */
        #define QCLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define QCLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define QCLK_DM_RES_UP          PIN_DM_RES_UP
        #define QCLK_DM_RES_DWN         PIN_DM_RES_DWN
        #define QCLK_DM_OD_LO           PIN_DM_OD_LO
        #define QCLK_DM_OD_HI           PIN_DM_OD_HI
        #define QCLK_DM_STRONG          PIN_DM_STRONG
        #define QCLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define QCLK_MASK               QCLK__MASK
#define QCLK_SHIFT              QCLK__SHIFT
#define QCLK_WIDTH              1u

/* Interrupt constants */
#if defined(QCLK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in QCLK_SetInterruptMode() function.
     *  @{
     */
        #define QCLK_INTR_NONE      (uint16)(0x0000u)
        #define QCLK_INTR_RISING    (uint16)(0x0001u)
        #define QCLK_INTR_FALLING   (uint16)(0x0002u)
        #define QCLK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define QCLK_INTR_MASK      (0x01u) 
#endif /* (QCLK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define QCLK_PS                     (* (reg8 *) QCLK__PS)
/* Data Register */
#define QCLK_DR                     (* (reg8 *) QCLK__DR)
/* Port Number */
#define QCLK_PRT_NUM                (* (reg8 *) QCLK__PRT) 
/* Connect to Analog Globals */                                                  
#define QCLK_AG                     (* (reg8 *) QCLK__AG)                       
/* Analog MUX bux enable */
#define QCLK_AMUX                   (* (reg8 *) QCLK__AMUX) 
/* Bidirectional Enable */                                                        
#define QCLK_BIE                    (* (reg8 *) QCLK__BIE)
/* Bit-mask for Aliased Register Access */
#define QCLK_BIT_MASK               (* (reg8 *) QCLK__BIT_MASK)
/* Bypass Enable */
#define QCLK_BYP                    (* (reg8 *) QCLK__BYP)
/* Port wide control signals */                                                   
#define QCLK_CTL                    (* (reg8 *) QCLK__CTL)
/* Drive Modes */
#define QCLK_DM0                    (* (reg8 *) QCLK__DM0) 
#define QCLK_DM1                    (* (reg8 *) QCLK__DM1)
#define QCLK_DM2                    (* (reg8 *) QCLK__DM2) 
/* Input Buffer Disable Override */
#define QCLK_INP_DIS                (* (reg8 *) QCLK__INP_DIS)
/* LCD Common or Segment Drive */
#define QCLK_LCD_COM_SEG            (* (reg8 *) QCLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define QCLK_LCD_EN                 (* (reg8 *) QCLK__LCD_EN)
/* Slew Rate Control */
#define QCLK_SLW                    (* (reg8 *) QCLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define QCLK_PRTDSI__CAPS_SEL       (* (reg8 *) QCLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define QCLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) QCLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define QCLK_PRTDSI__OE_SEL0        (* (reg8 *) QCLK__PRTDSI__OE_SEL0) 
#define QCLK_PRTDSI__OE_SEL1        (* (reg8 *) QCLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define QCLK_PRTDSI__OUT_SEL0       (* (reg8 *) QCLK__PRTDSI__OUT_SEL0) 
#define QCLK_PRTDSI__OUT_SEL1       (* (reg8 *) QCLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define QCLK_PRTDSI__SYNC_OUT       (* (reg8 *) QCLK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(QCLK__SIO_CFG)
    #define QCLK_SIO_HYST_EN        (* (reg8 *) QCLK__SIO_HYST_EN)
    #define QCLK_SIO_REG_HIFREQ     (* (reg8 *) QCLK__SIO_REG_HIFREQ)
    #define QCLK_SIO_CFG            (* (reg8 *) QCLK__SIO_CFG)
    #define QCLK_SIO_DIFF           (* (reg8 *) QCLK__SIO_DIFF)
#endif /* (QCLK__SIO_CFG) */

/* Interrupt Registers */
#if defined(QCLK__INTSTAT)
    #define QCLK_INTSTAT            (* (reg8 *) QCLK__INTSTAT)
    #define QCLK_SNAP               (* (reg8 *) QCLK__SNAP)
    
	#define QCLK_0_INTTYPE_REG 		(* (reg8 *) QCLK__0__INTTYPE)
#endif /* (QCLK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_QCLK_H */


/* [] END OF FILE */
