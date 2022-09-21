/*
 * Timer.c
 *
 * Created: 9/10/2022 10:43:49 PM
 *  Author: Lenovo
 */ 

#include "Timer.h"

void Delay_1s()
{
	unsigned int overflowNum = 62;
	//setting timer to normal mode
	TCCR0 = 0x00;
	//setting initial value to 4
	TCNT0 = (1<<2);
	//clkI/O/64 (From prescaler)
	TCCR0 |= 0x03;
	for (int i = 0; i < overflowNum; i++)
	{
		//wait until overflow flag to be set
		while((TIFR & (1<<0)) == 0);
		//clear overflow flag
		TIFR |= (1<<0);
	}
}

//generic delay
void Delay(int sec_num)
{
	for (int i = 0; i < sec_num; i++)
	{
		Delay_1s();
	}
}

