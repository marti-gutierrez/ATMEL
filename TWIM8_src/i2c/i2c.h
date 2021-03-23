/*
 * i2c.h
 *
 * Created: 13/03/2021 03:35:16 p. m.
 *  Author: marti
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

void i2c_init();
uint8_t i2c_Start();
uint8_t i2c_write(uint8_t data);
uint8_t i2c_read(uint8_t *data,uint8_t ack);
void i2c_stop();

#define Start_condition 0x08
#define Rep_Start_condition 0x10
#define SLA_W_ACK 0x18
#define SLA_R_ACK 0x28
#define one_data_ACK 0x40
#define data_read_ACK 0x58
#define data_read_NACK 0x50

#endif /* I2C_H_ */