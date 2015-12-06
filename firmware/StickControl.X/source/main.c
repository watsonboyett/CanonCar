
#include "bsp/bsp.h"
#include "periph/periph.h"
#include "hal/hal.h"

#include "common.h"
#include "controller.h"

void io_test()
{
    spi_init();
    io_init();

    pin_mode(A0, Digital, Output);
    pin_mode(A1, Digital, Output);
    pin_mode(A2, Digital, Input);
    pin_mode(D1, Digital, Output);
    pin_mode(D7, Digital, Input);

    bool val = 0;
    while (1)
    {
        bool A2_val = digital_read(A2);
        digital_write(A1, A2_val);

        bool D7_val = digital_read(D7);
        digital_write(D1, D7_val);

        val = !val;
        digital_write(A0, val);
        delay_ms(100);
    }
}

void motor_test()
{
    spi_init();
    io_init();
    motor_init();

    pin_mode(A0, Digital, Output);
    
    motor_set_mode(Driver1, DC);
    motor_set_current_level(Driver1, Channel1, Full);
    motor_set_dir(Driver1, Channel1, Forward);
    motor_set_current_level(Driver1, Channel2, Full);
    motor_set_dir(Driver1, Channel2, Forward);

    motor_set_mode(Driver2, DC);
    motor_set_current_level(Driver2, Channel1, Full);
    motor_set_dir(Driver2, Channel1, Forward);
    motor_set_current_level(Driver2, Channel2, Full);
    motor_set_dir(Driver2, Channel2, Forward);

    int counter = 0;
    float speed = 0.0;
    bool dir = false;
    bool val = 0;
    while (1)
    {
        dir = (counter % 2) == 0;
        speed = !((counter % 3) == 0);
        
        if (dir)
        {
            motor_set_dir(Driver1, Channel1, Forward);
            motor_set_dir(Driver1, Channel2, Forward);
            motor_set_dir(Driver2, Channel1, Forward);
            motor_set_dir(Driver2, Channel2, Forward);
        }
        else
        {
            motor_set_dir(Driver1, Channel1, Reverse);
            motor_set_dir(Driver1, Channel2, Reverse);
            motor_set_dir(Driver2, Channel1, Reverse);
            motor_set_dir(Driver2, Channel2, Reverse);
        }

        motor_set_speed(Driver1, Channel1, speed);
        motor_set_speed(Driver1, Channel2, speed);
        motor_set_speed(Driver2, Channel1, speed);
        motor_set_speed(Driver2, Channel2, speed);


        val = !val;
        digital_write(A0, val);
        delay_ms(1000);
        counter++;
    }
}

int main(void)
{
    clock_init();
    periph_disable_all();

    //io_test();
    motor_test();

    return 0;
}


uint8_t dev_id = 0;
void rf_test()
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
