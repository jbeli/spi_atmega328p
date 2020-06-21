/*
 * SPI_Slave.c
 *
 * Created: 6/17/2020 9:44:53 PM
 * Author : ajbeli
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <spi.h>
#include <avr/interrupt.h>
volatile uint8_t data ;


int main(void)
{

	spi_init_slave() ; 

	spi_select_clock_rate(spi_clock_rate_f128);

	spi_enable_int();

	spi_enable();
	
	spi_set_clock_polarity(spi_data_order_lsb_first);
	
	DDRD = (1<<DDD7) ;
	
	sei();
	while(1)
	{

	}

}

ISR (SPI_STC_vect)
{
	data = SPDR;
	if(data == 0x01)
	{
		PORTD^=(1<<PORTD7);
	}
}
