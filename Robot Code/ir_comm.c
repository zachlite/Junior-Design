
/*

ir_comm.c
read and transmit IR data over UART

Written by Isaac Patka & JD Team 9
Modified by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/

#include "ir_comm.h"

typedef struct ir_status
{
    unsigned char data;
    bool successful;
}ir_status;


void set_up_uart(void);
void uart_transmit(unsigned char data);
ir_status uart_attempt_receive_for_seconds(int seconds);



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
 

/*
Do we guarantee that when we successfully 
communicate with beacon the beacon will be captured?
what happens if we successfully recieve, invert, and transmit a signal
but the beacon is not captured?
That is dealt with in a higher level.

*/

unsigned char attempt_to_communicate_with_beacon()
{
    //try to read IR signal for n seconds
    ir_status ir_packet_received;
    ir_packet_received = uart_attempt_receive_for_seconds(RECEIVE_TIMEOUT);

    if (ir_packet_received.successful)
    {
        //invert data and send
        ir_packet_received.data = ~ir_packet_received.data;
        uart_transmit(ir_packet_received.data); 
        return SUCCESSFUL_COMMUNICATION;
    }

    else
    {
        return UNSUCCESSFUL_COMMUNICATION;
    }


}



void set_up_IR_communications(void)
{
    set_up_IR_carrier();
    set_up_uart();
    //sei();
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

ir_status uart_attempt_receive_for_seconds(int seconds)
{

    
 
    int total_time = 0;

    ir_status packet;


    //Pause until RXC is nonzero
   
    while (!(UCSR0A & (1 << RXC0)))
    {
        //and break after waiting 1 for one second

        
        if (total_time > seconds)
        {
            packet.data = 0;
            packet.successful = false;
            return packet;
        }
        total_time++;
    }
    
    packet.data= UDR0;
    packet.successful = true;
    return packet;

    
}


//void reverse_endianness_of_byte(unsigned char *byte);

// void reverse_endianness_of_byte(unsigned char *byte)
// {
//     unsigned char temporary_byte = 0;

//     for (int i = 0; i < 8; i++)
//     {
//         temporary_byte |= *byte & (1 << i);
//     }

//     *byte = 0b11111111;

//     //and a byte with another byte and the only 1 is the bit you want to keep
//     //shift to appropriate posiition


// }














