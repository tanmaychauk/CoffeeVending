#include"ADC.h"

void adc_initialise()
{
    ADCON0 = 0x00;//(FOSC/2),((channel 0),(A/D conversion disable),(ADC module off)
    ADCON1 = 0x8E;//(right Justified),(FOSC/2),(Channel 0 as Analog input,others as digital),
    
}

UWord adc_getValue()
{
    ADON = 1;       //Enable ADC module
    
    UWord adcValue = 0;
    
    ADGO = 1;       //start converter
    while(ADGO);    //ADC conversion in progress
    adcValue = (ADRESH<<8) + ADRESL ;
    
    ADON = 0;       //disable ADC module
    return adcValue; 
}
