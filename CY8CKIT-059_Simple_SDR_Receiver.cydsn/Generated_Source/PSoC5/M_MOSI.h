/*******************************************************************************
* File Name: M_MOSI.h  
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

#if !defined(CY_PINS_M_MOSI_H) /* Pins M_MOSI_H */
#define CY_PINS_M_MOSI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "M_MOSI_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 M_MOSI__PORT == 15 && ((M_MOSI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    M_MOSI_Write(uint8 value);
void    M_MOSI_SetDriveMode(uint8 mode);
uint8   M_MOSI_ReadDataReg(void);
uint8   M_MOSI_Read(void);
void    M_MOSI_SetInterruptMode(uint16 position, uint16 mode);
uint8   M_MOSI_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the M_MOSI_SetDriveMode() function.
     *  @{
     */
        #define M_MOSI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define M_MOSI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define M_MOSI_DM_RES_UP          PIN_DM_RES_UP
        #define M_MOSI_DM_RES_DWN         PIN_DM_RES_DWN
        #define M_MOSI_DM_OD_LO           PIN_DM_OD_LO
        #define M_MOSI_DM_OD_HI           PIN_DM_OD_HI
        #define M_MOSI_DM_STRONG          PIN_DM_STRONG
        #define M_MOSI_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define M_MOSI_MASK               M_MOSI__MASK
#define M_MOSI_SHIFT              M_MOSI__SHIFT
#define M_MOSI_WIDTH              1u

/* Interrupt constants */
#if defined(M_MOSI__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in M_MOSI_SetInterruptMode() function.
     *  @{
     */
        #define M_MOSI_INTR_NONE      (uint16)(0x0000u)
        #define M_MOSI_INTR_RISING    (uint16)(0x0001u)
        #define M_MOSI_INTR_FALLING   (uint16)(0x0002u)
        #define M_MOSI_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define M_MOSI_INTR_MASK      (0x01u) 
#endif /* (M_MOSI__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define M_MOSI_PS                     (* (reg8 *) M_MOSI__PS)
/* Data Register */
#define M_MOSI_DR                     (* (reg8 *) M_MOSI__DR)
/* Port Number */
#define M_MOSI_PRT_NUM                (* (reg8 *) M_MOSI__PRT) 
/* Connect to Analog Globals */                                                  
#define M_MOSI_AG                     (* (reg8 *) M_MOSI__AG)                       
/* Analog MUX bux enable */
#define M_MOSI_AMUX                   (* (reg8 *) M_MOSI__AMUX) 
/* Bidirectional Enable */                                                        
#define M_MOSI_BIE                    (* (reg8 *) M_MOSI__BIE)
/* Bit-mask for Aliased Register Access */
#define M_MOSI_BIT_MASK               (* (reg8 *) M_MOSI__BIT_MASK)
/* Bypass Enable */
#define M_MOSI_BYP                    (* (reg8 *) M_MOSI__BYP)
/* Port wide control signals */                                                   
#define M_MOSI_CTL                    (* (reg8 *) M_MOSI__CTL)
/* Drive Modes */
#define M_MOSI_DM0                    (* (reg8 *) M_MOSI__DM0) 
#define M_MOSI_DM1                    (* (reg8 *) M_MOSI__DM1)
#define M_MOSI_DM2                    (* (reg8 *) M_MOSI__DM2) 
/* Input Buffer Disable Override */
#define M_MOSI_INP_DIS                (* (reg8 *) M_MOSI__INP_DIS)
/* LCD Common or Segment Drive */
#define M_MOSI_LCD_COM_SEG            (* (reg8 *) M_MOSI__LCD_COM_SEG)
/* Enable Segment LCD */
#define M_MOSI_LCD_EN                 (* (reg8 *) M_MOSI__LCD_EN)
/* Slew Rate Control */
#define M_MOSI_SLW                    (* (reg8 *) M_MOSI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define M_MOSI_PRTDSI__CAPS_SEL       (* (reg8 *) M_MOSI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define M_MOSI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) M_MOSI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define M_MOSI_PRTDSI__OE_SEL0        (* (reg8 *) M_MOSI__PRTDSI__OE_SEL0) 
#define M_MOSI_PRTDSI__OE_SEL1        (* (reg8 *) M_MOSI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define M_MOSI_PRTDSI__OUT_SEL0       (* (reg8 *) M_MOSI__PRTDSI__OUT_SEL0) 
#define M_MOSI_PRTDSI__OUT_SEL1       (* (reg8 *) M_MOSI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define M_MOSI_PRTDSI__SYNC_OUT       (* (reg8 *) M_MOSI__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(M_MOSI__SIO_CFG)
    #define M_MOSI_SIO_HYST_EN        (* (reg8 *) M_MOSI__SIO_HYST_EN)
    #define M_MOSI_SIO_REG_HIFREQ     (* (reg8 *) M_MOSI__SIO_REG_HIFREQ)
    #define M_MOSI_SIO_CFG            (* (reg8 *) M_MOSI__SIO_CFG)
    #define M_MOSI_SIO_DIFF           (* (reg8 *) M_MOSI__SIO_DIFF)
#endif /* (M_MOSI__SIO_CFG) */

/* Interrupt Registers */
#if defined(M_MOSI__INTSTAT)
    #define M_MOSI_INTSTAT            (* (reg8 *) M_MOSI__INTSTAT)
    #define M_MOSI_SNAP               (* (reg8 *) M_MOSI__SNAP)
    
	#define M_MOSI_0_INTTYPE_REG 		(* (reg8 *) M_MOSI__0__INTTYPE)
#endif /* (M_MOSI__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_M_MOSI_H */


/* [] END OF FILE */
