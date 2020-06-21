


/*
* spi.c
 *
 * Created: 6/6/2020 2:38:52 AM
 *  Author: ajbeli

*/
#include <spi.h>
#include "avr/io.h"
#include <avr/sfr_defs.h>

void spi_init_slave(void)
{
	DDRB &= ~((1<<PORTB2)|(1<<PORTB3)|(1<<PORTB5));   // SCK, MOSI and SS as inputs
	DDRB |= (1<<PORTB4);                    // MISO as output
	SPCR &= ~(1<<MSTR);                // Set as slave
}

void spi_init_master(void)
{
	DDRB = (1<<PORTB5)|(1<<PORTB3)|(1<<PORTB2); // SCK, MOSI, SS as output // MISO as input 
	DDRB &=~(1<<PORTB4); // MISO as input 
	SPCR |= (1<<MSTR); // set as a master
	
}

void spi_enable()
{
	SPCR |= (1<<SPE);
}
void spi_enable_int(void)
{
	SPCR|=(1<<SPIE);
}

void spi_disable_int(void)
{
	SPCR = (0<<SPIE);
}
void spi_select_clock_rate(uint8_t clock_rate)
{
	
	if (clock_rate < 4)
	{
		SPCR|=(clock_rate << SPR0);
	}
	else
	{
		SPCR|= ((clock_rate & ~ (1<<3)) << SPR0) ;
		SPSR = 1<<SPI2X ;
	}
	
}

void spi_set_data_order(uint8_t order)
{
	SPCR|= order << DORD ;
}

void spi_set_clock_polarity(uint8_t polarity )
{
	SPCR|= polarity << CPOL ;
}

void spi_set_clock_phase(uint8_t phase)
{
	SPCR|=(phase << CPHA) ;
}

uint8_t spi_get_interrupt_flag(void)
{
	return bit_is_set(SPSR,SPIF) ;
}

uint8_t spi_get_collision_flag(void)
{
	return bit_is_set(SPSR,WCOL) ; 
}

uint8_t spi_send_data(uint8_t data)
{
	  
	
	while ( !(SPSR & (1<< SPIF)))
	;
	
	return SPDR ;
}
