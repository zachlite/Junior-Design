

//ADC0
#include <avr/io.h>
#include "ADC.h"

// void init_test_pins(void);
// void init_analog();
// int analog_read(unsigned char channel);

void run_ADC(void)
{
	while(1)
	{
		int value = analog_read(0);

		if (value > 100)
		{
			set_bit(&PORTB, 1);
		}
		else
		{
			clear_bit(&PORTB, 1);
		}
	}

}


void init_ADC(void)
{

	init_test_pins();

	



	//Configure ADC Hardware
	//clear_bit(&DDRC, 0); //Set up ADC0 as input

	init_analog_hardware();


	//Enable ADC


	//Start A to D conversions



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

int analog_read(unsigned char channel)
{
    ADMUX &= 0xF0;  //clear previous channel
    ADMUX |= channel;   //define new adc channel
    ADCSRA |= (1 << ADSC); //start new conversion
    while( ADCSRA & (1 << ADSC));   //wait until conversion is done
    
    return ADCW;    //return 10 bit ADC reading
    
}




void init_test_pins(void)
{

	set_bit(&DDRB, 1); //set up PB1 as outout
	
}
