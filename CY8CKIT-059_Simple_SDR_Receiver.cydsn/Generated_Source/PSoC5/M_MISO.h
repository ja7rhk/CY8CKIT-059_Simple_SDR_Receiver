/*******************************************************************************
* File Name: M_MISO.h  
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

#if !defined(CY_PINS_M_MISO_H) /* Pins M_MISO_H */
#define CY_PINS_M_MISO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "M_MISO_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 M_MISO__PORT == 15 && ((M_MISO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    M_MISO_Write(uint8 value);
void    M_MISO_SetDriveMode(uint8 mode);
uint8   M_MISO_ReadDataReg(void);
uint8   M_MISO_Read(void);
void    M_MISO_SetInterruptMode(uint16 position, uint16 mode);
uint8   M_MISO_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the M_MISO_SetDriveMode() function.
     *  @{
     */
        #define M_MISO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define M_MISO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define M_MISO_DM_RES_UP          PIN_DM_RES_UP
        #define M_MISO_DM_RES_DWN         PIN_DM_RES_DWN
        #define M_MISO_DM_OD_LO           PIN_DM_OD_LO
        #define M_MISO_DM_OD_HI           PIN_DM_OD_HI
        #define M_MISO_DM_STRONG          PIN_DM_STRONG
        #define M_MISO_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define M_MISO_MASK               M_MISO__MASK
#define M_MISO_SHIFT              M_MISO__SHIFT
#define M_MISO_WIDTH              1u

/* Interrupt constants */
#if defined(M_MISO__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in M_MISO_SetInterruptMode() function.
     *  @{
     */
        #define M_MISO_INTR_NONE      (uint16)(0x0000u)
        #define M_MISO_INTR_RISING    (uint16)(0x0001u)
        #define M_MISO_INTR_FALLING   (uint16)(0x0002u)
        #define M_MISO_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define M_MISO_INTR_MASK      (0x01u) 
#endif /* (M_MISO__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define M_MISO_PS                     (* (reg8 *) M_MISO__PS)
/* Data Register */
#define M_MISO_DR                     (* (reg8 *) M_MISO__DR)
/* Port Number */
#define M_MISO_PRT_NUM                (* (reg8 *) M_MISO__PRT) 
/* Connect to Analog Globals */                                                  
#define M_MISO_AG                     (* (reg8 *) M_MISO__AG)                       
/* Analog MUX bux enable */
#define M_MISO_AMUX                   (* (reg8 *) M_MISO__AMUX) 
/* Bidirectional Enable */                                                        
#define M_MISO_BIE                    (* (reg8 *) M_MISO__BIE)
/* Bit-mask for Aliased Register Access */
#define M_MISO_BIT_MASK               (* (reg8 *) M_MISO__BIT_MASK)
/* Bypass Enable */
#define M_MISO_BYP                    (* (reg8 *) M_MISO__BYP)
/* Port wide control signals */                                                   
#define M_MISO_CTL                    (* (reg8 *) M_MISO__CTL)
/* Drive Modes */
#define M_MISO_DM0                    (* (reg8 *) M_MISO__DM0) 
#define M_MISO_DM1                    (* (reg8 *) M_MISO__DM1)
#define M_MISO_DM2                    (* (reg8 *) M_MISO__DM2) 
/* Input Buffer Disable Override */
#define M_MISO_INP_DIS                (* (reg8 *) M_MISO__INP_DIS)
/* LCD Common or Segment Drive */
#define M_MISO_LCD_COM_SEG            (* (reg8 *) M_MISO__LCD_COM_SEG)
/* Enable Segment LCD */
#define M_MISO_LCD_EN                 (* (reg8 *) M_MISO__LCD_EN)
/* Slew Rate Control */
#define M_MISO_SLW                    (* (reg8 *) M_MISO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define M_MISO_PRTDSI__CAPS_SEL       (* (reg8 *) M_MISO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define M_MISO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) M_MISO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define M_MISO_PRTDSI__OE_SEL0        (* (reg8 *) M_MISO__PRTDSI__OE_SEL0) 
#define M_MISO_PRTDSI__OE_SEL1        (* (reg8 *) M_MISO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define M_MISO_PRTDSI__OUT_SEL0       (* (reg8 *) M_MISO__PRTDSI__OUT_SEL0) 
#define M_MISO_PRTDSI__OUT_SEL1       (* (reg8 *) M_MISO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define M_MISO_PRTDSI__SYNC_OUT       (* (reg8 *) M_MISO__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(M_MISO__SIO_CFG)
    #define M_MISO_SIO_HYST_EN        (* (reg8 *) M_MISO__SIO_HYST_EN)
    #define M_MISO_SIO_REG_HIFREQ     (* (reg8 *) M_MISO__SIO_REG_HIFREQ)
    #define M_MISO_SIO_CFG            (* (reg8 *) M_MISO__SIO_CFG)
    #define M_MISO_SIO_DIFF           (* (reg8 *) M_MISO__SIO_DIFF)
#endif /* (M_MISO__SIO_CFG) */

/* Interrupt Registers */
#if defined(M_MISO__INTSTAT)
    #define M_MISO_INTSTAT            (* (reg8 *) M_MISO__INTSTAT)
    #define M_MISO_SNAP               (* (reg8 *) M_MISO__SNAP)
    
	#define M_MISO_0_INTTYPE_REG 		(* (reg8 *) M_MISO__0__INTTYPE)
#endif /* (M_MISO__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_M_MISO_H */


/* [] END OF FILE */
