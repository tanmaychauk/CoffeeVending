#include<htc.h>
//#include<xc.h>
#include <pic.h>
#include<string.h>

#include "myTypeDef.h"

#define _XTAL_FREQ 20000000

/*******LCD pins definations*******/
#define	RS RE0
#define	RW RE1
#define EN RE2

#define LCDPORT PORTD


#define CLEAR 0x01



/*******LCD functions*******/
	
	void lcd_init();                              //initialise lcd in 4 bit mode
    void lcd_write(UByte data);                   //write 1 character to lcd
	void lcd_cmd(UByte cmnd);                     //write command to lcd
    void lcd_clear();                             //clear lcd
    void clear_XY(UByte row,UByte column);        //clear lcd at position specified
    void lcd_puts(UByte *ptr);                    //write string to lcd
    void goto_XY(UByte row,UByte column);         // go to specified position
    void lcd_writeThisStringAt(UByte row,UByte column,UByte *ptr);      //go to spcified position and write the string
    void lcd_writeThisCharAt(UByte row,UByte column,UByte data);      //go to spcified position and write the character
    void lcd_writeThisDigit(UByte data);
    
    
/**************************/







