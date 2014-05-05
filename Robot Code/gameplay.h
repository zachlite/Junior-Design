
/*

gameplay.c
high level gameplay

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "hardware_interface.h"
#include "stdbool.h"
#include "motors.h"
#include "ir_comm.h"
#include "light_sensors.h"
#include "binary.h"




void play_game();



//initialization
void init_game_timer();


//test
void game_timer_test();




//check for obstacle on every cycle of motor movement - easy

//check for beacon