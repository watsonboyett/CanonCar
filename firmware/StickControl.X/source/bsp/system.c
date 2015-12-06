/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include "device.h"

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */
#include <pps.h>

#include "system.h"          /* variables/params used by system.c */

/******************************************************************************/
/* System Level Functions                                                     */
/*                                                                            */
/* Custom oscillator configuration functions, reset source evaluation          */
/* functions, and other non-peripheral microcontroller initialization         */
/* functions get placed in system.c                                           */
/*                                                                            */
/******************************************************************************/

/* Refer to the device Family Reference Manual Oscillator section for
information about available oscillator configurations.  Typically
this would involve configuring the oscillator tuning register or clock
switching using the compiler's __builtin_write_OSCCON functions.
Refer to the C Compiler for PIC24 MCUs and dsPIC DSCs User Guide in the
compiler installation directory /doc folder for documentation on the
__builtin functions. */

/* TODO Add clock switching code if appropriate.  An example stub is below.   */
void ConfigureOscillator(void)
{

#if 0

        /* Disable Watch Dog Timer */
        RCONbits.SWDTEN = 0;

        /* When clock switch occurs switch to Prim Osc (HS, XT, EC)with PLL */
        __builtin_write_OSCCONH(0x03);  /* Set OSCCONH for clock switch */
        __builtin_write_OSCCONL(0x01);  /* Start clock switching */
        while(OSCCONbits.COSC != 0b011);

        /* Wait for Clock switch to occur */
        /* Wait for PLL to lock, if PLL is used */
        /* while(OSCCONbits.LOCK != 1); */

#endif
        
}


/* set clock parameters */
void clock_init()
{
    // Configure PLL pre-scaler, PLL post-scaler, PLL divisor
    PLLFBD = 41; // M = 43
    CLKDIVbits.PLLPOST = 0; // N1 = 2
    CLKDIVbits.PLLPRE = 0; // N2 = 2
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    //__builtin_write_OSCCONH(0x01);
    //__builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1)
    {
    };
}

/* disable all peripherals */
void periph_disable_all()
{
    // reset all port pins directions
    TRISA = 0xFF;
    TRISB = 0xFF;

    // Initialize outputs to 0
    PORTA = 0x00;
    PORTB = 0x00;

    // disable all open-drain pin configurations
    ODCA = 0b0000000000000000;
    ODCB = 0b0000000000000000;

    // disable all pull-ups
    CNPU1 = 0b0000000000000000;
    CNPU2 = 0b0000000000000000;

    // disable all peripherals
    PPSUnLock;
    PMCONbits.PMPEN = 0;
    PMCONbits.PTWREN = 0;
    PMCONbits.PTRDEN = 0;
    U1MODEbits.UARTEN = 0;
    SPI1STATbits.SPIEN = 0;
    SPI2STATbits.SPIEN = 0;
    I2C1CONbits.I2CEN = 0;
    CVRCONbits.CVREN = 0;
    CVRCONbits.CVROE = 0;
    CMCONbits.C1EN = 0;
    CMCONbits.C2EN = 0;
    AD1CON1bits.ADON = 0;
    PPSLock;
}
