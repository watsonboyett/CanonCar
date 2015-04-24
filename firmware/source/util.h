#ifndef INIT_H
#define INIT_H

#include "common.h"

#define Fcy (40e6)

#define HEART_TRIS _RA0
#define HEART_LAT _LATA0


void clock_init();
void periph_killall();
void blink_init();
void blink_flip();


void delay_ns(uint32_t count);
void delay_us(uint32_t count);
void delay_ms(uint32_t count);
void delay(uint32_t count);

#define clockCyclesPerMicrosecond() ( Fcy / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )



#endif
