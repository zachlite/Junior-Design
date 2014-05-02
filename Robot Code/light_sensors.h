#include "hardware_interface.h"
#include "stdbool.h"
#include "TWI_master.h"
#include "i2csoft.h"



#define NO_LIGHT 0
#define LEFT 1
#define RIGHT 2
#define FORWARD 3



#define LIGHT_SENSOR_DIFF_THRESHOLD 0x02	//needs to be tested DEBUG
#define AMBIENT 0x10	//without reading lux this is the raw threshold of C0





unsigned char get_heading_from_light_sensors();

uint16_t MAX3(uint16_t VAR1, uint16_t VAR2, uint16_t VAR3);

void setup_light_sensor_i2c_soft(void);

uint8_t read_light_sensor_i2c_hw(void);

void setup_light_sensor_i2c_hw(void);

uint8_t read_light_sensor_i2c_soft(void);

