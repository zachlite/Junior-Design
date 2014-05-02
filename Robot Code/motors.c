
/*

motors.c
Motor initialization and operation

Written by Isaac Patka and Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "motors.h"





//private API

void set_motor_directions_for_movement(unsigned char type_of_movement);
void set_left_motor_direction(unsigned char direction);
void set_right_motor_direction(unsigned char direction);



void enable_left_motor();
void enable_right_motor();
void stop_motors();
void stop_left_motor();
void stop_right_motor();
void move_distance(unsigned int distance_in_quad_ticks);
unsigned char motors_move_at_same_rate(unsigned int *left_ticks, unsigned int *right_ticks);
void get_duty_cycle(unsigned int distance, unsigned int quad_ticks, unsigned char *duty_cycle);

int convert_degrees_to_quad_ticks(unsigned short degrees);
int convert_inches_to_quad_ticks(unsigned short inches);

void evade_obstacle(unsigned char obsacle_sensor_number_triggered);


/*

             _     _ _          _     _       _           _                _ 
 _ __  _   _| |__ | (_) ___ _  | |__ (_) __ _| |__       | | _____   _____| |
| '_ \| | | | '_ \| | |/ __(_) | '_ \| |/ _` | '_ \ _____| |/ _ \ \ / / _ \ |
| |_) | |_| | |_) | | | (__ _  | | | | | (_| | | | |_____| |  __/\ V /  __/ |
| .__/ \__,_|_.__/|_|_|\___(_) |_| |_|_|\__, |_| |_|     |_|\___| \_/ \___|_|
|_|                                     |___/                                
		
simulation-portable

*/


// unsigned char move_until_interrupted()
// {
// 	while(1)
// 	{
// 		move_forward_by_distance(UnitOfMovement);//inches
// 		if (light_detected())//from LightSensors
// 		{
// 			return 1;
// 		}
// 		if (obstacle_detected())//from ADC.c
// 		{
// 			return 2;
// 		}

// 	}

// }

// unsigned char move_towards_and_capture_beacon()//will we know distance?
// {
// 	while(!beacon_captured())//its easier to determine a change in color of light than track distance to beacon approach
// 	{//from IRComm.c ^


// 		turn_towards_direction_of_beacon();
// 		move_forward_by_distance(UnitOfMovement)

// 		if (obstacle_detected())//from ADC.c
// 		{
// 			avoid_obstacle();
// 		}


// 		capture_beacon();//from IRComm.c

// 	}


// }

// void turn_towards_direction_of_beacon()
// {
// 	//for now do nothing


// }

// void avoid_obstacle()//eventually navigate around obstacle?
// {
// 	move_backward_by_distance(3);
// 	turn_right_by_angle(15);

// }


/*
                    _ _                       _                _ 
 _ __ ___   ___  __| (_)_   _ _ __ ___       | | _____   _____| |
| '_ ` _ \ / _ \/ _` | | | | | '_ ` _ \ _____| |/ _ \ \ / / _ \ |
| | | | | |  __/ (_| | | |_| | | | | | |_____| |  __/\ V /  __/ |
|_| |_| |_|\___|\__,_|_|\__,_|_| |_| |_|     |_|\___| \_/ \___|_|
                                                                 


*/
//need simulation replacements for these functions


void turn_left()
{
	turn_left_by_angle(90);	
}

void turn_right()
{
	turn_right_by_angle(90);
}

void turn_left_by_angle(unsigned short angle_to_turn)
{
	set_motor_directions_for_movement(Left);

	int angle_in_quad_ticks = convert_degrees_to_quad_ticks(angle_to_turn);

	move_distance(angle_in_quad_ticks);
}

void turn_right_by_angle(unsigned short angle_to_turn)
{
	set_motor_directions_for_movement(Right);
	int angle_in_quad_ticks = convert_degrees_to_quad_ticks(angle_to_turn);

	move_distance(angle_in_quad_ticks);
}

void turn_around()
{
	turn_right_by_angle(180);
}

void move_forward_by_distance(unsigned short distance_in_inches)
{
	
	set_motor_directions_for_movement(Forward);
	//convert inches to quad encoder ticks

	unsigned int distance_in_quad_ticks = convert_inches_to_quad_ticks(distance_in_inches);

	move_distance(distance_in_quad_ticks);

	//run motors at the same rate until number of ticks has been reached
		//motor speed is slow at the beginning, becomming constant, and slows at the end.

}

void move_backward_by_distance(unsigned short distance_in_inches)
{
	set_motor_directions_for_movement(Backward);

	unsigned int distance_in_quad_ticks = convert_inches_to_quad_ticks(distance_in_inches);

	move_distance(distance_in_quad_ticks);
}

