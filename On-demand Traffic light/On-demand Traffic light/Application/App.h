/*
 * App.h
 *
 * Created: 9/10/2022 10:45:16 PM
 *  Author: Lenovo
 */ 


#ifndef APP_H_
#define APP_H_


#include "../ECUAL/Button Driver/Button.h"
#include "../ECUAL/Interrupts/interrupts.h"
#include "../ECUAL/Led Driver/Led.h"
#include "../ECUAL/Timer Driver/Timer.h"


void APP_init(void);
void APP_start(void);


#endif /* APP_H_ */