/*
 * LCD_display.c
 *
 * Created: 24/02/2021 11:31:47 a. m.
 * Author : marti
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "LCD_display/LCD_display.h"

int main(void)
{
    LCD_init();
    while (1) 
    {
		LCD_write(LCD_CONTROL,clear_LCD);
        LCD_print("Soy Batman");
		_delay_ms(2000);
    }
}

