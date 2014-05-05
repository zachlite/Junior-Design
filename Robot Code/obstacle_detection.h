
/*

obstacle_detection.h
measure Piezo sensor activity via ADCs

Written by Isaac Patka
Modified by Zach Lite
Spring 2014

Junior Design Project
Binghamton University

*/


#include "hardware_interface.h"

#include "binary.h"

//#define OBSTACLE_DETECTED 1
#define NO_OBSTACLE_DETECTED 4

#define LEFT_SENSOR 0
#define LEFT_MID_SENSOR 1
#define RIGHT_MID_SENSOR 2
#define RIGHT_SENSOR 3

#define CHANNEL_SENSITIVITY 100

/*Description*/

/*

//to be renamed ObstacleAvoidance.c/h

ADC is responsible for detecting an obstacle from 1 of the obstacle sensors
Now Just using ADC0, but will be extended to use 3 or 4


interrupts program execution and Returns the uint_8 
corresponding to the obstacle sensor that detected an obstacle




*/



//Public API
void init_ADC_for_obstacle_detection(void);
unsigned char check_for_obstacle(void); //returns channel number where obstacle was detected




