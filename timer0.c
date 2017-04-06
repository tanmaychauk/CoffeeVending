#include"timer0.h"


void initialise_timer0()
{
    /*Set prescalar = divide by 256*/
    PS0 = 1;
    PS1 = 1;
    PS2 = 1;
    
    /*Timer clock source = Prescalar*/
    PSA = 0;
    
    /*Prescaler gets clock from FCPU*/
    T0CS = 0;
    
    /*8 bit mode*/
    T0SE = 0;
    
    /*Interrupt related settings*/
    TMR0IE = 1;         //Enalbe TIMER0 Interrupt
    PEIE = 1;           //Enable Peripheral Interrupt
    GlobalInterrupt_ENABLE();  
}

void start_timer0()
{
    TMR0 = 1;
}

void stop_timer0()
{
    TMR0 = 0;
}
