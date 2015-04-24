#ifndef ANALOGIN_H
#define ANALOGIN_H

#include "common.h"

#define A0_mode _TRISA0
#define A0_read _RA0
#define A0_write _LATA0

#define A1_mode _TRISA1
#define A1_read _RA1
#define A1_write _LATA1

#define A2_mode _TRISA2
#define A2_read _RA2
#define A2_write _LATA2

#define A3_mode _TRISA3
#define A3_read _RA3
#define A3_write _LATA3

#define A4_mode _TRISA4
#define A4_read _RA4
#define A4_write _LATA4

#define A5_mode _TRISB2
#define A5_read _RB2
#define A5_write _LATB2

#define A6_mode _TRISB3
#define A6_read _RB3
#define A6_write _LATB3

#define A7_mode _TRISB4
#define A7_read _RB4
#define A7_write _LATB4


void aio_init();
void adc_init();
void dma_init();

#define ADC_NCHAN 8
#define ADC_RES 4096


// read analog sample from given channel
float aio_read(uint8_t chan);

#endif
