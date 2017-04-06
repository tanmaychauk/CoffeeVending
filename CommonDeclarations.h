/* 
 * File:   CommonDeclarations.h
 * Author: Lenovo
 *
 * Created on March 19, 2017, 10:22 PM
 */

#ifndef COMMONDECLARATIONS_H
#define	COMMONDECLARATIONS_H

#include"myTypeDef.h"
#include<htc.h>
//#include<xc.h>
#include<pic.h>
#include"lcd.h"
#include"EEPROM_ReadWrite.h"
#include"SettingModeHandler.h"


#define NORMAL_MODE 1
#define SETTING_MODE 0

#define COFFEE  1
#define HALF    2
#define WATER   3
#define TEA     4

#define PREVIOUS    1
#define UP          2
#define DOWN        3
#define NEXT        4


#define DefaultCoffeeQuantity_value              0x10
#define DefaultWaterQuantity_forCoffee_value     0x10 
#define DefaultTeaQuantity_value                 0x10
#define DefaultWaterQuantity_forTea_value        0x10

#define KEYPAD                                   PORTB
#define KEY1                                     1<<4
#define KEY2                                     1<<5
#define KEY3                                     1<<6
#define KEY4                                     1<<7


Boolean IsNewMachine = TRUE;
Boolean flag_T0_OneSecond;
Boolean flag_T0_TenSecond;
Boolean modeOfWorking = 1;


UByte CurrentCoffeeQuantity = 10;
UByte CurrentWaterQuantity_forCoffee = 10;
UByte CurrentTeaQuantity = 10;
UByte CurrentWaterQuantity_forTea = 10;






void GlobalInterrupt_ENABLE();
void GlobalInterrupt_DISABLE();
void interrupt ISR();
void PeripheralInterrupt_ENABLE();
void PeripheralInterrupt_DISABLE();
void handleEvent(UByte keyPressed);
void NormalModeOperations(UByte keyPressed);
void SettingModeOperations(UByte KeyPressed);
void IsKeyPressed();






#endif	/* COMMONDECLARATIONS_H */

