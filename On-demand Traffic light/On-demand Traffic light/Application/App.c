/*
 * App.c
 *
 * Created: 9/10/2022 10:44:55 PM
 *  Author: Lenovo
 */ 


#include "App.h"

#define Normal_Mode 0
#define Pedestrian_Mode 1
#define ON_Time 5   // led on time

uint8_t Red_Led = 0; // 0 if OFF, 1 if ON
int state = Normal_Mode;   // normal or pedestrian
int counter = 0;     //for loops in app start function





void APP_init()
{
	Button_init(PORT_D, 2);
	INT0_init();
	LED_init(PORT_A, 0);
	LED_init(PORT_A, 1);
	LED_init(PORT_A, 2);
	LED_init(PORT_B, 0);
	LED_init(PORT_B, 1);
	LED_init(PORT_B, 2);
}

void APP_start()
{
	switch(state)
	{
		case Normal_Mode:
		ALL_LEDs_OFF();
		LED_ON(PORT_A, 0);   //car green led ON
		LED_ON(PORT_B, 2);   //pedestrian red led on
		//delay for 5 sec
		for (counter = 0; counter < ON_Time; counter++)
		{
			if(state == 1)break;   // check interrupt
			Delay_1s();
		}
		
		// car yellow led blinks 5 sec
		for (counter = 0; counter < ON_Time; counter++)
		{
			if(state == 1)break;   // check interrupt
			LED_toggle(PORT_A, 1);
			Delay_1s();
		}
		LED_OFF(PORT_A, 0);  //car green led OFF
		LED_OFF(PORT_B, 2);  //pedestrian red led off
		LED_OFF(PORT_A, 1);  //car yellow led OFF
		LED_ON(PORT_A, 2);  //car red led ON
		LED_ON(PORT_B, 0);  //pedestrian green led on
		//delay for 5 sec
		for (counter = 0; counter < ON_Time; counter++)
		{
			if(state == 1)break;   // check interrupt
			Delay_1s();
		}
		
		// car yellow led blinks 5 sec
		for (counter = 0; counter < ON_Time; counter++)
		{
			if(state == 1)break;   // check interrupt
			LED_toggle(PORT_A, 1);
			Delay_1s();
		}

		break;
		
		
		case Pedestrian_Mode:
		ALL_LEDs_OFF();
		if (Red_Led)  // check if red led is on
		{
			LED_ON(PORT_A, 2);  //car red led on
			LED_ON(PORT_B, 0);  //pedestrian green led on
			//delay 5 sec
			Delay(5);
		}
		else    //if car led was green or yellow
		{
			LED_ON(PORT_B, 2);  //pedestrian red led ON
			
			// both yellow LEDs blink 5 sec
			for (counter = 0; counter < ON_Time; counter++)
			{
				LED_toggle(PORT_A, 1);  //car yellow led
				LED_toggle(PORT_B, 1);  //pedestrian yellow led
				Delay_1s();
			}
			ALL_LEDs_OFF();
			LED_ON(PORT_A, 2);  // car red led on
			LED_ON(PORT_B, 0);  // pedestrian green led on
			Delay(5);   //delay 5 sec
		}
		LED_OFF(PORT_A, 2); //car red led OFF
		// both yellow LEDs blink 5 sec
		for (counter = 0; counter < ON_Time; counter++)
		{
			LED_toggle(PORT_A, 1);  //car yellow led
			LED_toggle(PORT_B, 1);  //pedestrian yellow led
			Delay_1s();
		}
		state = Normal_Mode;
		break;
	}
}

ISR(INT0_vect)
{
	DIO_Read(PORT_A, 2, &Red_Led);
	state = Pedestrian_Mode;
}