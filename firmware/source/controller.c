
#include <p24Hxxxx.h>

//#include <stdio.h>
#include <math.h>

#include "controller.h"
#include "util.h"
#include "analogio.h"
#include "motor.h"

struct stick
{
    float val;
    float mid;
    float low;
    float high;
    float thr_low;
    float thr_high;
};


struct stick stick_x;
struct stick stick_y;
struct stick stick_z;

void stick_init()
{
    // wait for ADCs to buffer, then get nominal stick position
    delay_ms(1000);

    stick_x.low = 0;
    stick_x.high = 4096;
    stick_x.mid = aio_read(STICK_X_CHAN);
    stick_x.thr_low = (stick_x.mid - stick_x.low) / 5;
    stick_x.thr_high = (stick_x.high - stick_x.mid) / 5;

    stick_y.low = 0;
    stick_y.high = 4096;
    stick_y.mid = aio_read(STICK_Y_CHAN);
    stick_y.thr_low = (stick_y.mid - stick_y.low) / 5;
    stick_y.thr_high = (stick_y.high - stick_y.mid) / 5;

    stick_z.mid = aio_read(STICK_Z_CHAN);
}

void stick_update()
{
    stick_x.val = aio_read(STICK_X_CHAN);
    stick_y.val = aio_read(STICK_Y_CHAN);
    stick_z.val = aio_read(STICK_Z_CHAN);
}

void drive()
{

    unsigned int x_dir = 0;
    float x_volt = 0;
    unsigned int y_dir = 0;
    float y_volt = 0;

    stick_update();

    x_volt = stick_x.val - stick_x.mid;
    if (x_volt > stick_x.thr_high)
    {
        x_dir = 0;
        x_volt = fabs(x_volt)*2;
    }
    else if (x_volt < -stick_x.thr_low)
    {
        x_dir = 1;
        x_volt = fabs(x_volt)*2;
    }
    else
    {
        x_volt = 0;
    }
    if (x_volt > 1)
    {
        x_volt = 1.0;
    }
    motor_set_dir(1, 2, x_dir);
    motor_set_speed(1, 2, x_volt);


    y_volt = stick_y.val - stick_y.mid;
    if (y_volt > stick_y.thr_low)
    {
        y_dir = 0;
        y_volt = fabs(y_volt)*2;
    }
    else if (y_volt < -stick_y.thr_high)
    {
        y_dir = 1;
        y_volt = fabs(y_volt)*2;
    }
    else
    {
        y_volt = 0;
    }
    if (y_volt > 1)
    {
        y_volt = 1.0;
    }
    motor_set_dir(1, 1, y_dir);
    motor_set_speed(1, 1, y_volt);

}