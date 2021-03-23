/*
 * LCD_display.c
 *
 * Created: 24/02/2021 11:33:33 a. m.
 *  Author: marti
 */ 
#include "LCD_display.h"

void LCD_start()
{
	PORTD &= ~(1<<PD0);
	_delay_us(1);
	PORTD |= (1<<PD0);
}

void LCD_write(uint8_t type,uint8_t inst_data)
{
	if (type)
	      PORTD |= (1<<PD1);//Data Register
    else
	      PORTD &= ~(1<<PD1);//Data Control
	PORTB = (PINB &(0x0F))|(inst_data & 0xF0);
	LCD_start();
	PORTB = (PINB &(0x0F)) | ((inst_data<<4)& 0xF0);
	LCD_start();
	_delay_ms(2);
}
void LCD_init()
{
	DDRD |= (1<<PD1)|(1<<PD0);
	DDRB = 0xF0;
	PORTD &= ~((1<<PD0)|(1<<PD1));
	PORTB = (PINB & 0x0F)| 0x30;
	_delay_ms(100);
	LCD_start();
	_delay_ms(5);
	LCD_start();
	_delay_us(100);
	LCD_start();
	_delay_us(100),
	PORTB = (PINB & 0x0F) | 0x20;
	
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