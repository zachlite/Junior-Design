

#include "hardware_interface.h"










void set_bit_value(volatile uint8_t * byte, unsigned char bit, unsigned char value);

uint16_t MAX3(uint16_t VAR1, uint16_t VAR2, uint16_t VAR3);


void setup_light_sensor_i2c_soft(void);

uint8_t read_light_sensor_i2c_hw(void);

void setup_light_sensor_i2c_hw(void);

uint8_t read_light_sensor_i2c_soft(void);