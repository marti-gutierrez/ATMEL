/*
 * UART.c
 *
 * Created: 11/03/2021 02:04:08 p. m.
 *  Author: marti
 */ 
#include "UART.h"

void UART_init()
{
	UCSRA = (0<<U2X);
	UCSRB = (1<<RXEN)|(1<<TXEN)|(0<<UCSZ2);;
	UCSRC = (0<<UMSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = 51;
	UBRRH = 0x00;
}
void UART_TX(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

char UART_RX()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}
