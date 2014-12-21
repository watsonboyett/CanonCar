

#ifndef ANALOGIN_H
#define ANALOGIN_H

#define A0_pin _RA1
#define A0 _LATA1
#define A1_pin _RB2
#define A1 _LATB2
#define A2_pin _RB3
#define A2 _LATB3

void aio_init( );
void adc_init( );
void dma_init( );

#define ADC_NCHAN 3
#define ADC_RES 4096


// read analog sample from given channel
float aio_read(unsigned int chan);

#endif

