#ifndef INIT_H
#define INIT_H

#include "types.h"

#define Fcy (40e6)


#define HEART_TRIS _RA0
#define HEART_LAT _LATA0


void clock_init();
void periph_killall();
void blink_init();
void blink_flip();


void delay_ns(uint32 count);
void delay_us(uint32 count);
void delay_ms(uint32 count);
void delay(uint32 count);

#endif
