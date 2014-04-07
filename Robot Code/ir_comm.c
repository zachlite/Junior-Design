/*
 *  Isaac Patka & JD Team 9
 *  CLUE Summer 2013 JK Spring 2014
 *  Radiator Labs
 */

#define F_CPU 8000000UL
#include "avr/io.h"
#include <avr/interrupt.h>
#include "ir_comm.h"



/*                                                   *
 *                         ------                    *
 *   PC6 -                |1   28| PC5 -  SCL        *
 *   PD0 - RX             |2   27| PC4 -  SDA        *
 *   PD1 - TX             |3   26| PC3 -             *
 *   PD2 -                |4   25| PC2               *
 *   PD3 -                |5   24| PC1               *
 *   PD4 -                |6   23| PC0               *
 *   VCC                  |7   22| GND               *
 *   GND                  |8   21| AREF              *
 *   PB6                  |9   20| AVCC              * 
 *   PB7 -                |10  19| PB5 - SCK         * 
 *   PD5 -                |11  18| PB4 - MISO        *
 *   PD6 -                |12  17| PB3 - MOSI        *
 *   PD7 -                |13  16| PB2 - SS          *
 *   PB0 -                |14  15| PB1 - Room Temp   *
 *                         ------                    *
 *                                                   */
    
#define UBRR_300 1667//300 baud in UBBR



void set_up_IR_communications(void)
{
    set_up_IR_carrier();
    set_up_uart();
    sei();
}



void set_up_uart(void)
{
    unsigned int UBRR_value;
    

    
    UCSR0A &= ~(_BV(U2X0));
    
    UBRR_value = UBRR_300;       // // ( ( 8000000 ) / (16 * 19200)) - 1 According to the data sheet (page 192) the error is 0.2%
    UBRR0H = (unsigned char) (UBRR_value >> 8);
    UBRR0L = (unsigned char) UBRR_value;
    
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);     //8-bit data length
    
    //No parity set at this time
    
    UCSR0C &= ~(1 << USBS0);  //Sets 1 stop bit
    
    UCSR0B = (1 << RXEN0)  | (1 << TXEN0);   //Enable the receiver and transmitter
    
    
}

void uart_transmit(unsigned char data)
{
    //Pause until transmitter is ready
    while ( !(UCSR0A & (1 << UDRE0)) );
    
    //Transmit the data
    UDR0 = data;
    
}

unsigned char uart_receive()
{
    //Pause until RXC is nonzero
    while (!(UCSR0A & (1 << RXC0)));
    
    //Get data
    return UDR0;
    
}

void reverse_endianness_of_byte(unsigned char *byte)
{
    unsigned char temporary_byte = 0;

    for (int i = 0; i < 8; i++)
    {
        temporary_byte |= *byte & (1 << i);
    }

    *byte = 0b11111111;

    //and a byte with another byte and the only 1 is the bit you want to keep
    //shift to appropriate posiition


}














