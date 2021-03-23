/*
 * LCD_display.c
 *
 * Created: 24/02/2021 11:33:33 a. m.
 *  Author: marti
 */ 
#include "LCD_display.h"
uint8_t valor;

void LCD_start()
{
	valor &= ~(1<<2);
	TWI_write(valor);
	_delay_us(1);
	valor |= (1<<2);
	TWI_write(valor);
}

void LCD_write(uint8_t type,uint8_t inst_data)
{
	if (type)
		  valor |= (1<<0);
    else
		  valor &= ~(1<<0);
	TWI_write(valor);
	valor = (valor & (0x0F))|(inst_data & 0xF0);
	TWI_write(valor);
	LCD_start();
	valor = (valor & (0x0F))|((inst_data<<4) & 0xF0);
	TWI_write(valor);
	LCD_start();
	_delay_ms(2);
}
void LCD_init()
{
	valor = 0x08;
	valor = (valor & 0x0F) | 0x30;
	TWI_write(valor);
	_delay_ms(100);
	LCD_start();
	_delay_ms(5);
	LCD_start();
	_delay_us(100);
	LCD_start();
	_delay_us(100),
	valor = (valor & 0x0F) | 0x20;
	TWI_write(valor);
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