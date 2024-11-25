//----------------------------------------------------------------------------
//
//	SIMPLE SDR RECEIVER PSoC3 FIRMWARE for Hardware Rev -
//
//	Copyright 2011 Simple Circuits Inc.
//
//	06/03/2011	Version 00, Original release.
//
//----------------------------------------------------------------------------
//
// PSoC3 => PSoC5LP
//
//  Sumio Koseki (JA7RHK)
//	05/28/2017
//
//----------------------------------------------------------------------------
#include <device.h>

#define	VERSION		"DSH:S 0000"		// displays as "H:S 0000" on display read cmd

// PSoC3 => PSoC5LP
#define FALSE  0
#define TRUE   1

#define USBUART 1       // USBUART interface is enabled

//----------------------------------------------------------------------------
//
//	Constants and Definitions
//
//----------------------------------------------------------------------------
#define	MODE_LSB		0				// operating modes
#define	MODE_USB		1
#define	MODE_CW			2
#define	MODE_RTTY		5
#define	MODE_CWREV		6
#define	MODE_RTTYREV	8

#define	FILTER_FL1		0				// receive filters
#define	FILTER_FL2		1
#define	FILTER_FL3		2
#define	FILTER_FL4		3
#define	FILTER_AM		4				// LPF for AM station (2017.6.1)koseki
#define	FILTER_RST		5               // reset filter 

#define	LED_BLINK		25				// 200 msec LED blink
#define	LED_SHORTBLINK	3				// 24 msec LED blink

#define CR				13				// ASCII carriage return


//----------------------------------------------------------------------------
//
//	EEprom Storage Definitions
//
//----------------------------------------------------------------------------
#define	SN_ROW				0			// serial number in eeprom row 0
#define	FQ_ROW				1			// frequency offset in eeprom row 1


//----------------------------------------------------------------------------
//
//	Elecraft K2 serial commands
//
//----------------------------------------------------------------------------
#define	CMD_AI		0x4149				// K2 PowerSDR remote commands
#define	CMD_AN		0x414E
#define	CMD_BG		0x4247
#define	CMD_DS		0x4453
#define	CMD_FA		0x4641
#define	CMD_FB		0x4642
#define	CMD_FR		0x4652
#define	CMD_FT		0x4654
#define	CMD_FW		0x4657
#define	CMD_GT		0x4754
#define	CMD_ID		0x4944
#define	CMD_IF		0x4946
#define	CMD_K2		0x4B32
#define	CMD_KS		0x4B53
#define	CMD_LK		0x4C4B
#define	CMD_MD		0x4D44
#define	CMD_NB		0x4E42
#define	CMD_PA		0x5041
#define	CMD_PC		0x5043
#define	CMD_PS		0x5053
#define	CMD_RA		0x5241
#define	CMD_SQ		0x5351


//----------------------------------------------------------------------------
//
//	Function Prototypes
//
//----------------------------------------------------------------------------
void AdjustAgc (void);
void ReadUSB (void);
void ChannelSet(uint8);
void LoadFilter (uint8);
void SetFrequency (void);
void SetMode (uint8);
uint32 BinaryFrequency (uint8 *);
void FactorySetup (void);
void Initialize (void);
void ProcessComRx (void);
CY_ISR(ADC_ISR_Handler);
