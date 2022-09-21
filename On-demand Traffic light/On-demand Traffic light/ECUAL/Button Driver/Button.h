/*
 * Button.h
 *
 * Created: 9/10/2022 10:43:05 PM
 *  Author: Lenovo
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/Dio.h"

//button macros
#define Button_Pressed 1
#define Button_NotPressed 0

//functions prototypes
void Button_init(uint8_t port_name, uint8_t pin_number);
void Button_Read(uint8_t port_name, uint8_t pin_number, uint8_t* state);




#endif /* BUTTON_H_ */