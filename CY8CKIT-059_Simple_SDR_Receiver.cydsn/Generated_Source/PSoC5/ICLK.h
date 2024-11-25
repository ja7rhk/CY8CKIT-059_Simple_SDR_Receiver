/*******************************************************************************
* File Name: ICLK.h  
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

#if !defined(CY_PINS_ICLK_H) /* Pins ICLK_H */
#define CY_PINS_ICLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ICLK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ICLK__PORT == 15 && ((ICLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ICLK_Write(uint8 value);
void    ICLK_SetDriveMode(uint8 mode);
uint8   ICLK_ReadDataReg(void);
uint8   ICLK_Read(void);
void    ICLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   ICLK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ICLK_SetDriveMode() function.
     *  @{
     */
        #define ICLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ICLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ICLK_DM_RES_UP          PIN_DM_RES_UP
        #define ICLK_DM_RES_DWN         PIN_DM_RES_DWN
        #define ICLK_DM_OD_LO           PIN_DM_OD_LO
        #define ICLK_DM_OD_HI           PIN_DM_OD_HI
        #define ICLK_DM_STRONG          PIN_DM_STRONG
        #define ICLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ICLK_MASK               ICLK__MASK
#define ICLK_SHIFT              ICLK__SHIFT
#define ICLK_WIDTH              1u

/* Interrupt constants */
#if defined(ICLK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ICLK_SetInterruptMode() function.
     *  @{
     */
        #define ICLK_INTR_NONE      (uint16)(0x0000u)
        #define ICLK_INTR_RISING    (uint16)(0x0001u)
        #define ICLK_INTR_FALLING   (uint16)(0x0002u)
        #define ICLK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ICLK_INTR_MASK      (0x01u) 
#endif /* (ICLK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ICLK_PS                     (* (reg8 *) ICLK__PS)
/* Data Register */
#define ICLK_DR                     (* (reg8 *) ICLK__DR)
/* Port Number */
#define ICLK_PRT_NUM                (* (reg8 *) ICLK__PRT) 
/* Connect to Analog Globals */                                                  
#define ICLK_AG                     (* (reg8 *) ICLK__AG)                       
/* Analog MUX bux enable */
#define ICLK_AMUX                   (* (reg8 *) ICLK__AMUX) 
/* Bidirectional Enable */                                                        
#define ICLK_BIE                    (* (reg8 *) ICLK__BIE)
/* Bit-mask for Aliased Register Access */
#define ICLK_BIT_MASK               (* (reg8 *) ICLK__BIT_MASK)
/* Bypass Enable */
#define ICLK_BYP                    (* (reg8 *) ICLK__BYP)
/* Port wide control signals */                                                   
#define ICLK_CTL                    (* (reg8 *) ICLK__CTL)
/* Drive Modes */
#define ICLK_DM0                    (* (reg8 *) ICLK__DM0) 
#define ICLK_DM1                    (* (reg8 *) ICLK__DM1)
#define ICLK_DM2                    (* (reg8 *) ICLK__DM2) 
/* Input Buffer Disable Override */
#define ICLK_INP_DIS                (* (reg8 *) ICLK__INP_DIS)
/* LCD Common or Segment Drive */
#define ICLK_LCD_COM_SEG            (* (reg8 *) ICLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define ICLK_LCD_EN                 (* (reg8 *) ICLK__LCD_EN)
/* Slew Rate Control */
#define ICLK_SLW                    (* (reg8 *) ICLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ICLK_PRTDSI__CAPS_SEL       (* (reg8 *) ICLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ICLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ICLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ICLK_PRTDSI__OE_SEL0        (* (reg8 *) ICLK__PRTDSI__OE_SEL0) 
#define ICLK_PRTDSI__OE_SEL1        (* (reg8 *) ICLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ICLK_PRTDSI__OUT_SEL0       (* (reg8 *) ICLK__PRTDSI__OUT_SEL0) 
#define ICLK_PRTDSI__OUT_SEL1       (* (reg8 *) ICLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ICLK_PRTDSI__SYNC_OUT       (* (reg8 *) ICLK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ICLK__SIO_CFG)
    #define ICLK_SIO_HYST_EN        (* (reg8 *) ICLK__SIO_HYST_EN)
    #define ICLK_SIO_REG_HIFREQ     (* (reg8 *) ICLK__SIO_REG_HIFREQ)
    #define ICLK_SIO_CFG            (* (reg8 *) ICLK__SIO_CFG)
    #define ICLK_SIO_DIFF           (* (reg8 *) ICLK__SIO_DIFF)
#endif /* (ICLK__SIO_CFG) */

/* Interrupt Registers */
#if defined(ICLK__INTSTAT)
    #define ICLK_INTSTAT            (* (reg8 *) ICLK__INTSTAT)
    #define ICLK_SNAP               (* (reg8 *) ICLK__SNAP)
    
	#define ICLK_0_INTTYPE_REG 		(* (reg8 *) ICLK__0__INTTYPE)
#endif /* (ICLK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ICLK_H */


/* [] END OF FILE */
