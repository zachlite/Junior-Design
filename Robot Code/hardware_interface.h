
/*

hardware_interface.h
hardware interfacing constants and dependencies

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
//#include "time.h"
// #include "binary.h"


/*                                                   *
 *                         ------                    *
 *   PC6                  |1   28| PC5 -  SCL        *
 *   PD0                  |2   27| PC4 -  SDA        *
 *   PD1                  |3   26| PC3               *
 *   PD2                  |4   25| PC2               *
 *   PD3                  |5   24| PC1               *
 *   PD4                  |6   23| PC0               *
 *   VCC                  |7   22| GND               *
 *   GND                  |8   21| AREF              *
 *   PB6            e      |9   20| AVCC              * 
 *   PB7                  |10  19| PB5               *
 *   PD5 - LED            |11  18| PB4               *
 *   PD6                  |12  17| PB3               *
 *   PD7                  |13  16| PB2               *
 *   PB0                  |14  15| PB1  carrier wave *
 *                         ------                    *
 *                                                   */




//define Data direction register
#define Data_Direction_Register_D &DDRD
#define Data_Direction_Register_B &DDRB
#define Data_Direction_Register_C &DDRC
//MOTOR INTERFACE

//Right motor - D
#define Right_Motor_Port &PORTB
#define Right_Motor_Pin &PINB
#define Right_Motor_Enable 5
#define Right_Motor_Direction 4
#define Right_Motor_Quad_A 3
#define Right_Motor_Quad_B 2

//Left Motor - B
#define Left_Motor_Port &PORTD
#define Left_Motor_Pin &PIND
#define Left_Motor_Enable 2 
#define Left_Motor_Direction 3
#define Left_Motor_Quad_A 5
#define Left_Motor_Quad_B 6

 //Debugging LED
#define SWITCH_PORT &PORTB
#define LED_SWITCH_1 0






//obstacle detection interface
#define Obstacle_Detection_Channel_0 0 //this is the channel number
#define Obstacle_Detection_Channel_1 1 
#define Obstacle_Detection_Channel_2 2 
#define Obstacle_Detection_Channel_3 3 
#define Obstacle_Detection_Channel_4 4
#define Obstacle_Detection_Channel_5 5 

//light sensor interface



//IR comm interface
//square wave
#define Square_Wave_Pin PB1

void blink_led(unsigned char SWITCH);
 
#endif
