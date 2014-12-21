

#include <p24Hxxxx.h>
//#include <Generic.h>
//#include <ports.h>
#include <pps.h>
#include <timer.h>

#include "util.h"



/* set clock parameters */
void clock_init() {
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD = 41; // M = 43
    CLKDIVbits.PLLPOST = 0; // N1 = 2
    CLKDIVbits.PLLPRE = 0; // N2 = 2
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    //__builtin_write_OSCCONH(0x01);
    //__builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1) {
    };
}

/* disable all peripherals */
void periph_killall() {
    // reset all port pins directions
    TRISA = 0b0000000000000000;
    TRISB = 0b0000000000000000;

    // Initialize outputs to 0
    PORTA = 0b0000000000000000;
    PORTB = 0b0000000000000000;

    // disable all open-drain pin configurations
    ODCA = 0b0000000000000000;
    ODCB = 0b0000000000000000;


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


void delay_ns(unsigned long count) {
    count = count * Fcy * 1e-9;
    delay(count);
}

void delay_us(unsigned long count) {
    count = count * Fcy * 1e-6;
    delay(count);
}

void delay_ms(unsigned long count) {
    count = count * Fcy * 1e-3;
    delay(count);
}

void delay(unsigned long count) {
    count = count / 11;
    while (count > 0) {
        count--;
    }
}

/* force toggle heartbeat led */
void blink_flip() {
    HEART_LAT = !HEART_LAT;
}

/* Enable HeartBeat Timer Interrupt and set its Priority to level 6 (lowest) */
void blink_init() {
    HEART_TRIS = 0;

    unsigned int match_value = (Fcy / 256) * 300e-3;

    ConfigIntTimer1(T1_INT_PRIOR_6 & T1_INT_ON);
    WriteTimer1(0);
    OpenTimer1(T1_ON & T1_GATE_OFF & T1_IDLE_STOP &
            T1_PS_1_256 & T1_SYNC_EXT_OFF &
            T1_SOURCE_INT, match_value);
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {
    // toggle heartbeat LED
    HEART_LAT = !HEART_LAT;

    // reset timer and clear Timer interrupt flag
    WriteTimer1(0);
    _T1IF = 0; 
}



