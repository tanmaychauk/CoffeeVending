#include"SettingModeHandler.h"

#define    MAX_QTY_TEA              15
#define    MAX_QTY_WATER_TEA        15
#define    MAX_QTY_COFFEE           15
#define    MAX_QTY_WATER_COFFEE     15



void InitialiseSettingMode() {
    ScreenIndex = ScreenIndex_0;
    UpdateScreen(INITIALISE);
}

void PreviousButtonHandler() {
    if (ScreenIndex_0 == ScreenIndex) {
        if (ParamIndex_TeaQty == ParameterIndex) {
            //do nothing
        } else if (ParamIndex_WaterQtyTea == ParameterIndex) {
            ParameterIndex = ParamIndex_TeaQty;
        }
    } else if (ScreenIndex_1 == ScreenIndex) {
        if (ParamIndex_WaterQtyCoffee == ParameterIndex) {
            ParameterIndex = ParamIndex_CoffeeQty;
        } else if (ParamIndex_CoffeeQty == ParameterIndex) {
            ScreenIndex = ScreenIndex_0;
            ParameterIndex = ParamIndex_WaterQtyTea;
        }
    } else if (ScreenIndex_2 == ScreenIndex) {
        ScreenIndex = ScreenIndex_1;

    }
    UpdateScreen(UPDATE);
}

void NextButtonHandler() {
    if (ScreenIndex_0 == ScreenIndex) {
        if (ParamIndex_TeaQty == ParameterIndex) {
            ParameterIndex = ParamIndex_WaterQtyTea;
        } else if (ParamIndex_WaterQtyTea == ParameterIndex) {
            ParameterIndex = ParamIndex_CoffeeQty;
            ScreenIndex = ScreenIndex_1;
        }
    } else if (ScreenIndex_1 == ScreenIndex) {
        if (ParamIndex_CoffeeQty == ParameterIndex) {
            ParameterIndex = ParamIndex_WaterQtyCoffee;
        } else if (ParamIndex_WaterQtyCoffee == ParameterIndex) {
            ScreenIndex = ScreenIndex_2;
        }

    } else if (ScreenIndex_2 == ScreenIndex) {
        //do nothing
    }


    UpdateScreen(UPDATE);
}

void UpbuttonHandler() {


    if ((ParamIndex_TeaQty == ParameterIndex) && (ScreenIndex_0 == ScreenIndex)) {
        if (CurrentTeaQuantity <= MAX_QTY_TEA) 
        {
            CurrentTeaQuantity = CurrentTeaQuantity + 1;
        }
    } else if ((ParamIndex_WaterQtyTea == ParameterIndex) && (ScreenIndex_0 == ScreenIndex)) {
        if (CurrentWaterQuantity_forTea <= MAX_QTY_WATER_TEA) {
            CurrentWaterQuantity_forTea = CurrentWaterQuantity_forTea + 1;
        }
    } else if ((ParamIndex_CoffeeQty == ParameterIndex) && (ScreenIndex_1 == ScreenIndex)) {
        if (CurrentCoffeeQuantity <= MAX_QTY_COFFEE) {
            CurrentCoffeeQuantity = CurrentCoffeeQuantity + 1;
        }
    } else if ((ParamIndex_WaterQtyCoffee == ParameterIndex) && (ScreenIndex_1 == ScreenIndex)) {
        if (CurrentWaterQuantity_forCoffee <= MAX_QTY_WATER_COFFEE) {
            CurrentWaterQuantity_forCoffee = CurrentWaterQuantity_forCoffee + 1;
        }

    } else if (ScreenIndex_2 == ScreenIndex) {
        CurrentCoffeeQuantity = DefaultCoffeeQuantity_value;
        CurrentWaterQuantity_forCoffee = DefaultWaterQuantity_forCoffee_value;
        CurrentTeaQuantity = DefaultTeaQuantity_value;
        CurrentWaterQuantity_forTea = DefaultWaterQuantity_forTea_value;
        
        lcd_writeThisStringAt(1,0,"DEFAULT UPDATED");
        __delay_ms(2000);
        lcd_writeThisStringAt(1,0,"PRESS EXIT KEY");
        __delay_ms(2000);
        break;
    }
    UpdateScreen(INITIALISE);
}

void DownButtonHandler() {
    if ((ParamIndex_TeaQty == ParameterIndex) && (ScreenIndex_0 == ScreenIndex)) {
        if (CurrentTeaQuantity >= 0) {
            CurrentTeaQuantity = CurrentTeaQuantity - 1;
        }
    } else if ((ParamIndex_WaterQtyTea == ParameterIndex) && (ScreenIndex_0 == ScreenIndex)) {
        if (CurrentWaterQuantity_forTea <= MAX_QTY_WATER_TEA) {
            CurrentWaterQuantity_forTea = CurrentWaterQuantity_forTea - 1;
        }
    } else if ((ParamIndex_CoffeeQty == ParameterIndex) && (ScreenIndex_1 == ScreenIndex)) {
        if (CurrentCoffeeQuantity <= MAX_QTY_COFFEE) {
            CurrentCoffeeQuantity = CurrentCoffeeQuantity - 1;
        }
    } else if ((ParamIndex_WaterQtyCoffee == ParameterIndex) && (ScreenIndex_1 == ScreenIndex)) {
        if (CurrentWaterQuantity_forCoffee <= MAX_QTY_WATER_COFFEE) {
            CurrentWaterQuantity_forCoffee = CurrentWaterQuantity_forCoffee - 1;
        }
    } else if (ScreenIndex_2 == ScreenIndex) {
        lcd_writeThisStringAt(1,0,"SETTINGS UPDATED");
        __delay_ms(2000);
        lcd_writeThisStringAt(1,0,"PRESS EXIT KEY");
        __delay_ms(2000);
        break;
    }
UpdateScreen(INITIALISE);
}

void UpdateScreen(Boolean Mode)
{
    lcd_clear();
    if (ScreenIndex_0 == ScreenIndex) {
        lcd_writeThisStringAt(0, 2, "TEA SETTINGS");
        if (ParamIndex_TeaQty == ParameterIndex) {
            lcd_writeThisStringAt(1, 1, "T:");
            lcd_writeThisDigit(CurrentTeaQuantity);
        } else if (ParamIndex_WaterQtyTea == ParameterIndex) {
            lcd_writeThisStringAt(1, 10, "W:");
            lcd_writeThisDigit(CurrentWaterQuantity_forTea);
        }
    }
    if (ScreenIndex_1 == ScreenIndex) {
        lcd_writeThisStringAt(0, 0, "COFFEE SETTINGS");
        if (ParamIndex_CoffeeQty == ParameterIndex) {
            lcd_writeThisStringAt(1, 0, "C:");
            lcd_writeThisDigit(CurrentCoffeeQuantity);
            
        } else if (ParamIndex_WaterQtyCoffee == ParameterIndex) {
            lcd_writeThisStringAt(1, 10, "W:");
            lcd_writeThisDigit(CurrentWaterQuantity_forCoffee);
        }
    }
    if (ScreenIndex_2 == ScreenIndex) {
        lcd_writeThisStringAt(0, 2, "SET DEFAULTS");
        lcd_writeThisStringAt(1, 2, "YES");
        lcd_writeThisStringAt(1, 10, "NO");
    }
        
    __delay_ms(3000);
}

