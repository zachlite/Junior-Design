#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
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
 *   PB6                  |9   20| AVCC              * 
 *   PB7                  |10  19| PB5               *
 *   PD5 - LED            |11  18| PB4               *
 *   PD6                  |12  17| PB3               *
 *   PD7                  |13  16| PB2               *
 *   PB0                  |14  15| PB1  carrier wave *
 *                         ------                    *
 *                                                   */




//define Data direction register

//MOTOR INTERFACE

//Right motor
#define Data_Direction_Register_D &DDRD
#define Data_Direction_Register_B &DDRB


//obstacle detection interface


//light sensor interface



//IR comm interface
 






#define Left_Motor_Enable 6
#define Left_Motor_Direction 5
#define Right_Motor_Enable 3
#define Right_Motor_Direction 4

#define Left_Motor_Port &PORTD
#define Right_Motor_Port &PORTB

#define Left_Motor_Pin &PIND
#define Right_Motor_Pin &PINB




void initialize_io(void);

void set_up_left_motor(void);
void set_up_right_motor(void);

void init_timer_pin(void);
