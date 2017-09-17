/* 
 * File:   timer2.h
 * Author: Lenovo
 *
 * Created on August 2, 2017, 11:52 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H

#ifdef	__cplusplus
extern "C" {
#endif


    
#include<htc.h>
//#include<xc.h>
#include<pic.h>
#include"myTypeDef.h"
#include"CommonDeclarations.h"



void initialise_timer2();
void start_timer2();
void stop_timer2();


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER2_H */

