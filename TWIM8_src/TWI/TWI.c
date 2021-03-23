/*
 * TWI.c
 *
 * Created: 10/03/2021 11:41:47 a. m.
 *  Author: marti
 */ 
#include "TWI.h"

void TWI_init()
{
	//DDRC &= ~((1<<PC5)|(1<<PC4));
	//PORTC |= ((1<<PC5)|(1<<PC4)); //Resistencias de Pull-up
    TWSR = 0x00; //Clear status reg
	TWBR = 0x0C; //Set bit rate
	TWCR |= (1<<TWEN);
}
void TWI_start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & (0XF8)) != twi_star_code);
}
void TWI_address(uint8_t sla_w,uint8_t R_W)
{
	uint8_t state = 0;
	sla_w = (sla_w << 1);
	if (R_W == twi_write)
	{
		sla_w &= ~1;
		state = MT_SLA_ACK;
	}
	else
	{
		sla_w |= 1;
		state = MT_DATA_ASK;
	}
	TWDR = sla_w;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & (0xF8)) != state);
}
void TWI_write(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	//while((TWSR & (0XF8)) != MT_DATA_ASK);
}

uint8_t TWI_read()
{
	TWCR = (1<<TWEN)|(1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}
void TWI_stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(TWCR & 1<<TWSTO);
}
void TWI_print(char *s)
{
	while(*s)
	{
		TWI_write(*s);
		s++;
		_delay_ms(10);
	}
}


