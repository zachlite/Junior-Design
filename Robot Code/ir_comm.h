/*

ir_comm.h
read and transmit IR data over UART

Written by Isaac Patka & JD Team 9
Modified by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/

#ifndef IR_COMM_H
#define IR_COMM_H
#include "hardware_interface.h"
#include "carrier_wave.h"
#include "binary.h"
#include <stdbool.h>
//#include <avr/interrupt.h>

static const unsigned char SUCCESSFUL_COMMUNICATION = 1;
static const unsigned char UNSUCCESSFUL_COMMUNICATION = 0;

#define UBRR_300 1667//300 baud in UBBR

#define RECEIVE_TIMEOUT 160




//public API

//public initialization
void set_up_IR_communications(void);


//public IR operation

unsigned char attempt_to_communicate_with_beacon();
#endif


