/* 
 * File:   ADC.h
 * Author: Lenovo
 *
 * Created on March 18, 2017, 9:14 PM
 */



#include<htc.h>
//#include<xc.h>
#include <pic.h>

#include "myTypeDef.h"

void adc_initialise();
int adc_getValue();
void print_ADCValue(int adcValue);
void readADCvalue();



