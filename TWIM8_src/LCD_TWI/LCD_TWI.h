/*
 * LCD_TWI.h
 *
 * Created: 12/03/2021 09:55:05 a. m.
 *  Author: marti
 */ 


#ifndef LCD_TWI_H_
#define LCD_TWI_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_CONTROL 0
#define LCD_DATA 1

#define Write_Line1 0x80
#define Write_Line2 0xC0
#define clear_LCD   0x01

void LCDtwi_start();
void LCD_write(uint8_t type,uint8_t inst_data);
void LCDtwi_init();

void TWI_start();

void LCD_print(char *s);



#endif /* LCD_TWI_H_ */