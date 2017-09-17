#include <pic16f887.h>

#include"ADC.h"
#include "lcd.h"
#include "CommonDeclarations.h"

void adc_initialise() {
    ADCON0 = 0x00; //(FOSC/2),((channel 0),(A/D conversion disable),(ADC module off)
    ADCON1 = 0x80; //(right Justified),(FOSC/2),(Channel 0 as Analog input,others as digital),
    //ANSEL = 0xFF;
}

int adc_getValue() 
{

    ADON = 1; //Enable ADC module

    int adcValue = 0;
    int temp = 0;
        
    GODONE = 1; //start converter
    while (GODONE); //ADC conversion in progress
    
    adcValue = (ADRESH << 8) + ADRESL;
        
    //temp = (5 * adcValue * 100) / 1024;
            
    ADON = 0; //disable ADC module
    
    return adcValue;
}

void print_ADCValue(int adcValue) {
    
    UByte data[5] = {'0', '0', '0', '0', '\0'};
    //adcValue = (5 * adcValue * 100) / 1024;
    
    data[3] = (adcValue % 10) + 0x30;
    adcValue = adcValue / 10;

    data[2] = (adcValue % 10) + 0x30;
    adcValue = adcValue / 10;

    data[1] = (adcValue % 10) + 0x30;
    adcValue = adcValue / 10;

    data[0] = (adcValue % 10) + 0x30;
    adcValue = adcValue / 10;

    lcd_writeThisStringAt(1,0,data);
    //lcd_puts(data);
}


void readADCvalue()
{
    int temp;
    temp = adc_getValue();
    print_ADCValue(temp);
    __delay_ms(200);
    
}