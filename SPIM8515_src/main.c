/*
 * SPI_8515.c
 *
 * Created: 23/02/2021 07:05:29 p. m.
 * Author : marti
 */ 
#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SPI/SPI.h"

int main(void)
{
	SPI_init();
	_delay_ms(10);
	DDRC = 0xFF;
    while (1) 
    {
		for (uint8_t i = 0; i <= 100; i+= 10)
		{
			SPI_tx(i);
		    PORTC = SPI_rx();
			_delay_ms(3000);
		}
		
    }
}

