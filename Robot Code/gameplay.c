
/*

gameplay.c
high level gameplay

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


#include "gameplay.h"


void PlayGame()
{

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

	unsigned char case;

	case = move_until_interupted()
	
	if (case == 1)//light detected
	{
		move_towards_and_capture_beacon();
	}
	else//obstacle detected
	{
		avoid_obstacle();
	}






	

}
