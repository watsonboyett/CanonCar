
#include <adc.h>
#include <dma.h>
#include "analogio.h"

void adc_init()
{
    DisableIntADC1();

    uint16_t cfg_AD1CON1 = ADC_MODULE_ON & ADC_IDLE_STOP & ADC_ADDMABM_ORDER &
            ADC_AD12B_12BIT & ADC_FORMAT_INTG & ADC_CLK_AUTO &
            ADC_AUTO_SAMPLING_ON & ADC_MULTIPLE & ADC_SAMP_ON;
    AD1CON1 = cfg_AD1CON1;

    uint16_t cfg_AD1CON2 = ADC_VREF_AVDD_AVSS & ADC_SCAN_ON & ADC_SELECT_CHAN_0 &
            ADC_ALT_BUF_OFF & ADC_DMA_ADD_INC_4 & ADC_ALT_INPUT_OFF;
    AD1CON2 = cfg_AD1CON2;

    uint16_t cfg_AD1CON3 = ADC_CONV_CLK_SYSTEM & ADC_SAMPLE_TIME_30 & ADC_CONV_CLK_60Tcy;
    AD1CON3 = cfg_AD1CON3;

    uint16_t cfg_AD1CON4 = ADC_DMA_BUF_LOC_1;
    AD1CON4 = cfg_AD1CON4;

    uint16_t cfg_AD1CHS123 = 0;
    AD1CHS123 = cfg_AD1CHS123;

    uint16_t cfg_AD1CHS0 = ADC_CH0_NEG_SAMPLEB_VREFN & ADC_CH0_POS_SAMPLEB_AN1 &
            ADC_CH0_NEG_SAMPLEA_NVREF & ADC_CH0_POS_SAMPLEA_AN1;
    AD1CHS0 = cfg_AD1CHS0;

    // always scan all analog inputs
    uint16_t cfg_AD1CSSL = 0;
    bit_set(cfg_AD1CSSL, get_pin_info(A0)->analog_chan);
    bit_set(cfg_AD1CSSL, get_pin_info(A1)->analog_chan);
    //bit_set(cfg_AD1CSSL, get_pin_info(A2)->analog_chan);
    //bit_set(cfg_AD1CSSL, get_pin_info(A3)->analog_chan);
    //bit_set(cfg_AD1CSSL, get_pin_info(A4)->analog_chan);
    bit_set(cfg_AD1CSSL, get_pin_info(A5)->analog_chan);
    bit_set(cfg_AD1CSSL, get_pin_info(A6)->analog_chan);
    //bit_set(cfg_AD1CSSL, get_pin_info(A7)->analog_chan);
    //bit_set(cfg_AD1CSSL, get_pin_info(A8)->analog_chan);
    //bit_set(cfg_AD1CSSL, get_pin_info(A9)->analog_chan);
    AD1CSSL = cfg_AD1CSSL;

    // initialize analog pins into digital mode
    uint16_t cfg_AD1PCFGL = ENABLE_ALL_DIG_0_15;
    AD1PCFGL = cfg_AD1PCFGL;
}


uint16_t ADC_buf[ADC_NCHAN] __attribute__((space(dma)));

void dma_init()
{
    DisableIntDMA0;

    uint16_t cfg_DMA0CON = DMA0_MODULE_ON & DMA0_SIZE_WORD & PERIPHERAL_TO_DMA0 &
            DMA0_INTERRUPT_BLOCK & DMA0_NORMAL & DMA0_REGISTER_POST_INCREMENT &
            DMA0_CONTINUOUS;
    DMA0CON = cfg_DMA0CON;

    uint16_t cfg_DMA0REQ = 13;
    DMA0REQ = cfg_DMA0REQ;

    uint16_t cfg_DMA0STA = __builtin_dmaoffset(ADC_buf);
    DMA0STA = cfg_DMA0STA;

    uint16_t cfg_DMA0PAD = &ADC1BUF0;
    DMA0PAD = cfg_DMA0PAD;

    // NOTE: dma count should be one less than number of ADC scan channels
    uint16_t cfg_DMA0CNT = 3;
    DMA0CNT = cfg_DMA0CNT;

}

void analogio_init()
{
    adc_init();
    dma_init();
}

void analogio_set_dir(PinConfig_s * pin, const PinDir_e dir)
{
    PinInfo_s * pin_info = pin->info;
    if (pin_info->analog_chan == -1)
    {
        return;
    }

    if (dir == Input)
    {
        uint16_t cfg_AD1PCFGL = AD1PCFGL;
        bit_clear(cfg_AD1PCFGL, pin_info->analog_chan);
        AD1PCFGL = cfg_AD1PCFGL;

        uint16_t tris = *(pin_info->tris);
        bit_set(tris, pin_info->bit_pos);
        *(pin_info->tris) = tris;
    }
    else if (dir == Output)
    {
        // TODO: this
    }

    pin->dir = dir;
}

uint16_t analogio_read(PinConfig_s * pin)
{
    int chan = pin->info->analog_chan;
    uint16_t value = 0;
    if (chan != -1)
    {
        value = ADC_buf[chan];
    }
    return value;
}

float analogio_read_frac(PinConfig_s * pin)
{
    return (float) analogio_read(pin) / (float) ADC_RES;
}

void analogio_write(PinConfig_s * pin, const uint16_t val)
{

}

void analogio_write_frac(PinConfig_s * pin, const float val)
{

}
