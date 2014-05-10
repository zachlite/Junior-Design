
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
#include "obstacle_detection.h"
#include "stdbool.h"

//movement enumerations
#define Backward 0
#define Forward 1
#define Left 2
#define Right 3



#define ACCEL_THRESHOLD 10

#define DUTY_CYCLE_SMALL 40
#define DUTY_CYCLE_LARGE 255
#define SLIP_DISTANCE 1000
#define WheelCircumference 8.875

#define UnitOfMovement 1


#define EVADE_BACKUP_DISTANCE 2
#define EVADE_TURN_ANGLE 5 //was 15
#define EVADE_MOVE_FORWARD_DISTANCE 3

#define COURSE_ADJUSTMENT_ANGLE 1
#define COURSE_ADJUSTMENT_DISTANCE 1
#define SCOUT_AREA_ANGLE 2
#define SCOUT_AREA_DISTANCE 5



//high level - Public API
void turn_left();
void turn_right();
void turn_left_by_angle(unsigned short angle_to_turn, bool should_check_for_obstacles);
void turn_right_by_angle(unsigned short angle_to_turn, bool should_check_for_obstacles);
void turn_around();
void move_forward_by_distance(unsigned short distance_in_inches, bool should_check_for_obstacles);
void move_backward_by_distance(unsigned short distance_in_inches, bool should_check_for_obstacles); 
void stop();
void enable_motors();



//public motor initialization
void set_up_motors();

