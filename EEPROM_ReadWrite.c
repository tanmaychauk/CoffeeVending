#include"EEPROM_ReadWrite.h"


void myEEPROM_writeData(UByte ADDRESS,UByte DATA)
{
    GIE = 0;            //Disable interrupts
    
    EEADR = ADDRESS;    // set the address location in EEADR
    EEDATA = DATA; // data to be written is taken in EEDATA
    
    EEPGD = 0;
    WREN = 1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    WR = 1;
    WREN = 0;
    
    while(WR == 1);    // wait until write procedure gets completed.
    
}

UByte myEEPROM_readData(UByte ADDRESS)
{
    EEADR = ADDRESS;
    RD = 1;                     // read eeprom at address EEADR
    return EEDATA;              // data from eeprom read will be available in very next cycle in EEDATA

}

void myEEPROM_writeString(UByte StartAddress,UByte *data)
{
    while(*data != '\0')
    {
     myEEPROM_writeData(StartAddress++,*data++);
    }
}