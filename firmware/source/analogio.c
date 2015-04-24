
#include <p24Hxxxx.h>
#include <adc.h>
#include <dma.h>

#include "analogio.h"
#include "util.h"

void aio_init()
{
    adc_init();
    dma_init();
}

void adc_init()
{
    uint16_t config1, config2, config3, config4;
    uint16_t configport_l, configport_h;
    uint16_t configscan_l, configscan_h;


    config1 = ADC_MODULE_ON & ADC_IDLE_STOP & ADC_ADDMABM_ORDER & ADC_AD12B_12BIT &
            ADC_FORMAT_INTG & ADC_CLK_AUTO & ADC_AUTO_SAMPLING_ON & ADC_MULTIPLE & ADC_SAMP_ON;
    config2 = ADC_VREF_AVDD_AVSS & ADC_SCAN_ON & ADC_SELECT_CHAN_0 & ADC_ALT_BUF_OFF &
            ADC_DMA_ADD_INC_3 & ADC_ALT_INPUT_OFF;
    config3 = ADC_CONV_CLK_SYSTEM & ADC_SAMPLE_TIME_30 & ADC_CONV_CLK_60Tcy;
    config4 = ADC_DMA_BUF_LOC_1;
    configport_l = ENABLE_AN1_ANA & ENABLE_AN4_ANA & ENABLE_AN5_ANA;
    configport_h = ENABLE_ALL_DIG_16_31;
    configscan_l = ~(SKIP_SCAN_AN1 & SKIP_SCAN_AN4 & SKIP_SCAN_AN5);
    configscan_h = SCAN_NONE_16_31;


    DisableIntADC1();
    _TRISA1 = 1;
    _TRISB2 = 1;
    _TRISB3 = 1;
    OpenADC1(config1, config2, config3, config4,
             configport_l, configport_h,
             configscan_h, configscan_l);
    SetChanADC1(0, ADC_CH0_NEG_SAMPLEB_VREFN & ADC_CH0_POS_SAMPLEB_AN1 &
                ADC_CH0_NEG_SAMPLEA_NVREF & ADC_CH0_POS_SAMPLEA_AN1);
}


int ADC_buf[ADC_NCHAN] __attribute__((space(dma)));

void dma_init()
{
    uint16_t config, irq, sta_address, pad_address, count;

    config = DMA0_MODULE_ON & DMA0_SIZE_WORD & PERIPHERAL_TO_DMA0 & DMA0_INTERRUPT_BLOCK &
            DMA0_NORMAL & DMA0_REGISTER_POST_INCREMENT & DMA0_CONTINUOUS;

    irq = 13;
    sta_address = __builtin_dmaoffset(ADC_buf);
    pad_address = &ADC1BUF0;
    count = 2;

    DisableIntDMA0;
    OpenDMA0(config, irq, sta_address, 0, pad_address, count);
}

float aio_read(uint8_t chan)
{
    return (float) ADC_buf[chan] / (float) ADC_RES;
}
