/*
 * Dio.h
 *
 * Created: 9/10/2022 10:44:32 PM
 *  Author: Lenovo
 */ 


#ifndef DIO_H_
#define DIO_H_


#include <avr/io.h>

//DRIVER MACROS
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction macros
#define INPUT 0
#define OUTPUT 1

//value macros
#define HIGH 1
#define LOW 0

#define NumOfPins 8

typedef enum EN_DioError_t
{
	OK, WRONG_Direction, Wrong_portName,Wrong_pinNum
}EN_DioError_t;

//functions prototypes
EN_DioError_t DIO_init(uint8_t port_name, uint8_t pin_number, uint8_t direction);
EN_DioError_t DIO_write(uint8_t port_name, uint8_t pin_number, uint8_t value);
EN_DioError_t DIO_Read(uint8_t port_name, uint8_t pin_number, uint8_t *value);
EN_DioError_t DIO_toggle(uint8_t port_name, uint8_t pin_number);

#endif /* DIO_H_ */