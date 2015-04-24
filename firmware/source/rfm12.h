/*** FILEHEADER ****************************************************************
 *
 *    FILENAME:    rfm12.h
 *    DATE:        31.10.2010
 *    AUTHOR:      (c) Christian Stadler
 *
 *    DESCRIPTION: Driver for RFM12 wireless tranceiver module.
 *
 ******************************************************************************/

/*** HISTORY OF CHANGE *********************************************************
 *
 *    $Log: /pic/_drv/rfm12.h $
 * 
 * 2     1.11.10 11:50 Stadler
 * - adaptions for Microchip C18 compiler
 * 
 * 1     31.10.10 14:45 Stadler
 * - RFM12 tranceiver module driver
 * 
 ******************************************************************************/

#ifndef _RFM12_H
#define _RFM12_H

/* common data type definitions */
#include "common.h"

/* RFM12 configuration, to be created by the user */
#include "rfm12conf.h"


// DIO chip select pin
#define RFM12_CS_TRIS TRISBbits.TRISB14
#define RFM12_CS PORTBbits.RB14
// DIO interrupt pin
#define RFM12_INT_TRIS TRISBbits.TRISB15
#define RFM12_INT PORTBbits.RB15


/* I/O pin controll functions */
#define RFM12_ClrSCK()      LATBbits.LATB9 = 0
#define RFM12_SetSCK()      LATBbits.LATB9 = 1
#define RFM12_ClrSDI()      LATBbits.LATB10 = 0
#define RFM12_SetSDI()      LATBbits.LATB10 = 1
#define RFM12_ClrNSEL()     LATBbits.LATB14 = 0
#define RFM12_SetNSEL()     LATBbits.LATB14 = 1
#define RFM12_GetSDO()      PORTBbits.RB11
#define RFM12_GetIRQ()      PORTBbits.RB15


/* macro for calculating frequency value out of frequency in MHz */
#define RFM12FREQ(freq)     ((freq-430.0)/0.0025)


uint16_t RFM12_Write(uint16_t data);
void RFM12_init(void);
void RFM12_setup(void);
void RFM12_SetBandwidth(uint8_t bandwidth, uint8_t gain, uint8_t drssi);
void RFM12_SetFreq(uint16_t freq);
void RFM12_SetBaud(uint16_t baud);
void RFM12_SetPower(uint8_t power, uint8_t mod);
void RFM12_Ready(void);
void RFM12_TxData(uint8_t *data, uint8_t length);
void RFM12_RxData(uint8_t *data, uint8_t length);


#endif /* #ifndef _RFM12_H */
