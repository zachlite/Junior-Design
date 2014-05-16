
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
   
   

   //toggle_bit(&PORTC, 5);
}




void play_game()
{

	unsigned char heading = 0;
	unsigned char scout_random = 0;
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



		  //turn_carrier_on();
		// attempt_to_communicate_with_beacon();
		// _delay_ms(10);


		 heading = get_heading_from_light_sensors();

		if (heading == LEFT)
		{
			//turn left 5 degrees
			//set_bit(SWITCH_PORT,LED_SWITCH_1);
			turn_left_by_angle(COURSE_ADJUSTMENT_ANGLE, false);
			

		}
		if (heading == RIGHT)
		{
			//turn right 5 degrees
			//set_bit(SWITCH_PORT,LED_SWITCH_1);
			turn_right_by_angle(COURSE_ADJUSTMENT_ANGLE, false);

		}

		if (heading == FORWARD)
		{
			//move foward 2 inches
			//blink_led(LED_SWITCH_1);
			move_forward_by_distance(COURSE_ADJUSTMENT_DISTANCE,true);


		}

		

		if (heading == NO_LIGHT) //will reaquire beacon if previously found but lost due to obstacle avoidance
		{
			//no lights seen.  go find one
			//blink_led(LED_SWITCH_1);

			if (scout_random % 2 == 1 || scout_random-1 % 2 == 1)
			{
				scout_random ++;
				turn_right_by_angle(SCOUT_AREA_ANGLE, false);
			}
			else
			{
				scout_random ++;

			turn_left_by_angle(SCOUT_AREA_ANGLE, false);
			}





			move_forward_by_distance(SCOUT_AREA_DISTANCE, true);
			//clear_bit(SWITCH_PORT,LED_SWITCH_1);
			
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
		if (heading != NO_LIGHT)
		{

			for (int i = 0; i < 10; ++i)
			{
				unsigned char comm_receive_and_send_successful = attempt_to_communicate_with_beacon();
				_delay_ms(10);
			}
			
		}

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




	


