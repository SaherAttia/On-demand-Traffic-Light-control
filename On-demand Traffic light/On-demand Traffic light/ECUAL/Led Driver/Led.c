/*
 * Led.c
 *
 * Created: 9/10/2022 10:43:23 PM
 *  Author: Lenovo
 */ 

#include "Led.h"

void LED_init(uint8_t port_name, uint8_t pin_number)
{
	DIO_init(port_name, pin_number, OUTPUT);
}


void LED_ON(uint8_t port_name, uint8_t pin_number)
{
	DIO_write(port_name, pin_number, HIGH);
}


void LED_OFF(uint8_t port_name, uint8_t pin_number)
{
	DIO_write(port_name, pin_number, LOW);
}

void LED_toggle(uint8_t port_name, uint8_t pin_number)
{
	DIO_toggle(port_name, pin_number);
}

void LED_State(uint8_t port_name, uint8_t pin_number, uint8_t *state)
{
	DIO_Read(port_name, pin_number, state);
}

void ALL_LEDs_OFF()
{
	LED_OFF(PORT_A, 0);  //car green led
	LED_OFF(PORT_A, 1);  //car yellow led
	LED_OFF(PORT_A, 2);  //car red led
	
	LED_OFF(PORT_B, 0);  //pedestrian green led
	LED_OFF(PORT_B, 1);  //pedestrian yellow led
	LED_OFF(PORT_B, 2);  //pedestrian red led	
}