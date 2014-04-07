#include "carrier_wave.h"
#include "binary.h"



void set_up_IR_communications(void);
void set_up_uart(void);
void uart_transmit(unsigned char data);
unsigned char uart_receive();
void reverse_endianness_of_byte(unsigned char *byte);

