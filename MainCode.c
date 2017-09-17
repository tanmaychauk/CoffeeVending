#include"myTypeDef.h"
#include<htc.h>
#include<pic.h>
#include <eeprom_routines.h>

//#include<xc.h>



#include"lcd.h"
#include"EEPROM_ReadWrite.h"
#include"ADC.h"
#include"timer0.h"
#include"timer2.h"
#include"CommonDeclarations.h"
#include"PORTB_Config.h"


// CONFIG
__CONFIG(BORDIS & WDTDIS & LVPDIS & HS & PWRTEN & DEBUGDIS);



void default_initialisations();
void peripheral_initialsation();
void default_bootSequence();
void isItFirstTime();

//void timerFunction() {
//    lcd_writeThisCharAt(0, 0, "timerTest");
//    __delay_ms(1000);
//    initialise_timer0();
//    start_timer0();
//    while (1) {
//        if (flag_T0_TenSecond == 1) {
//            lcd_writeThisCharAt(1, 0, '*');
//            __delay_ms(100);
//        } else {
//            lcd_clear();
//        }
//    }
//}

void main(void) {
    int temperatureCelcius;
    default_initialisations();
    peripheral_initialsation();
    isItFirstTime();

    default_bootSequence();

    lcd_clear();
    PORTB = 0x01;

    start_timer0();

    while (1) {

        if (1 == modeOfWorking)
        {
            lcd_writeThisStringAt(0, 4, "WELCOME");
        }
        IsKeyPressed();
     
    }
}

void peripheral_initialsation() {
    lcd_init();
    initialisePortB(); //RB0 as interrupt
    enableInterrupt_RB0();
    //PeripheralInterrupt_DISABLE();
    GlobalInterrupt_ENABLE();
    initialise_timer0(); //initialise timer 0 
    // initialise_timer2();
    adc_initialise(); //initialise adc
    lcd_clear();
    isFirstTime_Settings = 0;
}

void default_initialisations() {

    ANSEL = 0x01;
    ANSELH = 0x00;

    ADCON1 = 0x80;

    TRISE = 0x00;
    TRISD = 0x00;
    TRISC = 0x00;
    TRISB = 0xF1;
    TRISA = 0x01;

    modeOfWorking = 1;
}

void default_bootSequence() {
    lcd_writeThisStringAt(0, 0, "Starting....");
    __delay_ms(1000);
}

void isItFirstTime() {
    UByte Config;

    Config = EEPROM_READ(ConfigurationSetter);
    if (0x01 != Config) {

        //lcd_writeThisStringAt(0, 0, "First Time Init");
        EEPROM_WRITE(defaultCoffeeQuantity_ADDR, DefaultCoffeeQuantity_value);
        __delay_ms(100);
        EEPROM_WRITE(defaultWaterQuantityForCoffee_ADDR, DefaultWaterQuantity_forCoffee_value);
        __delay_ms(100);
        EEPROM_WRITE(defaultTeaQuantity_ADDR, DefaultTeaQuantity_value);
        __delay_ms(100);
        EEPROM_WRITE(defaultWaterQuantityForTea_ADDR, DefaultWaterQuantity_forTea_value);
        __delay_ms(100);
        EEPROM_WRITE(currentCoffeeQuantity_ADDR, DefaultCoffeeQuantity_value);
        __delay_ms(100);
        EEPROM_WRITE(currentWaterQuantityForCoffee_ADDR, DefaultWaterQuantity_forCoffee_value);
        __delay_ms(100);
        EEPROM_WRITE(currentTeaQuantity_ADDR, DefaultTeaQuantity_value);
        __delay_ms(100);
        EEPROM_WRITE(currentWaterQuantityForTea_ADDR, DefaultWaterQuantity_forTea_value);
        __delay_ms(100);


        CurrentCoffeeQuantity = DefaultCoffeeQuantity_value;
        CurrentWaterQuantity_forCoffee = DefaultWaterQuantity_forCoffee_value;
        CurrentTeaQuantity = DefaultTeaQuantity_value;
        CurrentWaterQuantity_forTea = DefaultWaterQuantity_forTea_value;

        EEPROM_WRITE(ConfigurationSetter, 0x01);


        __delay_ms(100);
    } else if (0x01 == Config) {

       // lcd_writeThisStringAt(0, 0, "Fetching Config");
        CurrentCoffeeQuantity = EEPROM_READ(currentCoffeeQuantity_ADDR);
        CurrentWaterQuantity_forCoffee = EEPROM_READ(currentWaterQuantityForCoffee_ADDR);
        CurrentTeaQuantity = EEPROM_READ(currentTeaQuantity_ADDR);
        CurrentWaterQuantity_forTea = EEPROM_READ(currentWaterQuantityForTea_ADDR);


    }

}