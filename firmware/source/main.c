
#include "common.h"
#include "util.h"
#include "io.h"
#include "spi_util.h"
#include "rfm12.h"
#include "motor.h"
#include "controller.h"


// Select Internal FRC at POR
_FOSCSEL(FNOSC_FRCPLL);
// Enable Clock Switching and Configure
_FOSC(FCKSM_CSECMD & OSCIOFNC_ON & IOL1WAY_OFF);
// Disable watchdog timer
_FWDT(FWDTEN_OFF);

int main(void)
{
    // initialize all peripherals/modules
    clock_init();
    periph_disable_all();
    spi_init();
    io_init();
    RFM12_init();
    motor_init();
    //stick_init();
    heartbeat_init();
    
    while (1)
    {
        //drive();
        digitalio_test();
    }

    return 0;
}


uint8_t dev_id = 0;

void trx()
{

    uint8_t txbuf[] = {0, 0, 1, 0, 0, 0, 0, 1};
    uint8_t rxbuf[8];
    uint8_t i;
    bool rx_good = 1;

    // transmit message
    delay_ms(1000);
    if (dev_id == 0)
    {
        RFM12_TxData(txbuf, sizeof (txbuf));
        heartbeat_toggle();
    }
    else if (dev_id == 1)
    {
        RFM12_RxData(rxbuf, 8);

        for (i = 0; i < 8; i++)
        {
            if (txbuf[i] != rxbuf[i])
            {
                rx_good = 0;
                break;
            }
        }
        if (rx_good)
        {
            heartbeat_toggle();
        }
    }

}
