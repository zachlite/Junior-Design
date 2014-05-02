#include "hardware_interface.h"
#include "stdbool.h"



#define NO_LIGHT 0
#define LEFT 1
#define RIGHT 2
#define FORWARD 3



#define LIGHT_SENSOR_DIFF_THRESHOLD 100
#define AMBIENT 1000


typedef struct light_sensor_reading
{
	short LS_1_Lux;
	short LS_2_Lux;
	bool is_valid;

} light_sensor_reading;


unsigned char get_heading_from_light_sensors();


