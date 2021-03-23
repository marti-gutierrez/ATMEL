/*
 * LCD_display.h
 *
 * Created: 24/02/2021 11:33:13 a. m.
 *  Author: marti
 */ 


#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../TWI/TWI.h"

#define LCD_CONTROL 0
#define LCD_DATA 1

#define Write_Line1 0x80
#define Write_Line2 0xC0
#define clear_LCD   0x01

void LCD_start();
void LCD_write(uint8_t type,uint8_t inst_data);
void LCD_init();

void LCD_print(char *s);

#endif /* LCD_DISPLAY_H_ */