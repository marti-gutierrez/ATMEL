/*
 * TWI.h
 *
 * Created: 10/03/2021 11:41:24 a. m.
 *  Author: marti
 */ 


#ifndef TWI_H_
#define TWI_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define twi_write 0x00
#define twi_read  0x01

#define twi_star_code 0x08
#define MT_SLA_ACK 0x18
#define MT_DATA_ASK 0x28

void TWI_init();
void TWI_start();
void TWI_address(uint8_t sla_w,uint8_t R_W);
void TWI_write(uint8_t data);
uint8_t TWI_read();
void TWI_stop();
void TWI_print(char *s);

#endif /* TWI_H_ */