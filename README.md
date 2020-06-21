# spi_atmega328p

The SPI API contains the following functions that help to set-up the micro-controller : 

void spi_init_slave(void) ;
void spi_init_master(void);
void spi_enable_int(void) ;
void spi_enable() ;
void spi_select_clock_rate(uint8_t clock_rate) ;
void spi_set_data_order(uint8_t order) ;
void spi_set_clock_polarity(uint8_t polarity ) ;
uint8_t spi_get_interrupt_flag(void) ;
uint8_t spi_get_collision_flag(void) ;
uint8_t spi_send_data(uint8_t data) ;
