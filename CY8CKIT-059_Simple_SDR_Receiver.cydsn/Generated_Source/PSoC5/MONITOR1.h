/*******************************************************************************
* File Name: MONITOR1.h  
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

#if !defined(CY_PINS_MONITOR1_H) /* Pins MONITOR1_H */
#define CY_PINS_MONITOR1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MONITOR1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MONITOR1__PORT == 15 && ((MONITOR1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MONITOR1_Write(uint8 value);
void    MONITOR1_SetDriveMode(uint8 mode);
uint8   MONITOR1_ReadDataReg(void);
uint8   MONITOR1_Read(void);
void    MONITOR1_SetInterruptMode(uint16 position, uint16 mode);
uint8   MONITOR1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MONITOR1_SetDriveMode() function.
     *  @{
     */
        #define MONITOR1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MONITOR1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MONITOR1_DM_RES_UP          PIN_DM_RES_UP
        #define MONITOR1_DM_RES_DWN         PIN_DM_RES_DWN
        #define MONITOR1_DM_OD_LO           PIN_DM_OD_LO
        #define MONITOR1_DM_OD_HI           PIN_DM_OD_HI
        #define MONITOR1_DM_STRONG          PIN_DM_STRONG
        #define MONITOR1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MONITOR1_MASK               MONITOR1__MASK
#define MONITOR1_SHIFT              MONITOR1__SHIFT
#define MONITOR1_WIDTH              1u

/* Interrupt constants */
#if defined(MONITOR1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MONITOR1_SetInterruptMode() function.
     *  @{
     */
        #define MONITOR1_INTR_NONE      (uint16)(0x0000u)
        #define MONITOR1_INTR_RISING    (uint16)(0x0001u)
        #define MONITOR1_INTR_FALLING   (uint16)(0x0002u)
        #define MONITOR1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MONITOR1_INTR_MASK      (0x01u) 
#endif /* (MONITOR1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MONITOR1_PS                     (* (reg8 *) MONITOR1__PS)
/* Data Register */
#define MONITOR1_DR                     (* (reg8 *) MONITOR1__DR)
/* Port Number */
#define MONITOR1_PRT_NUM                (* (reg8 *) MONITOR1__PRT) 
/* Connect to Analog Globals */                                                  
#define MONITOR1_AG                     (* (reg8 *) MONITOR1__AG)                       
/* Analog MUX bux enable */
#define MONITOR1_AMUX                   (* (reg8 *) MONITOR1__AMUX) 
/* Bidirectional Enable */                                                        
#define MONITOR1_BIE                    (* (reg8 *) MONITOR1__BIE)
/* Bit-mask for Aliased Register Access */
#define MONITOR1_BIT_MASK               (* (reg8 *) MONITOR1__BIT_MASK)
/* Bypass Enable */
#define MONITOR1_BYP                    (* (reg8 *) MONITOR1__BYP)
/* Port wide control signals */                                                   
#define MONITOR1_CTL                    (* (reg8 *) MONITOR1__CTL)
/* Drive Modes */
#define MONITOR1_DM0                    (* (reg8 *) MONITOR1__DM0) 
#define MONITOR1_DM1                    (* (reg8 *) MONITOR1__DM1)
#define MONITOR1_DM2                    (* (reg8 *) MONITOR1__DM2) 
/* Input Buffer Disable Override */
#define MONITOR1_INP_DIS                (* (reg8 *) MONITOR1__INP_DIS)
/* LCD Common or Segment Drive */
#define MONITOR1_LCD_COM_SEG            (* (reg8 *) MONITOR1__LCD_COM_SEG)
/* Enable Segment LCD */
#define MONITOR1_LCD_EN                 (* (reg8 *) MONITOR1__LCD_EN)
/* Slew Rate Control */
#define MONITOR1_SLW                    (* (reg8 *) MONITOR1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MONITOR1_PRTDSI__CAPS_SEL       (* (reg8 *) MONITOR1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MONITOR1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MONITOR1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MONITOR1_PRTDSI__OE_SEL0        (* (reg8 *) MONITOR1__PRTDSI__OE_SEL0) 
#define MONITOR1_PRTDSI__OE_SEL1        (* (reg8 *) MONITOR1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MONITOR1_PRTDSI__OUT_SEL0       (* (reg8 *) MONITOR1__PRTDSI__OUT_SEL0) 
#define MONITOR1_PRTDSI__OUT_SEL1       (* (reg8 *) MONITOR1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MONITOR1_PRTDSI__SYNC_OUT       (* (reg8 *) MONITOR1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MONITOR1__SIO_CFG)
    #define MONITOR1_SIO_HYST_EN        (* (reg8 *) MONITOR1__SIO_HYST_EN)
    #define MONITOR1_SIO_REG_HIFREQ     (* (reg8 *) MONITOR1__SIO_REG_HIFREQ)
    #define MONITOR1_SIO_CFG            (* (reg8 *) MONITOR1__SIO_CFG)
    #define MONITOR1_SIO_DIFF           (* (reg8 *) MONITOR1__SIO_DIFF)
#endif /* (MONITOR1__SIO_CFG) */

/* Interrupt Registers */
#if defined(MONITOR1__INTSTAT)
    #define MONITOR1_INTSTAT            (* (reg8 *) MONITOR1__INTSTAT)
    #define MONITOR1_SNAP               (* (reg8 *) MONITOR1__SNAP)
    
	#define MONITOR1_0_INTTYPE_REG 		(* (reg8 *) MONITOR1__0__INTTYPE)
#endif /* (MONITOR1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MONITOR1_H */


/* [] END OF FILE */
