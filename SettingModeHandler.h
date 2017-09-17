/* 
 * File:   SettingModeHandler.h
 * Author: Lenovo
 *
 * Created on March 29, 2017, 9:40 PM
 */

#ifndef SETTINGMODEHANDLER_H
#define	SETTINGMODEHANDLER_H

#include "CommonDeclarations.h"


#define INITIALISE                  0
#define UPDATE                      1

#define ScreenIndex_0               0
#define ScreenIndex_1               1
#define ScreenIndex_2               2

#define ParamIndex_TeaQty           0
#define ParamIndex_WaterQtyTea      1
#define ParamIndex_CoffeeQty        3
#define ParamIndex_WaterQtyCoffee   4

Boolean isFirstTimeInSetting  =     TRUE;

UByte ScreenIndex = 0;
UByte ParameterIndex = 0;

void InitialiseSettingMode();
void PreviousButtonHandler();
void NextButtonHandler();
void UpbuttonHandler();
void DownButtonHandler();
void UpdateScreen(Boolean Mode);
void updateConfiguration();



#endif	/* SETTINGMODEHANDLER_H */

