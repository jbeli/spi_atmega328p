/*
 * SPI_master.c
 *
 * Created: 6/17/2020 9:11:39 PM
 * Author : ajbeli
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <spi.h>
#include <avr/interrupt.h>


uint8_t data = 0x01 ;

int main (void)
{
	DDRD &= ~(1<<6) ; // 6 input 
	
	PCICR = (1<<PCIE2); // set interruption for PORT D 
	PCMSK2 = (1<<PCINT22); // set Pin 6 
	
	//SPI settings
    
	spi_init_master() ;
    
	spi_select_clock_rate(spi_clock_rate_f128) ;
    
	spi_enable_int() ;
    
	spi_enable();
	 
	spi_set_clock_polarity(spi_data_order_lsb_first);

	sei();

	while(1)
	{
	
	}
 }
 
 ISR(PCINT2_vect)
 {
	 if(bit_is_set(PIND, PIND6))
	 {
		 SPDR = 0x01 ;
		 while(!(SPSR & (1<< SPIF))) ;

	 }
	
 }
 