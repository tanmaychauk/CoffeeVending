/* 
 * File:   EEPROM_ReadWrite.h
 * Author: Lenovo
 *
 * Created on March 19, 2017, 8:19 PM
 */

#ifndef EEPROM_READWRITE_H
#define	EEPROM_READWRITE_H

#include<htc.h>
//#include<xc.h>
#include<pic.h>
#include"myTypeDef.h"

#define ConfigurationSetter             0x05


#define defaultCoffeeQuantity_ADDR           0x10
#define defaultWaterQuantityForCoffee_ADDR   0x12
#define defaultTeaQuantity_ADDR              0x14
#define defaultWaterQuantityForTea_ADDR      0x16

#define currentCoffeeQuantity_ADDR           0x20
#define currentWaterQuantityForCoffee_ADDR   0x22
#define currentTeaQuantity_ADDR              0x24
#define currentWaterQuantityForTea_ADDR      0x26

void  myEEPROM_writeData(UByte ADDRESS,UByte DATA);
UByte myEEPROM_readData(UByte ADDRESS);
void  myEEPROM_writeString(UByte StartAddress,UByte *data);





#endif	/* EEPROM_READWRITE_H */

