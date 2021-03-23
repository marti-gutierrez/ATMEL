/*
 * SPI.h
 *
 * Created: 23/02/2021 07:07:39 p. m.
 *  Author: marti
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

void SPI_init();
void SPI_slaveON(uint8_t slave);
void SPI_slaveOFF(uint8_t slave);
void SPI_tx(uint8_t data);
uint8_t SPI_rx();

#endif /* SPI_H_ */