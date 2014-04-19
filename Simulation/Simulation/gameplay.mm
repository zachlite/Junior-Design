//
//  gameplay.c
//  Simulation
//
//  Created by Zach Lite on 4/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include <stdio.h>
#include "gameplay.h"

//include motors, ir, lights, and obstacle adc



unsigned char move_until_interrupted();
void move_towards_and_capture_beacon();//will we know distance?
void turn_towards_direction_of_beacon();
void avoid_obstacle();//eventually navigate around obstacle?



void PlayGame()
{
    
    unsigned char situation;
    
    situation = move_until_interrupted();
	
//	if (situation == 1)//light detected
//	{
//		move_towards_and_capture_beacon();
//	}
//	else//obstacle detected
    if (situation == 2)
    {
        avoid_obstacle();
    }
	
    //turn_right_by_angle(1);
    //turn_left_by_angle(15);
    //RotateRobot();
}





#define UnitOfMovement 5//pixels




unsigned char move_until_interrupted()
{
        //move_backward_by_distance(UnitOfMovement);
		
   
        move_forward_by_distance(UnitOfMovement);//inches

    
    //SDL_Delay(1000);
//		if (light_detected())//from LightSensors
//		{
//			return 1;
//		}
		if (obstacle_detected())//from ADC.c
		{
            
            NSLog(@"obstacle detected!");
			return 2;
		}
        
	return 0;
    
}

void move_towards_and_capture_beacon()//will we know distance?
{
	while(!beacon_captured())//its easier to determine a change in color of light than track distance to beacon approach
	{//from IRComm.c ^
        
        
		turn_towards_direction_of_beacon();
		move_forward_by_distance(UnitOfMovement);
        
		if (obstacle_detected())//from ADC.c
		{
			avoid_obstacle();
		}
        
        
		capture_beacon();//from IRComm.c
        
	}
    
    
    
}

void turn_towards_direction_of_beacon()
{
	//for now do nothing
    
    
}

void avoid_obstacle()//eventually navigate around obstacle?
{
	move_backward_by_distance(UnitOfMovement);
    //SDL_Delay(500);
    for (int i = 0; i < 90 ; i++)
    {
        turn_right_by_angle(1);

    }
    //SDL_Delay(500);
    
}

