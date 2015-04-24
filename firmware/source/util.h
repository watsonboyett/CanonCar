#ifndef INIT_H
#define INIT_H

#include "common.h"

#define Fcy (40e6)
void clock_init();
void periph_disable_all();

#define HEARTBEAT_TRIS _RA0
#define HEARTBEAT_LAT _LATA0
void heartbeat_init();
void heartbeat_toggle();

void delay_ns(uint32_t count);
void delay_us(uint32_t count);
void delay_ms(uint32_t count);
void delay(uint32_t count);

#define cycles_per_us() ( Fcy / 1000000L )
#define cycles_to_us(a) ( (a) / cycles_per_us() )
#define us_to_cycles(a) ( (a) * cycles_per_us() )

#endif
