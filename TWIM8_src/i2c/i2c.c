/*
 * i2c.c
 *
 * Created: 13/03/2021 03:35:32 p. m.
 *  Author: marti
 */ 
#include "i2c.h"

void i2c_init()
{
	TWBR = 0x0C;
	TWSR = 0X00;     //Prescaler 1
	TWCR = (1<<TWEN);//Enable Two Interface Wire
}
uint8_t i2c_Start()
{
	uint8_t edo;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);//Start condition
	edo = TWSR & 0xF8;
	if(edo == Start_condition || edo == Rep_Start_condition)
	    return 0x01;
	return edo;
}
uint8_t i2c_write(uint8_t data)
{
	uint8_t edo;
	TWDR = data;                 //Cargar data
	TWCR = (1<<TWEN)|(1<<TWINT); //Start Send
	while(!(TWCR & (1<<TWINT))); //Wait flag (TWINT)
	edo = TWSR & 0xF8;
	if(edo == SLA_W_ACK|| edo == SLA_R_ACK||edo == one_data_ACK)
	   return 0x01;
	return edo;
}
void i2c_stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); //Stop Condition
	while(TWCR & (1<<TWSTO));
}
uint8_t i2c_read(uint8_t *data,uint8_t ack)
{
	uint8_t edo;
	if(ack)
	   TWCR |= (1<<TWEA);  //Read with ACK
	else
	   TWCR &= ~(1<<TWEA); //Read without ACK --> NACK
	TWCR |= (1<<TWINT);
	while(!(TWCR & (1<<TWINT)));
	edo = TWSR & 0xF8;
	if(edo == data_read_ACK||edo == data_read_NACK )
	{
	    *data = TWDR;
		return 0x01;
	}
	return edo;	
}
