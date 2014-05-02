#include "light_sensors.h"


light_sensor_reading read_light_sensors();



unsigned char get_heading_from_light_sensors()
{

	/*
						   /\ foreward
 			LS1    LS2     |
						   |
						   |
						   |
						   |


	*/

	light_sensor_reading sensor_value = read_light_sensors();//from light_sensor.h
	//read_light_sensors should only return values if at least one lux value is above ambient (TBD)

	if (sensor_value.is_valid)
	{
			if (abs(sensor_value.LS_1_Lux - sensor_value.LS_2_Lux) < LIGHT_SENSOR_DIFF_THRESHOLD)
			{
				return FORWARD;
			}
			else if (sensor_value.LS_1_Lux > sensor_value.LS_2_Lux)
			{
				return LEFT;
			}
			else
			{
				return RIGHT;
			}
	}

	else
	{
		return NO_LIGHT; // no lights seen
	}	

}


//Isaac's function
light_sensor_reading read_light_sensors()
{
	
	light_sensor_reading sensor_data;




	//light sensor 1
	sensor_data.LS_1_Lux = 1532;//sensor1lux;

	//light sensor 2
	sensor_data.LS_2_Lux = 1765;//sensor2lux;

	if (sensor_data.LS_1_Lux > AMBIENT || sensor_data.LS_2_Lux > AMBIENT)
	{
		sensor_data.is_valid = true;
	}
	else
	{
		sensor_data.is_valid = false;
	}


	return sensor_data;

}






