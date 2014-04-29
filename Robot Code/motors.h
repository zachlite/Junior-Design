
/*

motors.h
Motor initialization and operation

Written by Isaac Patka and Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "hardware_interface.h"
#include "binary.h"

//movement enumerations
#define Backward 0
#define Forward 1
#define Left 2
#define Right 3


#define duty_cycle_small 150
#define duty_cycle_large 255
#define slip_distance 1000
#define WheelCircumference 8.875

#define UnitOfMovement 1


//high level - Public API
void turn_left();
void turn_right();
void turn_left_by_angle(unsigned short angle_to_turn);
void turn_right_by_angle(unsigned short angle_to_turn);
void turn_around();
void move_forward_by_distance(unsigned short distance_in_inches);
void move_backward_by_distance(unsigned short distance_in_inches); 
void stop();



//public motor initialization
void set_up_motors();

