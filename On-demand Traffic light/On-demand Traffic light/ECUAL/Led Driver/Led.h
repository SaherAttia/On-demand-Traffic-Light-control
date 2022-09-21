/*
 * Led.h
 *
 * Created: 9/10/2022 10:43:34 PM
 *  Author: Lenovo
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/Dio.h"

void LED_init(uint8_t port_name, uint8_t pin_number);
void LED_ON(uint8_t port_name, uint8_t pin_number);
void LED_OFF(uint8_t port_name, uint8_t pin_number);
void LED_toggle(uint8_t port_name, uint8_t pin_number);
void LED_State(uint8_t port_name, uint8_t pin_number, uint8_t *state);
void ALL_LEDs_OFF(void);



#endif /* LED_H_ */