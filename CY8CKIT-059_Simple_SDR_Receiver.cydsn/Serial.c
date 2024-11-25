//----------------------------------------------------------------------------
//
//	SIMPLE SDR RECEIVER PSoC3 FIRMWARE for Hardware Rev -
//
//	Copyright 2011 Simple Circuits Inc.
//
//	06/03/2011	Original release.
//
//----------------------------------------------------------------------------
//  (2017.9.12) JA7RHK
//  modified for PSoC5LP
//
#include <device.h>
#include <string.h>
#include "main.h"
// PSoC3 => PSoC5LP
#include "USBUART_FIFO.h"
#include <stdlib.h>
#include <stdio.h>

//----------------------------------------------------------------------------
//
//	Global variables
//
//----------------------------------------------------------------------------
extern uint8	ComRxCmd [32];				// remote command rx buffer
extern uint8	UsbTxBuffer [64];
extern uint8	ComRxPtr;					// pointer into com rx buffer

extern uint8	Freq [8];					// frequency in ASCII BCD
extern int32	Frequency;					// receive frequency in binary

extern uint8	LedTimer;					// LED on timer
extern uint8	DisplayIndex;				// index for status display

extern uint8	AgcDisable;					// Agc disable flag
extern uint8	AgcGain;					// AGC for ADC input, power of 2 scaling factor
extern uint8	AgcIntegrator;				// AGC integrator
extern uint8	AgcTimeConstant;            // AGC time constant
extern uint8	Mode;						// operating mode
extern uint8	Filter;						// audio filter bandwidth
extern uint8	AttenuatorOn;				// rx attenuator on/off flag
extern uint8	Squelch;					// squelch level, 0 - 250.

extern const uint8 FREQ_ERROR[8];			// freq offset is 1st row of eeprom
extern const uint8 SERIAL_NUM[8];			// serial number is 2nd row of eeprom

//----------------------------------------------------------------------------
//
//	SERIAL ROUTINES
//
//----------------------------------------------------------------------------

//
//	Process com rx commands
//
void ProcessComRx (void)
{
#define GET_CMD		(ComRxCmd [2] == ';')
	uint8	i;
	uint8	sendUsb = FALSE;
    char    str[8];
	
	switch ((ComRxCmd [0] * 256) + ComRxCmd [1])
	{
		case CMD_AI:					// auto-information, make always mode 0
			if (GET_CMD)
			{
				sendUsb = 4;			// flag to send response
				memcpy (UsbTxBuffer, "AI0;", sendUsb);
			}
			break;

		case CMD_AN:					// antenna select, always 1
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "AN1;", sendUsb);
			}
			break;

		case CMD_BG:					// bar graph, return BG12 thru BG22
			sendUsb = 5;
			i = AgcGain / 6;			// 64 >= AgcGain >= 0, 10 >= i >= 0
			i = (10 - i) + 12;			// between 22 and 12.
			memcpy (UsbTxBuffer, "BG12;", sendUsb);
			UsbTxBuffer [2] = (i / 10) + '0';	// either '1' or '2'
			UsbTxBuffer [3] = (i % 10) + '0';	// '0' thru '9'
			break;

		case CMD_DS:					// display read
			sendUsb = 13;
			DisplayIndex++;
			DisplayIndex %= 12;
			if (DisplayIndex < 4)		// display version info
				memcpy (UsbTxBuffer, VERSION, 10);
			else if (DisplayIndex < 8)
			{
				memcpy (UsbTxBuffer, "DSSN ", 5);
				memcpy (&UsbTxBuffer [5], &SERIAL_NUM [3], 5);
			}
			else
			{
				memcpy (UsbTxBuffer, "DSFR ", 5);
				memcpy (&UsbTxBuffer [5], &FREQ_ERROR [3], 5);
			}
			UsbTxBuffer [10] = UsbTxBuffer [11] = 0x80;
			UsbTxBuffer [12] = ';';
			break;
		
		case CMD_FA:					// set/get frequency
			if (GET_CMD)
			{
				sendUsb = 14;
				memcpy (UsbTxBuffer, "FA00000000000;", sendUsb);
				memcpy (&UsbTxBuffer [5], Freq, 8);
			}
			else
			{
				memcpy (Freq, &ComRxCmd [5], 8);
				SetFrequency ();		// set new frequency
			}
			break;

		case CMD_FB:					// no VFO B to set/get
			if (GET_CMD)
			{
				sendUsb = 14;
				memcpy (UsbTxBuffer, "FB00000000000;", sendUsb);
			}
			break;

		case CMD_FR:					// no receive split mode, always 0
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "FR0;", sendUsb);
			}
			break;

		case CMD_FT:					// no transmit split mode, always 0
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "FT0;", sendUsb);
			}
			break;

		case CMD_FW:					// filter bandwidth
			if (GET_CMD)
			{
				sendUsb = 9;
				if (Filter == FILTER_FL1)
					memcpy (UsbTxBuffer, "FW250010;", sendUsb);
				else if (Filter == FILTER_FL2)
					memcpy (UsbTxBuffer, "FW200020;", sendUsb);
				else if (Filter == FILTER_FL3)
					memcpy (UsbTxBuffer, "FW150030;", sendUsb);
				else if (Filter == FILTER_FL4)
					memcpy (UsbTxBuffer, "FW100040;", sendUsb);
				else if (Filter == FILTER_AM)
					memcpy (UsbTxBuffer, "FW380050;", sendUsb);   // 2017.11.4(koseki)
			}
			else
			{
				Filter = ComRxCmd [6] - '1';
				if (Filter > FILTER_RST)
					Filter = FILTER_FL1;
				LoadFilter (Filter);
			}
			break;

		case CMD_GT:					// AGC time constant, slow, on/off
			if (GET_CMD)
			{
				sendUsb = 7;
				//memcpy (UsbTxBuffer, "GT0040;", sendUsb);
                sprintf(str, "GT%03d0;", AgcTimeConstant);
				memcpy (UsbTxBuffer, str, sendUsb);
				UsbTxBuffer [5] = (AgcDisable) ? '0' : '1';
			}
			else
            {
                AgcTimeConstant = ComRxCmd [4] - '0';
                AgcDisable = (ComRxCmd [5] == '0');
			}
            break;

		case CMD_ID:					// K2 ID number
			sendUsb = 6;
			memcpy (UsbTxBuffer, "ID017;", sendUsb);
			break;

		case CMD_IF:					// radio info
			sendUsb = 35;
			memcpy (UsbTxBuffer, "IF00000000000     +00000001000001 ;", sendUsb);
			memcpy (&UsbTxBuffer [5], Freq, 8);
			break;

		case CMD_K2:					// meta-command
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "K22;", sendUsb);
			}
			break;

		case CMD_KS:					// keyer speed, not used
			if (GET_CMD)
			{
				sendUsb = 6;
				memcpy (UsbTxBuffer, "KS009;", sendUsb);
			}
			break;

		case CMD_LK:					// VFO lock, always unlocked
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "LK0;", sendUsb);
			}
			break;

		case CMD_MD:					// operating mode
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "MD1;", sendUsb);
				UsbTxBuffer [2] = Mode + '1';	// Mode = 0 - 9
			}
			else
            {
				SetMode (ComRxCmd [2] - '1');	// map Mode to 0 - 9
                LoadFilter (Filter);
            }   
			break;

		case CMD_NB:					// noise blanker mode, extended
			if (GET_CMD)
			{
				sendUsb = 5;
				memcpy (UsbTxBuffer, "NB01;", sendUsb);
			}