void stop()
{
	stop_motors();
}


/*
       _         _             _                         _     _                      
  ___ | |__  ___| |_ __ _  ___| | ___    __ ___   _____ (_) __| | __ _ _ __   ___ ___ 
 / _ \| '_ \/ __| __/ _` |/ __| |/ _ \  / _` \ \ / / _ \| |/ _` |/ _` | '_ \ / __/ _ \
| (_) | |_) \__ \ || (_| | (__| |  __/ | (_| |\ V / (_) | | (_| | (_| | | | | (_|  __/
 \___/|_.__/|___/\__\__,_|\___|_|\___|  \__,_| \_/ \___/|_|\__,_|\__,_|_| |_|\___\___|
                                                                                      
		
*/



void evade_obstacle(unsigned char obsacle_sensor_number_triggered)
{
	//need to know direction to turn based on obstacle sensor triggered
	//based on clock rate, only one sensor will be triggered at a time 

	move_backward_by_distance(EVADE_BACKUP_DISTANCE);

	if (obsacle_sensor_number_triggered == LEFT_SENSOR)
	{
		//assume obstacle to left
		//bear right
		turn_right_by_angle(EVADE_TURN_ANGLE);
	}
	else if (obsacle_sensor_number_triggered == LEFT_MID_SENSOR)
	{
		//assume obstacle to left
		//bear right
		turn_right_by_angle(EVADE_TURN_ANGLE);
	}
	else if (obsacle_sensor_number_triggered == RIGHT_MID_SENSOR)
	{
		
		
		//assume obstacle to right
		//bear left
		turn_left_by_angle(EVADE_TURN_ANGLE);
		
	
	}
	else //right sensor
	{
		//assume obstacle to right
		// bear left
		turn_left_by_angle(EVADE_TURN_ANGLE);

	}

	move_forward_by_distance(EVADE_MOVE_FORWARD_DISTANCE); //ensures you fully clear the obstacle
}








/*

            _            _           _                    _                _ 
 _ __  _ __(_)_   ____ _| |_ ___ _  | | _____      __    | | _____   _____| |
| '_ \| '__| \ \ / / _` | __/ _ (_) | |/ _ \ \ /\ / /____| |/ _ \ \ / / _ \ |
| |_) | |  | |\ V / (_| | ||  __/_  | | (_) \ V  V /_____| |  __/\ V /  __/ |
| .__/|_|  |_| \_/ \__,_|\__\___(_) |_|\___/ \_/\_/      |_|\___| \_/ \___|_|
|_|                                                                          
		


*/





void set_motor_directions_for_movement(unsigned char type_of_movement)
{

	stop_motors();
	_delay_ms(50);

	if (type_of_movement == Backward)
	{
		set_left_motor_direction(Backward);
		set_right_motor_direction(Backward);
	}
	else if (type_of_movement == Forward)
	{
		set_left_motor_direction(Forward);
		set_right_motor_direction(Forward);
	}
	else if (type_of_movement == Left)
	{
		set_left_motor_direction(Backward);
		set_right_motor_direction(Forward);
	}
	else if (type_of_movement == Right)
	{
		set_left_motor_direction(Forward);
		set_right_motor_direction(Backward);
	}
}




void set_left_motor_direction(unsigned char direction)
{
	if (direction == Forward)
	{	
		//should spin forwards
		set_bit(Left_Motor_Port, Left_Motor_Direction);

	}
	else
	{
		//should spin backwards
		clear_bit(Left_Motor_Port, Left_Motor_Direction);

	}


}
void set_right_motor_direction(unsigned char direction)
{

	if (direction == Forward)
	{	
		//should spin forwards
		clear_bit(Right_Motor_Port, Right_Motor_Direction);

	}
	else
	{
		//should spin backwards
		set_bit(Right_Motor_Port, Right_Motor_Direction);

	}
}


void enable_motors()
{
	set_bit(Right_Motor_Port, Right_Motor_Enable);
	set_bit(Left_Motor_Port, Left_Motor_Enable);

}
void enable_left_motor()
{
	set_bit(Left_Motor_Port, Left_Motor_Enable);
}

void enable_right_motor()
{
	set_bit(Right_Motor_Port, Right_Motor_Enable);

}


void stop_motors()
{
	clear_bit(Left_Motor_Port, Left_Motor_Enable);
	clear_bit(Right_Motor_Port, Right_Motor_Enable);
	_delay_ms(150);
}


void stop_left_motor()
{
	clear_bit(Left_Motor_Port, Left_Motor_Enable);
}

