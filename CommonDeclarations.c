//#include <pic168xa.h>

#include"CommonDeclarations.h"
#include "PORTB_Config.h"
#include "ADC.h"
#include "timer0.h"

#define OneSecond 90
#define TenSecond 10




void GlobalInterrupt_ENABLE() {
    GIE = 1;
}

void GlobalInterrupt_DISABLE() {
    GIE = 0;
}

void PeripheralInterrupt_ENABLE() {
    PEIE = 1;
}

void PeripheralInterrupt_DISABLE() {
    PEIE = 0;
}

void interrupt ISR()
{
    if (T0IE && T0IF) {
        timer0_count++;
        if (timer0_count == OneSecond) {
            flag_T0_OneSecond = TRUE;
            timer0_count = 0;
            timer0_count10++;
        } else {
            flag_T0_OneSecond = FALSE;
        }

        if (timer0_count10 >= TenSecond) {
            flag_T0_TenSecond = TRUE;
            flag_TenSecond_main = TRUE;
            //lcd_writeThisStringAt(1,0,"yep");
            if(modeOfWorking == 1)
            {
             print_ADCValue(adc_getValue());
            }
            timer0_count10 = 0;
        } else {
            flag_T0_TenSecond = FALSE;

        }
        T0IF = 0;

    }
    //    if(TMR2IE && TMR2IF)
    //    {
    //        flagTimer2 = TRUE;
    //        TMR2IF = 0;
    //        readADCvalue();
    //        TMR2IF = 0;
    //        flagTimer2 = FALSE;
    //    }
    if (INTE && INTF) {

        disableInterrupt_RB0();
        stop_timer0();
        INTF = 0;
        buttonPressedCount = 0;

        while (!RB0 && (buttonPressedCount <= 40)) {
            buttonPressedCount++;
            __delay_ms(100);

        }
        if (buttonPressedCount >= 40) {
            lcd_clear();
            
            
            if (isFirstTime_Settings == 0) {
              //  lcd_writeThisStringAt(0, 0, "SETTINGS");
                isFirstTime_Settings = 1;
                modeOfWorking = 0;
                lcd_writeThisStringAt(0, 0, "SETTINGS_0N_I");
                __delay_ms(1000);
                InitialiseSettingMode();
            } else if (isFirstTime_Settings == 1) {
                isFirstTime_Settings = 0;
                modeOfWorking = 1;
                lcd_writeThisStringAt(0, 0, "SETTINGS_0FF_I");
                updateConfiguration();
                __delay_ms(1000);
                lcd_clear();
                lcd_writeThisStringAt(0, 4, "WELCOME");
            }

        }
        enableInterrupt_RB0();
        start_timer0();
    }

}
