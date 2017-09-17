#include "PORTB_Config.h"

void initialisePortB()
{
    TRISB = 0b11110001;     //RB0,RB4,RB5,RB6,RB7 as input pins
    RBPU = 1;               //enable internal pullup
    
}

void enableInterrupt_RB0()
{
    INTEDG = 0;         //interrupt on Falling Pulse on INTEDG
    INTE = 1;               //Enable Interrupt for RB0
}

void disableInterrupt_RB0()
{
    INTE = 0;               //Disable interrupt RB0
}


    

