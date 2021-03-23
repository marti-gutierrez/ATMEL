/*
 * UART.c
 *
 * Created: 12/03/2021 03:19:19 p. m.
 *  Author: marti
 */ 
#include "UART.h"
void UART_init()
{
    DDRD |= (1<<PD1);//PD1 <-- Exit (TX)
	DDRD &= ~(1<<PD0);//PD0 <-- In (RX)
	UCSR0A = (0<<TXC0)|(0<<U2X0)|(0<<MPCM0);
	UCSR0B = (1<<RXCIE0)|(0<<TXCIE0)|(0<<UDRIE0)|(1<<RXEN0)|(1<<TXEN0)|(0<<UCSZ02)|(0<<TXB80);
	UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)|(0<<UPM01)|(0<<UPM00)|(0<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00)|(0<<UCPOL0);
	UBRR0 = 51;
}

void UART_write(uint8_t data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}
void UART_write_tx(char* cadena)
{
	while(*cadena != (0x00))
	{
		UART_write(*cadena);
		cadena++;
	}
}

char UART_read()
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}