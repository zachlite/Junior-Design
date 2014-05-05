
/*

obstacle_detection.c
measure Piezo sensor activity via ADCs

Written by Isaac Patka
Modified by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/


//ADC0
#include "obstacle_detection.h"


//Private API
void init_test_pins(void);
void init_analog_hardware();
int analog_read(unsigned char channel);




/*


 ___       _ _   
|_ _|_ __ (_) |_ 
 | || '_ \| | __|
 | || | | | | |_ 
|___|_| |_|_|\__|
                 
		


*/


void init_ADC_for_obstacle_detection(void)
{

	//init_test_pins();

	init_analog_hardware();

}




void init_test_pins(void)
{

	set_bit(&DDRB, 1); //set up PB1 as outout
	
}



void init_analog_hardware()
{
    //Set Prescaler to 128 -> ADC_freq = 62.5KHz
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
    ADCSRA &= ~(1 << ADPS0);
    
    //Set reference voltage to AVCC
    ADMUX |= (1 << REFS0);
    
    ADCSRA |= (1 << ADEN); //enable ADC
    ADCSRA |= (1 << ADSC);  //do an initial conversion because the first one will take 23 ADC clocks
    
}


/*

 ____                   _    ____   ____ 
|  _ \ _   _ _ __      / \  |  _ \ / ___|
| |_) | | | | '_ \    / _ \ | | | | |    
|  _ <| |_| | | | |  / ___ \| |_| | |___ 
|_| \_\\__,_|_| |_| /_/   \_\____/ \____|
                                         
		


*/

unsigned char check_for_obstacle(void)
{

				//need to check each channel

				//4 channels: 0, 1, 2, 3

			/*LIGHT SENSOR CHANNEL ORIENTATION

				    	forward

			  left	 0   1   2    3   right   

					   backward
				
			*/

	for (unsigned char channel = 0; channel < 4; channel++)
	{
		//check channel
		if (analog_read(channel) > CHANNEL_SENSITIVITY)
		{
			//obstacle detected on channel channel
			return channel; //channel refers to sensor number
		}
	}


	return NO_OBSTACLE_DETECTED;


}




int analog_read(unsigned char channel)
{
    ADMUX &= 0xF0;  //clear previous channel
    ADMUX |= channel;   //define new adc channel
    ADCSRA |= (1 << ADSC); //start new conversion
    while( ADCSRA & (1 << ADSC));   //wait until conversion is done
    
    return ADCW;    //return 10 bit ADC reading
    
}





/////////
//old analog read
	//To Do: set up global interrupt so adc checking runs in the background
	// while(1)//try n times
	// {
	// 	int value = analog_read(0);

	// 	if (value > 100)
	// 	{
	// 		//clear_bit(&PORTB, 1);
	// 		set_bit(&PORTB, 1);
	// 		//return OBSTACLE_DETECTED;
	// 	}
	// 	else
	// 	{
	// 		clear_bit(&PORTB, 1);

	// 	}
	// }

	// return NO_OBSTACLE_DETECTED;





