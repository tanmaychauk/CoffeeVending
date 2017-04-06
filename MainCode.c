

#include"myTypeDef.h"
#include<htc.h>
#include<pic.h>

//#include<xc.h>



#include"lcd.h"
#include"EEPROM_ReadWrite.h"
#include"ADC.h"
#include"timer0.h"
#include"CommonDeclarations.h"
#include"PORTB_Config.h"


// CONFIG
__CONFIG(BORDIS & WDTDIS & LVPDIS & HS & PWRTEN & DEBUGDIS);



void default_initialisations();
void peripheral_initialsation();
void default_bootSequence();
void isItFirstTime();

void main(void) {
    default_initialisations();
    peripheral_initialsation();
    isItFirstTime();
    default_bootSequence();

    lcd_clear();

    // start_timer0();

    while (1)
    {
        PORTB = 0x01;
        if (1 == modeOfWorking)
        {
            lcd_writeThisStringAt(0, 4, "WELCOME");
        }
        IsKeyPressed();
        /*
        if(flag_T0_TenSecond == 1)
        {
            checkSensorValues();
        }
         */
    }
}

void peripheral_initialsation() {
    lcd_init();
    initialisePortB(); //RB0 as interrupt
    enableInterrupt_RB0();
    PeripheralInterrupt_DISABLE();
    GlobalInterrupt_ENABLE();
    //initialise_timer0();          //initialise timer 0 
    //adc_initialise();             //initialise adc


}

void default_initialisations() {
    ADCON1 = 0x06;
    TRISE = 0x00;
    TRISD = 0x00;
    TRISB = 0x01;
    TRISA = 0x00;
    
    PORTB = 0x01;


    modeOfWorking = 1;
}

void default_bootSequence() {
    lcd_writeThisStringAt(0, 0, "Starting....");
    __delay_ms(1000);
}

void isItFirstTime() {
    if (0x00 == EEPROM_READ(ConfigurationSetter)) {

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
    }
}