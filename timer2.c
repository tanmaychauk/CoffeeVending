#include <pic16f887.h>

#include"timer2.h"

void initialise_timer2()
{
    //prescalar 1:16, timer off, postscalar 1:16
    T2CON = 0b1111011;     
    TMR2IE = 1;
    TMR2 = 0x00;
    PR2 = 0xFF;
}
void start_timer2()
{
    TMR2ON = 1;
}
void stop_timer2()
{
    TMR2ON = 0;
}
