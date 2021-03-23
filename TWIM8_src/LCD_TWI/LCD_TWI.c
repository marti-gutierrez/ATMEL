/*
 * LCD_TWI.c
 *
 * Created: 12/03/2021 09:55:28 a. m.
 *  Author: marti
 */ 
#include "LCD_TWI/LCD_TWI.h"

void LCDtwi_start()
{
	PORTD &= ~(1<<PD2);
	_delay_us(1);
	PORTD |= (1<<PD2);
}

void LCD_write(uint8_t type,uint8_t inst_data)
{
	if (type)
	PORTD |= (1<<PD0);//Data Register
	else
	PORTD &= ~(1<<PD0);//Data Control
	PORTD = (PIND &(0x0F))|(inst_data & 0xF0);
	LCD_start();
	PORTD = (PIND &(0x0F)) | ((inst_data<<4)& 0xF0);
	LCD_start();
	_delay_ms(2);
}
void LCDtwi_init()
{
	uint8_t data = 0x08;
	TWSR = 0x00;
	TWBR = 0x62;
	TWCR |= (1<<TWEN);
	// 
	data = (data & 0x0F)| 0x30;
	_delay_ms(100);
	LCD_start();
	_delay_ms(5);
	LCD_start();
	_delay_us(100);
	LCD_start();
	_delay_us(100),
	PORTD = (PIND & 0x0F) | 0x20;
	
	LCD_start();
	_delay_us(100);
	LCD_write(LCD_CONTROL,0x2C);
	LCD_write(LCD_CONTROL,0x08);
	LCD_write(LCD_CONTROL,0x01);
	LCD_write(LCD_CONTROL,0x06);
	LCD_write(LCD_CONTROL,0X0C);
}

void LCD_print(char *s)
{
	while(*s)
	{
		LCD_write(LCD_DATA, *s);
		s++;
	}
}

void TWI_start()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));
}