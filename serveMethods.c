#include"serveMethods.h"

void serveCoffee() {
    lcd_writeThisStringAt(0, 0, "Serving Coffee..");

    RB1 = 1;
    __delay_ms(200);
    RB1 = 0;
    RB2 = 1;
    __delay_ms(200);
    RB2 = 0;
    RB3 = 1;
    __delay_ms(200);
    RB3 = 0;
    RB4 = 1;
    __delay_ms(200);
    RB4 = 0;


    lcd_clear();
}

void serveHalfQuantity() {
    lcd_writeThisStringAt(0, 0, "Serving Half..");
    __delay_ms(1000);
     RB4 = 1;
    __delay_ms(200);
    RB4 = 0;
    lcd_clear();
}

void serveTea() {
    lcd_writeThisStringAt(0, 0, "Serving Tea..");
    __delay_ms(1000);
       
    RB7 = 1;
    __delay_ms(200);
    RB7 = 0;
    RB6 = 1;
    __delay_ms(200);
    RB6 = 0;
    RB5 = 1;
    __delay_ms(200);
    RB5 = 0;
    RB4 = 1;
    __delay_ms(200);
    RB4 = 0;

    lcd_clear();
}

void serveHotWater() {
    lcd_writeThisStringAt(0, 0, "Serving Water..");
    __delay_ms(1000);
     RB4 = 1;
    __delay_ms(200);
    RB4 = 0;
    lcd_clear();
}
