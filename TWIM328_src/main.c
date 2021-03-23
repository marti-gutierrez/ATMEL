/*
 * twi_atmega328.c
 *
 * Created: 10/03/2021 11:26:26 p. m.
 * Author : marti
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <compat/twi.h>
#include <util/delay.h>
#include "UART/UART.h"

int main(void)
{
	uint8_t addres = 0x03;
	UART_init();
	_delay_ms(10);
	DDRB = 0xFF;
	addres <<= 0x01;
	addres |= 0x01;
	TWAR = addres;
	TWCR = (1<<TWEA)|(1<<TWEN)|(1<<TWIE);
	sei();
    while (1) 
	   asm("nop");
}
ISR(TWI_vect)
{
	uint8_t estado,dato;
	estado = TWSR & 0xFC;
	switch(estado)
	{
		case 0x60:
		case 0x70: TWCR |= (1<<TWINT); //clear
		           break;
		case 0x80:
		case 0x90: dato = TWDR; //Receiver data
		
				   PORTB = dato;
				   TWCR |= (1<<TWINT);
				   break;
		default:   TWCR |= (1<<TWINT)|(1<<TWSTO);
	}
}

