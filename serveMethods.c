#include"serveMethods.h"

void serveCoffee() {
    lcd_writeThisStringAt(0, 0, "Serving Coffee..");

    __delay_ms(1000);
    lcd_clear();
}

void serveHalfQuantity() {
    lcd_writeThisStringAt(0, 0, "Serving Half..");
    
    __delay_ms(1000);
     lcd_clear();
}

void serveTea() {
    lcd_writeThisStringAt(0, 0, "Serving Tea..");
    
    __delay_ms(1000);
    lcd_clear();
}

void serveHotWater() {
    lcd_writeThisStringAt(0, 0, "Serving Water..");
    
    __delay_ms(1000);
    lcd_clear();
}
