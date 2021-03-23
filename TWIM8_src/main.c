/*
 * TWI_Atmega8.c
 *
 * Created: 10/03/2021 11:40:33 a. m.
 * Author : marti
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TWI/TWI.h"
#include "LCD/LCD_display.h"

#define slave1 0x27
#define slave2 0x03

char nombre[] = "Martin Gutierrez Hernandez\n\r";
char estado1[] = "Protocolo I2C";
char estado2[] = "Esclavo 2";
char terminal[] = "Esclavo 1\n\r";
int main(void)
{
	DDRD = 0x00;
	PORTD = 0XFF;
	i2c_init();
	MCUCR = (1<<ISC01)|(0<<ISC00);
	GICR = (1<<INT0);
	sei();
	while(1)
	   asm("nop");
}

ISR(INT0_vect)
{
   TWI_start();
   TWI_address(slave2,twi_write);
   TWI_print(nombre);
   TWI_stop();
   _delay_ms(2000);
    TWI_start();
    TWI_address(slave1,twi_write);
    LCD_init();
    LCD_write(LCD_CONTROL,clear_LCD);
    LCD_write(LCD_CONTROL,Write_Line1);
    LCD_print(estado1);
	LCD_write(LCD_CONTROL,Write_Line2+2);
	LCD_print(estado2);
	_delay_ms(3000);
	LCD_write(LCD_CONTROL,clear_LCD);
    TWI_stop();
	TWI_start();
	TWI_address(slave2,twi_write);
	TWI_print(terminal);
	TWI_stop();
	_delay_ms(2000);
}