#ifdef PSoC3            
			else if (!memcmp (Freq, "10101010", 8))	// special frequency test
				CyBtldr_Load();			// enter USB boot loader mode
			else
			{
				Clock_FracN_SetDividerValue (10);	// unlock and reloack PLL
				CyDelay (100);						// delay in msec
				Clock_FracN_SetDividerValue (9);
			}
#endif
            break;

		case CMD_PA:					// rx preamp, always off
			if (GET_CMD)
			{
				sendUsb = 4;
				memcpy (UsbTxBuffer, "PA0;", sendUsb);
			}
			break;

		case CMD_PC:					// power output level
			if (GET_CMD)
			{
				sendUsb = 7;
				memcpy (UsbTxBuffer, "PC0000;", sendUsb);
			}
			break;

		case CMD_PS:					// radio power status, always on
			sendUsb = 4;
			memcpy (UsbTxBuffer, "PS1;", sendUsb);
			break;

		case CMD_RA:					// rx attenuator, 0 = off, 1 = on
			if (GET_CMD)
			{
				sendUsb = 5;
				memcpy (UsbTxBuffer, "RA00;", sendUsb);
				UsbTxBuffer [3] = (AttenuatorOn) ? '1' : '0';
			}
			else
			{
				AttenuatorOn = (ComRxCmd [3] == '1');
				AgcGain = AgcIntegrator = 0;	// mute the input signal during ADC range changes
				ADC_SetBufferGain ( (AttenuatorOn) ? 1 : 4 );
			}	
			break;
							
		case CMD_SQ:					// squelch, 0 2 250.
			if (GET_CMD)
			{
				sendUsb = 6;
				memcpy (UsbTxBuffer, "SQ000;", sendUsb);
				i = Squelch;
				UsbTxBuffer [2] = (i / 100) + '0';	// hundreds
				i = i % 100;
				UsbTxBuffer [3] = (i / 10) + '0';	// tens
				UsbTxBuffer [4] = (i % 10) + '0';	// units
			}
			else
			{
				Squelch = 100 * (ComRxCmd [2] - '0');
				Squelch += 10 * (ComRxCmd [3] - '0');
				Squelch += ComRxCmd [4] - '0';
			}
			break;
	}

	if (sendUsb)
	{
#ifdef PSoC3 // original code
		USBUART_Write(UsbTxBuffer, sendUsb);	// send response
#else
        UsbTxBuffer [sendUsb] = '\0';   // 2017.11.4(koseki)
        putstr((char*)UsbTxBuffer);
        putch('\n');
#endif
    }
}
