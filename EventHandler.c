#include"CommonDeclarations.h"
#include"serveMethods.h"
#include"SettingModeHandler.h"

#define debouncdDelay 500
//int debouncdDelay = 1000;
Boolean isKeyPressed = 0;
UByte keyPressed = 0;

void IsKeyPressed() 
{
    keyPressed = 0;
    PORTA = 0x00;
    
    isKeyPressed = 0;

    while (isKeyPressed == FALSE && keyPressed == 0)
    {
   /*     
        if (!(1 && RB4)) {
            __delay_ms(debouncdDelay);
            if (!(1 && RB4)) {
                isKeyPressed = TRUE;
                keyPressed = 1;
            }
        }
        if (!(1 && RB5)) {
            __delay_ms(debouncdDelay);
            if (!(1 && RB5)) {
                isKeyPressed = TRUE;
                keyPressed = 2;
            }

        }
        if (!(1 && RB6)) {
            __delay_ms(debouncdDelay);
            if (!(1 && RB6)) {
                isKeyPressed = TRUE;
                keyPressed = 3;
            }

        }
        if (!(1 && RB7)) {
            __delay_ms(debouncdDelay);
            if (!(1 && RB7)) {
                isKeyPressed = TRUE;
                keyPressed = 4;
            }
        }
  
    

  */
        if (0b00000010 == PORTA) {
            __delay_ms(debouncdDelay);
            if (0b00000010 == PORTA) {
                isKeyPressed = TRUE;
                keyPressed = 1;
            }
        }
        if (0b00000100 == PORTA) {
            __delay_ms(debouncdDelay);
            if (0b00000100 == PORTA) {
                isKeyPressed = TRUE;
                keyPressed = 2;
            }

        }
        if (0b00001000 == PORTA) {
            __delay_ms(debouncdDelay);
            if (0b00001000 == PORTA) {
                isKeyPressed = TRUE;
                keyPressed = 3;
            }

        }
        if (0b00010000 == PORTA) {
            __delay_ms(debouncdDelay);
            if (0b00010000 == PORTA) {
                isKeyPressed = TRUE;
                keyPressed = 4;
            }
        }
  
    }
    
    if (isKeyPressed == TRUE)
    {
        if (0 == modeOfWorking) {
            handleEvent(keyPressed);
        } else if (1 == modeOfWorking) {
            handleEvent(keyPressed);
        }
    }

    isKeyPressed = FALSE;
    keyPressed = 0;
}

void handleEvent(UByte keyPressed) {

    lcd_clear();
    if (0 == modeOfWorking) {
      //  lcd_writeThisStringAt(0, 0, "SETTING MODE");
        SettingModeOperations(keyPressed);
    } else if (1 == modeOfWorking) {
      //  lcd_writeThisStringAt(0, 0, "NORMAL MODE");
        NormalModeOperations(keyPressed);
    }

}

void SettingModeOperations(UByte keyPressed) {
    switch (keyPressed) {
        case PREVIOUS: //Previous
            //   lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            PreviousButtonHandler();
            break;

        case UP: //Up
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            UpbuttonHandler();
            break;

        case DOWN: //Down
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            DownButtonHandler();
            break;

        case NEXT: //Next
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            NextButtonHandler();
            break;

        default:
            //  lcd_writeThisCharAt(1, 0, 0x30);
            break;
    }
}

void NormalModeOperations(UByte keyPressed) {
    switch (keyPressed) {
        case COFFEE: //for Coffee
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            serveCoffee();
            break;

        case HALF: //for half quantity    
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            serveHalfQuantity();
            break;

        case WATER:
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            serveHotWater(); //for hot water
            break;

        case TEA:
            //  lcd_writeThisCharAt(1, 0, keyPressed + 0x30);
            serveTea(); //for Tea
            break;

        default:
            //  lcd_writeThisCharAt(1, 0, 0x30);

            break;
    }

}

