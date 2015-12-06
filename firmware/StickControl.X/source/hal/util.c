
#include "util.h"

#include <pps.h>
#include <timer.h>

#include "../bsp/bsp.h"


void __attribute__((optimize("O0"))) delay_ms(uint32_t count)
{
    delay_us(count * 1030);
}

void __attribute__((optimize("O0"))) delay_us(uint32_t count)
{
    // NOTE: Multiply by ~3.5 to convert count value to us (microsecond) value
    // This multiplier is very specific to this chip (based on operating frequency, instruction architecture, etc.)
    // NOTE: 3.5 x count = (4 * count) - (count / 2) -> use shift operations instead of multiply
    count = (count << 2) - (count >> 1);
    while (count > 0)
    {
        count--;
    }
}

void __attribute__((optimize("O0"))) delay_ns(uint32_t count)
{
    // NOTE: can't delay less than ~760ns due to hardware limitations (IOPS)
    if (count > 800)
    {
        delay_us((count / 1000) + 1);
    }
}

/* force toggle heartbeat led */
void heartbeat_toggle()
{
    HEARTBEAT_LAT = !HEARTBEAT_LAT;
}

/* Enable HeartBeat Timer Interrupt and set its Priority to level 6 (lowest) */
const float heartbeat_rate = 250e-3;
void heartbeat_init()
{
    HEARTBEAT_TRIS = 0;
    uint16_t match_val = (FCY / 256) * heartbeat_rate;

    ConfigIntTimer1(T1_INT_PRIOR_6 & T1_INT_ON);
    WriteTimer1(0);
    OpenTimer1(T1_ON & T1_GATE_OFF & T1_IDLE_STOP &
               T1_PS_1_256 & T1_SYNC_EXT_OFF &
               T1_SOURCE_INT, match_val);
}

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void)
{
    HEARTBEAT_LAT = !HEARTBEAT_LAT;
    WriteTimer1(0);
    _T1IF = 0;
}
