

#ifndef _RFM12CONF_H
#define _RFM12CONF_H

/*---------------------------------------------------------------------------*/
/* Configuration for Microchip x8 Compiler                                  */
/*---------------------------------------------------------------------------*/
#if defined(__18CXX)
#include <p18cxxx.h>

/* set I/O direction for pins used for controlling RFM12 */
#define RFM12_PinInit()     LATD &= 0x1F; TRISD &= 0x1F;

/* I/O pin controll functions */
#define RFM12_ClrSCK()      LATDbits.LATD7 = 0
#define RFM12_SetSCK()      LATDbits.LATD7 = 1
#define RFM12_ClrSDI()      LATDbits.LATD6 = 0
#define RFM12_SetSDI()      LATDbits.LATD6 = 1
#define RFM12_ClrNSEL()     LATDbits.LATD5 = 0
#define RFM12_SetNSEL()     LATDbits.LATD5 = 1
#define RFM12_GetSDO()      PORTDbits.RD4
#define RFM12_GetIRQ()      PORTDbits.RD3


/*---------------------------------------------------------------------------*/
/* Configuration for Microchip x16 Compiler                                  */
/*---------------------------------------------------------------------------*/
#elif defined(__PIC24H__)
#include <p24Hxxxx.h>



#endif



#endif /* #define _RFM12CONF_H */

