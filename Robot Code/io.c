
#include <avr/io.h>
#include "io.h"


void initialize_io(void)
{
	set_up_left_motor();
	set_up_right_motor();
}


void set_up_left_motor(void)
{

    set_bit(&DDRD, 5);
    set_bit(&DDRD, 6);

    clear_bit(&DDRD, 7);
    clear_bit(&DDRB, 0);

}


void set_up_right_motor(void)
{
    set_bit(&DDRB, 4);
    set_bit(&DDRB, 3);

    clear_bit(&DDRB, 2);
    clear_bit(&DDRB, 1);


}