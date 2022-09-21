/*
 * Button.c
 *
 * Created: 9/10/2022 10:42:51 PM
 *  Author: Lenovo
 */ 


#include "Button.h"

void Button_init(uint8_t port_name, uint8_t pin_number)
{
	DIO_init(port_name, pin_number, INPUT);
}


void Button_Read(uint8_t port_name, uint8_t pin_number, uint8_t *state)
{
	DIO_Read(port_name, pin_number, state);
}