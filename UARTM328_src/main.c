/*
 * UART_M328.c
 *
 * Created: 11/03/2021 03:54:49 p. m.
 * Author : marti
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "UART/UART.h"

int main(void)
{
    UART_init();
	_delay_ms(10);
	while(!(UCSRA & (1<<RXC)));
    while (1) 
    {
		UART_TX('S');
    }
}