void stop_right_motor()
{
	clear_bit(Right_Motor_Port, Right_Motor_Enable);

}



void move_distance(unsigned int distance_in_quad_ticks)
{
	// set_bit(&DDRC, 5);
	// set_bit(&DDRC, 4); debug purposes


	unsigned char quad_encoder_signal_left;
	unsigned char quad_encoder_signal_right;
    unsigned int left_ticks = 0; 
    unsigned int right_ticks = 0;
    unsigned int quad_ticks = 0;

    unsigned char last_signal_left, last_signal_right;

    //set pwm cycle at .5 for the first and last 5% of the distance to travel

    //unsigned char duty_cycle = 0;
    unsigned char cycle_counter = 0;

    enable_motors();


    unsigned char obsacle_sensor_number_triggered;
	while (quad_ticks < distance_in_quad_ticks)
	{



		//obstacle avoidance check and recursion:
		obsacle_sensor_number_triggered = check_for_obstacle();
		if (obsacle_sensor_number_triggered != NO_OBSTACLE_DETECTED)
		{
			evade_obstacle(obsacle_sensor_number_triggered);
		}
		else
		{
			//no obstacle
		}





	 	last_signal_left = quad_encoder_signal_left;
        last_signal_right = quad_encoder_signal_right;
        
        
        quad_encoder_signal_left = get_quad_encoder_signal(Left_Motor_Pin, Left_Motor_Quad_A, Left_Motor_Quad_B);
        quad_encoder_signal_right = get_quad_encoder_signal(Right_Motor_Pin, Right_Motor_Quad_A, Right_Motor_Quad_B);
	 
        if (quad_encoder_signal_left != last_signal_left)
        {
            left_ticks++;

        }
        
        if (quad_encoder_signal_right != last_signal_right)
        {
            right_ticks++;

           
        }

        //get_duty_cycle(distance_in_quad_ticks, quad_ticks, &duty_cycle);

       
        motors_move_at_same_rate(&left_ticks, &right_ticks);

      
       
    



        if (right_ticks >= quad_ticks && left_ticks >= quad_ticks)
        {
        	quad_ticks++;

        }
	 	

        cycle_counter++;


        
	}


	stop_motors();



}

unsigned char motors_move_at_same_rate(unsigned int *left_ticks, unsigned int *right_ticks)
{

	if(*right_ticks > *left_ticks)
	{
		stop_right_motor();
		enable_left_motor();
		return 0;
	}	
	if (*left_ticks > *right_ticks)//this is happening A LOT.  the left motor is stopping a lot.
	{
		stop_left_motor();
		enable_right_motor();

		return 0;
	}
	
		enable_motors();
		return 1;
	
}



int convert_inches_to_quad_ticks(unsigned short inches)
{
	return inches*100;
}

int convert_degrees_to_quad_ticks(unsigned short degrees)
{
	return degrees*2;
}



void get_duty_cycle(unsigned int distance, unsigned int quad_ticks, unsigned char *duty_cycle)
{
	if (quad_ticks < slip_distance || quad_ticks > distance - slip_distance)
	{
		*duty_cycle = duty_cycle_small;
	}
	else
	{
		*duty_cycle = duty_cycle_large;
	}
}


/*
//                  _                        _                 
//  _ __ ___   ___ | |_ ___  _ __   ___  ___| |_   _   _ _ __  
// | '_ ` _ \ / _ \| __/ _ \| '__| / __|/ _ \ __| | | | | '_ \ 
// | | | | | | (_) | || (_) | |    \__ \  __/ |_  | |_| | |_) |
// |_| |_| |_|\___/ \__\___/|_|    |___/\___|\__|  \__,_| .__/ 
//                                                      |_|    
*/
//set bit initializes pin as output
//clearbit initializes pin as input
void set_up_right_motor()
{
	set_bit(Data_Direction_Register_B, Right_Motor_Enable);
    set_bit(Data_Direction_Register_B, Right_Motor_Direction);
 

    clear_bit(Data_Direction_Register_B, Right_Motor_Quad_A);
    clear_bit(Data_Direction_Register_B, Right_Motor_Quad_B);

}
void set_up_left_motor()
{
	set_bit(Data_Direction_Register_D, Left_Motor_Enable);
    set_bit(Data_Direction_Register_D, Left_Motor_Direction);


    clear_bit(Data_Direction_Register_D, Left_Motor_Quad_A);
    clear_bit(Data_Direction_Register_D, Left_Motor_Quad_B);
}


void set_up_motors()
{
	set_up_right_motor();
	set_up_left_motor();


}













