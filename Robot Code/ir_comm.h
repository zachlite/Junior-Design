/*

ir_comm.h
read and transmit IR data over UART

Written by Isaac Patka & JD Team 9
Modified by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "hardware_interface.h"
#include "carrier_wave.h"
#include "binary.h"
#include <stdbool.h>
//#include <avr/interrupt.h>

#define SUCCESSFUL_COMMUNICATION 1;
#define UNSUCCESSFUL_COMMUNICATION 0;

#define UBRR_300 1667//300 baud in UBBR

#define RECEIVE_TIMEOUT 100

typedef struct ir_status
{
    unsigned char data;
    bool successful;
}ir_status;


//public API

//public initialization
void set_up_IR_communications(void);


//public IR operation

bool attempt_to_communicate_with_beacon();


