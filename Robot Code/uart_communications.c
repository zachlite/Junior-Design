/**
 * EECE 252 Example Code
 * AVR Standard I/O over UART: Universal Asynchronous Receiver / Transmitter 
 *
 * Allows you to use printf/scanf using your AVR and a USB-to-serial converter,
 * like the Bus Pirate. If you're about to use this to gather debug information,
 * you might want to see if the Logic Analyzer isn't a better fit to your needs.
 */

//If you do not specify F_CPU at the compile time (e.g. on the GCC command line),
//assume 8MHz.
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

//If you do not specify BAUD at the compile time (e.g. on the GCC command line),
//assume 19.2k-baud.
#ifndef BAUD
#define BAUD 19200
#endif

#include <avr/io.h>
#include <util/setbaud.h>
#include <stdio.h>

#include "uart_communications.h"

#define USART_STATUS        UCSR0A
#define READY_TO_TRANSMIT   UDRE0
#define DATA_RECIEVED       RXC0

#define USE_EIGHT_BIT_DATA 

//Set up function: sets up stdin/stdout for use with printf/scanf.
static inline void set_up_special_files();

//Functions that wait for transmission or receipt to occur.
static void wait_until_ready_to_transmit();
static void wait_until_data_is_received();

//Low-level functions which directly modify the transmit/receieve buffers.
static void place_into_transmit_buffer(char c);
static inline char read_contents_of_receive_buffer();

//Special wrapper functions which allow use of this library with printf, scanf, and other stdio functions.
static inline int send_via_uart_stdio_compatible(char c, FILE * pipe_to_transmit_from);
static inline int receieve_via_uart_stdio_compatible(FILE * pipe_to_receive_into);

//Create an input and output "pipe" device, which can be used as stdin/out/error replacements.
static FILE uart_transmit_pipe = FDEV_SETUP_STREAM(send_via_uart_stdio_compatible, NULL, _FDEV_SETUP_WRITE);
static FILE uart_receive_pipe  = FDEV_SETUP_STREAM(NULL, receieve_via_uart_stdio_compatible, _FDEV_SETUP_READ);

/**
 * Sets up the device to use STDIO over serial.
 */
void set_up_stdio_over_serial() {
    initialize_uart();
    set_up_special_files();
}

/**
 * Sets up the raw UART (Universal Asynchronous Receiver/Transmitter) for general use.
 * Does not set up the UART for use with stdin/stdout/stderr.
 */
void initialize_uart() {

    //These values are automatically generated by <util/setbaud.h>
    //They're a tad 
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    #if USE_2X
      UCSR0A |= _BV(U2X0);
    #else
      UCSR0A &= ~(_BV(U2X0));
    #endif

    //Set up use of 8-bit data packets...  
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); 

    //And take ownership of the Rx/Tx lines on the AVR.
    UCSR0B = (1 << RXEN0)  | (1 << TXEN0);   
}

/**
 * Sends the provided character over the serial line.
 */
inline void send_via_uart(char c) {
  wait_until_ready_to_transmit();
  place_into_transmit_buffer(c);
}

/**
 * Waits for and recieves a single character over the serial line.
 *
 * This kind of function is known as a "blocking" function-- as execution
 * can't continue until it's complete!
 */ 
inline char receieve_via_uart() {
  wait_until_data_is_received();
  return read_contents_of_receive_buffer();
}

/**
 * Sets up the standard 'pipes' (stdio, stdout, and stderr) to transmit
 * over the serial line.
 */
static inline void set_up_special_files() {

  //Replace the standard output and standard error with our new transmission 
  //method. We treat the output and error identically, as we only have one line
  //with which to send data.
  stdout = stderr = &uart_transmit_pipe;

  //Replace the standard input with our new reciept method.
  stdin = &uart_receive_pipe;
}

/**
 * A wrapper for send_via_uart which is compatible with the standard I/O functions.
 */
static inline int send_via_uart_stdio_compatible(char character, FILE * output_file) {
 
  //The standard I/O functions end their line with '\n', but most serial terminals
  //expect \r\n. If we're about to send a \n, we interject a '\r' first.
  if(character == '\n') {
    send_via_uart('\r'); 
  }

  send_via_uart(character);

  return 1;
}

/**
 * A wrapper for receieve_via_uart which is compatible with the standard I/O functions.
 */
static inline int receieve_via_uart_stdio_compatible(FILE * input_file) {
  return receieve_via_uart();
}

/**
 * Places a single character directly into the transmit buffer,
 * initiating transmission.
 */ 
static inline void place_into_transmit_buffer(char c) {
    UDR0 = c; 
}

/**
 * Returns the current content of the recieve buffer,
 * and (indirectly) clears the read buffer.
 */ 
static inline char read_contents_of_receive_buffer() {
  return UDR0;
}

/**
 * Waits until the device is ready to transmit-- we may have to wait
 * if the device still is in the proces of transmitting data.
 */  
static inline void wait_until_ready_to_transmit() {
    loop_until_bit_is_set(USART_STATUS, READY_TO_TRANSMIT);
}


/**
 * Waits until we've recieved at least a single byte of data.
 */
static inline void wait_until_data_is_received() {
    loop_until_bit_is_set(USART_STATUS, DATA_RECIEVED);
}
