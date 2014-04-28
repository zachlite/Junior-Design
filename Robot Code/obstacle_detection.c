

//ADC0
#include <avr/io.h>
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


void init_ADC(void)
{

	init_test_pins();

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

unsigned char run_ADC_to_detect_obstacle(void)
{
	while(1)//try n times
	{
		int value = analog_read(0);

		if (value > 100)
		{
			set_bit(&PORTB, 1);
			return 1;
		}
		else
		{
			clear_bit(&PORTB, 1);

		}
	}

	return 0;

}




int analog_read(unsigned char channel)
{
    ADMUX &= 0xF0;  //clear previous channel
    ADMUX |= channel;   //define new adc channel
    ADCSRA |= (1 << ADSC); //start new conversion
    while( ADCSRA & (1 << ADSC));   //wait until conversion is done
    
    return ADCW;    //return 10 bit ADC reading
    
}






