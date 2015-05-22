#ifndef INIT_H
#define INIT_H

#include "common.h"

#define Fcy (40e6)
void clock_init();
void periph_disable_all();

#define HEARTBEAT_TRIS _TRISA0
#define HEARTBEAT_LAT _LATA0
void heartbeat_init();
void heartbeat_toggle();

void __attribute__((optimize("O0"))) delay(uint32_t count);
void __attribute__((optimize("O0"))) delay_ns(uint32_t count);
void __attribute__((optimize("O0"))) delay_us(uint32_t count);
void __attribute__((optimize("O0"))) delay_ms(uint32_t count);

#define cycles_per_us() ( Fcy / 1000000L )
#define cycles_to_us(a) ( (a) / cycles_per_us() )
#define us_to_cycles(a) ( (a) * cycles_per_us() )

#endif
