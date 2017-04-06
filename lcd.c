#include"lcd.h"
//#define HIGHER_BYTES
#define LOWER_BYTES
#define delaytime 5

void lcd_init()
	{
			UByte command_array[]={0x02,0x28,0x0E,0x01,0x06,0x80};
			UByte index;
            
			for(index=0;index<6;index++)
			{
				lcd_cmd(command_array[index]);	
			}	
	}


void lcd_write(UByte data)
	{

    #ifdef LOWER_BYTES
        LCDPORT = ((data >> 4)& 0x0F);
    #endif
    
    #ifdef HIGHER_BYTES
		LCDPORT=( data & 0x0F0 );
	#endif
        
				RS=1;
				RW=0;		
				EN=1;
				__delay_ms(delaytime);
				EN=0;
    
    #ifdef LOWER_BYTES
        LCDPORT=( data & 0x0F );
    #endif
    #ifdef HIGHER_BYTES            
		LCDPORT=((data<<4)&(0x0F0));
    #endif		
				EN=1;
				__delay_ms(delaytime);
				EN=0;	

	}	



void lcd_cmd(UByte cmnd)
	{
     #ifdef LOWER_BYTES
        LCDPORT = ((cmnd >> 4)& 0x0F);
    #endif
    
    #ifdef HIGHER_BYTES
		LCDPORT=( cmnd & 0x0F0 );
	#endif

				RS=0;
				RW=0;
				EN=1;
				__delay_ms(delaytime);
				EN=0;
              
    
    #ifdef LOWER_BYTES
        LCDPORT=( cmnd & 0x0F );
    #endif
    #ifdef HIGHER_BYTES            
		LCDPORT=((cmnd<<4)&(0x0F0));
    #endif		
			
				EN=1;
				__delay_ms(delaytime);
				EN=0;	
			
	}

void lcd_puts(UByte *ptr)
{
    while(*ptr != '\0')
    {
        lcd_write(*ptr++);
    }
}


void goto_XY(UByte row, UByte column)// </editor-fold>
{
    if(row == 0)
    {
        lcd_cmd(0x80 + column);
    }
    else if(row == 1)
    {
        lcd_cmd(0xC0 + column);
    }
}

  void lcd_clear()
  {
      lcd_cmd(CLEAR);
  }
  
  
  void clear_XY(UByte row,UByte column)
    {
        goto_XY(row,column);
        lcd_write(' ');
    }
  
  void lcd_writeThisStringAt(UByte row,UByte column,UByte *ptr)
  {
      goto_XY(row,column);
      lcd_puts(ptr);
  }
    void lcd_writeThisCharAt(UByte row,UByte column,UByte data)
    {
        goto_XY(row,column);
        lcd_write(data);
        
    }
    
    void lcd_writeThisDigit(UByte data)
    {
        UByte string[4]= {'0','0','0','\0'};
        
        string[2] = data%10 + 0x30;
        data=data/10;
        string[1] = data%10 + 0x30;
        data = data/10;
        string[0] = data%10 + 0x30;
        
        lcd_puts(string);
        
    }