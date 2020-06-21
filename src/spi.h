/*
 * spi.h
 *
 * Created: 6/6/2020 2:38:52 AM
 *  Author: ajbeli
 */ 

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>


#define spi_clock_rate_f2		0x04
#define spi_clock_rate_f4		0x00
#define spi_clock_rate_f8		0x05
#define spi_clock_rate_f16		0x01
#define spi_clock_rate_f32		0x06
#define spi_clock_rate_f64		0x02
#define spi_clock_rate_f128		0x03
#define spi_clock_rate_f256		0x07

#define spi_data_order_lsb_first 0x01
#define spi_data_order_msb_first 0x00 

#define spi_clock_leading_falling 0x01
#define spi_clock_leading_rising  0x00

#define spi_clock_phase_sample_data_leading_edge 0x01 
#define spi_clock_phase_sample_data_trailing_edge 0x00

// SPI Pins
#define SPI_MOSI B,3
#define SPI_MISO B,4
#define SPI_SCK  B,5
#define SPI_CS   B,2
#define SPI_INT  D,2
#define True 0x01
#define False 0x00


void spi_init_slave(void) ;
void spi_init_master(void) ;
void spi_enable_int(void) ;
void spi_enable() ;
void spi_select_clock_rate(uint8_t clock_rate) ;
void spi_set_data_order(uint8_t order) ;
void spi_set_clock_polarity(uint8_t polarity ) ;
uint8_t spi_get_interrupt_flag(void) ;
uint8_t spi_get_collision_flag(void) ;
uint8_t spi_send_data(uint8_t data) ;

#endif