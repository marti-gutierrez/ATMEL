/*
 * UART.h
 *
 * Created: 11/03/2021 02:03:46 p. m.
 *  Author: marti
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 8000000
void UART_init();
void UART_TX(char data);
char UART_RX();


#endif /* UART_H_ */