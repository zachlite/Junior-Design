
#define F_CPU 8000000UL

#include <avr/io.h>
#include "motors.h"
#include "binary.h"
#include "inputoutput.h"
#include <util/delay.h>

#define duty_cycle_small 150
#define duty_cycle_large 255
#define slip_distance 1000


//private API




//high level functions
//Public API
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
}

void turn_right_by_angle(unsigned short angle_to_turn)
{
	set_motor_directions_for_movement(Right);
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
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////





void set_motor_directions_for_movement(unsigned char type_of_movement)
{

	stop_motors();
	_delay_ms(5);

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



//low level
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
	unsigned char quad_encoder_signal_left, quad_encoder_signal_right;
    unsigned int left_ticks = 0; unsigned int right_ticks = 0;
    unsigned int quad_ticks = 0;


    //set pwm cycle at .5 for the first and last 5% of the distance to travel

    unsigned char duty_cycle = 0;
    unsigned char cycle_counter = 0;

    enable_motors();
	while (quad_ticks < distance_in_quad_ticks)
	{
	 	unsigned char last_signal_left, last_signal_right;
        last_signal_left = quad_encoder_signal_left;
        last_signal_right = quad_encoder_signal_right;
        
        quad_encoder_signal_left = get_quad_encoder_signal(Left_Motor_Pin, Right_Motor_Pin, 7, 0);
        quad_encoder_signal_right = get_quad_encoder_signal(Right_Motor_Pin, Right_Motor_Pin,2, 1);
	 
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

        // if (cycle_counter <= 254)
        // {

        //     toggle_bit(Right_Motor_Port, 7);


        // 	//if (motors_move_at_same_rate(&left_ticks, &right_ticks))
       	// 	//{

        // 	//}
        // 	enable_motors();
        // }

        // else
        // {
        // 	stop_motors();
        // }



        

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

	if (*left_ticks > *right_ticks)
	{
		stop_left_motor();
		enable_right_motor();

		return 0;
	}
	else if (*right_ticks > *left_ticks)
	{
		stop_right_motor();
		enable_left_motor();
		return 0;
	}
	else
	{
		enable_motors();
		return 1;
	}
}



int convert_inches_to_quad_ticks(unsigned short inches)
{
	return inches*100;
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














