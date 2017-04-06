//#include <pic168xa.h>

#include"CommonDeclarations.h"
#include "PORTB_Config.h"

#define OneSecond 90


UByte timer0_count = 0;
UByte timer0_count10 = 0;
UByte button_pressed = 0;
Boolean isFirstTime_Settings = 0;
int buttonPressedCount = 0;

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

void interrupt ISR() {
    if (TMR0IE && TMR0IF) {
        timer0_count++;
        if (timer0_count == OneSecond) {
            flag_T0_OneSecond = TRUE;
            timer0_count = 0;
            timer0_count10++;
        } else {
            flag_T0_OneSecond = FALSE;
        }
        if (timer0_count10 >= 10) {
            flag_T0_TenSecond = TRUE;
            timer0_count10 = 0;
        } else {
            flag_T0_TenSecond = FALSE;
        }
        TMR0IF = 0;
    }
    if (INTE && INTF) {


        disableInterrupt_RB0();
        INTF = 0;
        buttonPressedCount = 0;

        while (!RB0 && (buttonPressedCount <= 40)) {
            buttonPressedCount++;
            __delay_ms(100);

        }
        if (buttonPressedCount >= 40) {
            lcd_clear();

            if (isFirstTime_Settings == 0) {
                isFirstTime_Settings = 1;
                modeOfWorking = 0;
                lcd_writeThisStringAt(0, 0, "SETTINGS_0N_I");
                __delay_ms(1000);
                InitialiseSettingMode();
            } else if (isFirstTime_Settings == 1) {
                isFirstTime_Settings = 0;
                modeOfWorking = 1;
                lcd_writeThisStringAt(0, 0, "SETTINGS_0FF_I");
                __delay_ms(1000);
                lcd_clear();
                lcd_writeThisStringAt(0, 4, "WELCOME");
            }

        }
        enableInterrupt_RB0();
    }

}
