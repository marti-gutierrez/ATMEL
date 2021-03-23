/*
 * UART.h
 *
 * Created: 12/03/2021 03:19:03 p. m.
 *  Author: marti
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 8000000UL 
void UART_init();
void UART_write(uint8_t data);
void UART_write_tx(char* cadena);
char UART_read();


#endif /* UART_H_ */