/*
 * Dio.c
 *
 * Created: 9/10/2022 10:44:20 PM
 *  Author: Lenovo
 */ 


#include "Dio.h"



//functions implementation
EN_DioError_t DIO_init(uint8_t port_name, uint8_t pin_number, uint8_t direction)
{
	if (pin_number >= NumOfPins)
	{
		return Wrong_pinNum;
	}
	switch(port_name)
	{
		case PORT_A:
		if (direction == INPUT)
		{
			DDRA &= ~(1<<pin_number);
			return OK;
		}
		else if (direction == OUTPUT)
		{
			DDRA |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;

		case PORT_B:
		if (direction == INPUT)
		{
			DDRB &= ~(1<<pin_number);
			return OK;
		}
		else if (direction == OUTPUT)
		{
			DDRB |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;
		
		case PORT_C:
		if (direction == INPUT)
		{
			DDRC &= ~(1<<pin_number);
			return OK;
		}
		else if (direction == OUTPUT)
		{
			DDRC |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;
		
		case PORT_D:
		if (direction == INPUT)
		{
			DDRD &= ~(1<<pin_number);
			return OK;
		}
		else if (direction == OUTPUT)
		{
			DDRD |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;
		
		default:
		return Wrong_portName;
	}
}

EN_DioError_t DIO_write(uint8_t port_name, uint8_t pin_number, uint8_t value)
{
	if (pin_number >= NumOfPins)
	{
		return Wrong_pinNum;
	}
	switch(port_name)
	{
		case PORT_A:
		if (value == LOW)
		{
			PORTA &= ~(1<<pin_number);
			return OK;
		}
		else if (value == HIGH)
		{
			PORTA |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;

		case PORT_B:
		if (value == LOW)
		{
			PORTB &= ~(1<<pin_number);
			return OK;
		}
		else if (value == HIGH)
		{
			PORTB |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;
		
		case PORT_C:
		if (value == LOW)
		{
			PORTC &= ~(1<<pin_number);
			return OK;
		}
		else if (value == HIGH)
		{
			PORTC |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;
		
		case PORT_D:
		if (value == LOW)
		{
			PORTD &= ~(1<<pin_number);
			return OK;
		}
		else if (value == HIGH)
		{
			PORTD |= (1<<pin_number);
			return OK;
		}
		else
		{
			return WRONG_Direction;
		}
		break;
		
		default:
		return Wrong_portName;
	}
}

EN_DioError_t DIO_Read(uint8_t port_name, uint8_t pin_number, uint8_t *value)
{
	if (pin_number >= NumOfPins)
	{
		return Wrong_pinNum;
	}
	switch(port_name)
	{
		case PORT_A:
		*value = ((PINA & (1 << pin_number)) >> pin_number);
		return OK;
		break;
		
		case PORT_B:
		*value = ((PINB & (1 << pin_number)) >> pin_number);
		return OK;
		break;
		
		case PORT_C:
		*value = ((PINC & (1 << pin_number)) >> pin_number);
		return OK;
		break;
		
		case PORT_D:
		*value = ((PIND & (1 << pin_number)) >> pin_number);
		return OK;
		break;
		
		default:
		return Wrong_portName;
	}
}

EN_DioError_t DIO_toggle(uint8_t port_name, uint8_t pin_number)
{
	if (pin_number >= NumOfPins)
	{
		return Wrong_pinNum;
	}
	switch(port_name){
		case PORT_A:
		PORTA ^= (1<<pin_number);
		return OK;
		break;
		case PORT_B:
		PORTB ^= (1<<pin_number);
		return OK;
		break;
		case PORT_C:
		PORTC ^= (1<<pin_number);
		return OK;
		break;
		case PORT_D:
		PORTD ^= (1<<pin_number);
		return OK;
		break;
		default:
		return Wrong_portName;
	}
}