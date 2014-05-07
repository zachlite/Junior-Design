
/*

gameplay.c
high level gameplay

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "gameplay.h"



bool should_check_light_sensors;
unsigned char seconds_remaining;



//initialization
void init_game_timer()
{
// Set the Timer Mode to CTC
   TCCR0A |= (1 << WGM01);
   
   // Set the value that you want to count to
   //OCRn =  [ (clock_speed / Prescaler_value) * Desired_time_in_Seconds ] - 1
   //[ (8000000 / 256) * 1] -1
   OCR0A = 31249;  //1 second
   
   // start the timer
   TCCR0B |= (1 << CS02);
   // set prescaler to 256 and start the timer
   
   TIMSK0 |= (1 << OCIE0A);
   
   //sei is called in main
}


//does this need to be in the same file?
ISR(TIMER0_COMPA_vect)  //Execute this upon interrupt
{   
   
   //should_check_light_sensors = 1;

   //assuming this interrupt happens once per second
   // if (seconds_remaining > 0)
   // {
   // 		seconds_remaining -= 1;
   // }
   
   

   toggle_bit(&PORTC, 5);
}








void play_game()
{
	seconds_remaining = 185;

	unsigned char heading = 0;
	while(1)
	{


		/*
		 _ _       _     _                                      _                        _                   _   _             
		| (_) __ _| |__ | |_ ___  ___ _ __  ___  ___  _ __     | |__   __ _ ___  ___  __| |  _ __ ___   ___ | |_(_) ___  _ __  
		| | |/ _` | '_ \| __/ __|/ _ \ '_ \/ __|/ _ \| '__|____| '_ \ / _` / __|/ _ \/ _` | | '_ ` _ \ / _ \| __| |/ _ \| '_ \ 
		| | | (_| | | | | |_\__ \  __/ | | \__ \ (_) | | |_____| |_) | (_| \__ \  __/ (_| | | | | | | | (_) | |_| | (_) | | | |
		|_|_|\__, |_| |_|\__|___/\___|_| |_|___/\___/|_|       |_.__/ \__,_|___/\___|\__,_| |_| |_| |_|\___/ \__|_|\___/|_| |_|
		     |___/                                                                                                             
		*/		




		
		heading = get_heading_from_light_sensors();

		if (heading == LEFT)
		{
			//turn left 5 degrees
			set_bit(SWITCH_PORT,LED_SWITCH_1);
			turn_right_by_angle(COURSE_ADJUSTMENT_ANGLE);
			

		}
		if (heading == RIGHT)
		{
			//turn right 5 degrees
			set_bit(SWITCH_PORT,LED_SWITCH_1);
			turn_left_by_angle(COURSE_ADJUSTMENT_ANGLE);

		}

		if (heading == FORWARD)
		{
			//move foward 2 inches
			blink_led(LED_SWITCH_1);
			move_forward_by_distance(COURSE_ADJUSTMENT_DISTANCE);


		}

		if (heading == NO_LIGHT) //will reaquire beacon if previously found but lost due to obstacle avoidance
		{
			//no lights seen.  go find one
			//blink_led(LED_SWITCH_1);
			//turn_right_by_angle(SCOUT_AREA_ANGLE);
			move_forward_by_distance(SCOUT_AREA_DISTANCE);
			
		}







		/*
		 ____                                ____            _                  
		| __ )  ___  __ _  ___ ___  _ __    / ___|__ _ _ __ | |_ _   _ _ __ ___ 
		|  _ \ / _ \/ _` |/ __/ _ \| '_ \  | |   / _` | '_ \| __| | | | '__/ _ \
		| |_) |  __/ (_| | (_| (_) | | | | | |__| (_| | |_) | |_| |_| | | |  __/
		|____/ \___|\__,_|\___\___/|_| |_|  \____\__,_| .__/ \__|\__,_|_|  \___|
		                                              |_|                       
				
		*/


		//if light sensors lux values are high enough to detect, we might be in range of IR
		/*if (heading != NO_LIGHT)
		{
			bool comm_receive_and_send_successful = attempt_to_communicate_with_beacon();
			
			if (comm_receive_and_send_successful)
			{
				//in range.  double check capture was successful!
				unsigned char beacon_double_check = get_heading_from_light_sensors();
				if (beacon_double_check == NO_LIGHT)
				{
					//beacon captured! cool.
				}
				else
				{
					//try a few more times
					for (int i = 0; i < 3; i++)
					{
						attempt_to_communicate_with_beacon();
						if (get_heading_from_light_sensors() == NO_LIGHT)
						{
							//beacon finally captured
							break; // for
						}

					}
				}

			}
			
			//else out of range. try again next time.
			
		}*/

	}


}

void game_timer_test()
{
	seconds_remaining = 10;

	set_bit(&DDRC, 5);

	//while(seconds_remaining>0)
	//{/
		set_bit(&PORTC, 5);

	//}

	//clear_bit(&PORTC, 5);

}


		//check to make sure beacon was actually captured




		//call movement with a flag that says whether or not you've see a beacon


		//bool obstacle_detected_during_movement = false;

		//move foreward 5 inches
		//assign bool value there ^


		//what if motors were capable of avoiding obstacles on their own?
		//made recursive calls to turn, then move, then check again
		//if the recursive call is entered too many times, the obstacle is a wall, and the robot must turn around
		//should note direction traveling when obstacle was encountered




		//use light sensors as eyes that always move towards brightest light












	// 	if (hunt_for_beacon() == SUCCESS)
	// 	{
	// 		//navigate to light sensor
	// 	}
		
	// 	//else keep hunting

	// }



	// while(time less than 3 minutes)//game is running
	// {
	// 	//think of the priorities

	// 	if (lights visible)
	// 	{
	// 		navigate towards light. how???
	// 		if(obstacle detected)
	// 		{
	// 			navigate around obstacle
	// 		}


	// 	}

	// 	else
	// 	{
	// 		look for light

	// 	}

	// }


	 //for now, move until obstacle is detected, then turn and keep moving

	// unsigned char case;

	// case = move_until_interupted()
	
	// if (case == 1)//light detected
	// {
	// 	move_towards_and_capture_beacon();
	// }
	// else//obstacle detected
	// {
	// 	avoid_obstacle();
	// }






	


