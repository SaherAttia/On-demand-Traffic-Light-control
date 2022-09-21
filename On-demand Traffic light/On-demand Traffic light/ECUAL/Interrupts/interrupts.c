/*
 * interrupts.c
 *
 * Created: 9/11/2022 12:08:29 AM
 *  Author: Lenovo
 */ 


#include "interrupts.h"

void INT0_init()
{
	//enable global interrupts
	sei();
	
	//sense on rising edge
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	
	//enable external INT0
	GICR |= (1<<INT0);
}