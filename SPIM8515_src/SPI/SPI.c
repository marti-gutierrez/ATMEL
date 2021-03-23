/*
 * SPI.c
 *
 * Created: 23/02/2021 07:07:54 p. m.
 *  Author: marti
 */ 
#include "SPI.h"

void SPI_init()
{
	/* Master -> 1<<SCK(PB7)|0<<MISO(PB6)|1<<MOSI(PB5)
	   Slave  -> 0<<SCK(PB7)|1<<MISO(PB6)|0<<MOSI(PB5)*/
    DDRB |= (1<<PB7)|(1<<PB5);
	DDRB &= ~(1<<PB6);
	//SLAVE ->	PB1(SLAVE 1)|PB2(SLAVE 2)
	DDRB |= (1<<PB1)|(1<<PB2);
	PORTB |= (1<<PB1)|(1<<PB2);
	SPCR = (1<<SPE)|(1<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(0<<SPR1)|(1<<SPR0);
	/*   |  SPI    | Data    | Select  | SCK     | clk pha |   SCK rate       |
	     |  Enable | LSB-1°  | "Master"|clock low|Rising ED| F_osc/8 = 4 MHz/8|*/
	SPSR |= (1<<SPI2X);
}
void SPI_slaveON(uint8_t slave)
{
	switch (slave)
	{
		case 1:
		        PORTB &= ~(1<<PB1);
				break;
		case 2:
		        PORTB &= ~(1<<PB2);
				break;
	} 
}
void SPI_slaveOFF(uint8_t slave)
{
	switch (slave)
	{
		case 1:
		    	PORTB |= (1<<PB1);
			    break;
		case 2:
			    PORTB |= (1<<PB2);
			    break;
	}
}
void SPI_tx(uint8_t data)
{
	SPDR =data;
	while(!(SPSR &(1<<SPIF)));
}
uint8_t SPI_rx()
{
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
