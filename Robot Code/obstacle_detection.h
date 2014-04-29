
/*

obstacle_detection.h
measure Piezo sensor activity via ADCs

Written by Isaac Patka
Modified by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "binary.h"

/*Description*/

/*

//to be renamed ObstacleAvoidance.c/h

ADC is responsible for detecting an obstacle from 1 of the obstacle sensors
Now Just using ADC0, but will be extended to use 3 or 4


interrupts program execution and Returns the uint_8 
corresponding to the obstacle sensor that detected an obstacle




*/



//Public ADC API
void init_ADC(void);
unsigned char run_ADC_to_detect_obstacle(void);



