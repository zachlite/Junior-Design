
/*

gameplay.c
high level gameplay

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include "hardware_interface.h"
#include "stdbool.h"
#include "motors.h"
#include "ir_comm.h"
#include "light_sensors.h"





void play_game();



//initialization
void init_game_timer();



#endif

//check for obstacle on every cycle of motor movement - easy

//check for beacon