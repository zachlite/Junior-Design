// printer.h file
#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_

 // printer.h code goes here



#include "hardware_interface.h"
#include "stdbool.h"
#include "TWI_master.h"
#include "i2csoft.h"



static const unsigned char NO_LIGHT = 0;
static const unsigned char LEFT = 1;
static const unsigned char RIGHT = 2;
static const unsigned char FORWARD = 3;

/*
#define NO_LIGHT 0
#define LEFT 1
#define RIGHT 2
#define FORWARD 3*/



static const unsigned char LIGHT_SENSOR_DIFF_THRESHOLD = 0x03;	//needs to be tested DEBUG
static const unsigned char AMBIENT = 0x10;	//without reading lux this is the raw threshold of C0





unsigned char get_heading_from_light_sensors();

uint16_t MAX3(uint16_t VAR1, uint16_t VAR2, uint16_t VAR3);

void setup_light_sensor_i2c_soft(void);

uint8_t read_light_sensor_i2c_hw(void);

void setup_light_sensor_i2c_hw(void);

uint8_t read_light_sensor_i2c_soft(void);

#endif

