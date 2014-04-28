
#include <avr/io.h>
#include "hardware_interface.h"





void initialize_io(void)
{
	set_up_left_motor();
	set_up_right_motor();

    //return 0;
}


/*


       |     |
       |     |
       |     | 
       |     |
   PB7 |     |
   PD5 |     | PB4
   PD6 |     | PB3
   PD7 |     | PB2
   PB0 |_____| PB1



*/


//set bit initializes pin as output
//clearbit initializes pin as input

void set_up_left_motor(void)
{

    set_bit(Data_Direction_Reg_D, 5);//left motor direction direction
    set_bit(Data_Direction_Reg_D, 6);//left motor enable

    clear_bit(Data_Direction_Reg_D, 7);
    clear_bit(Data_Direction_Reg_B, 0);

    clear_bit(Data_Direction_Reg_B, 7);//set up pin 10 for left side obstacle detect
}


void set_up_right_motor(void)
{
    set_bit(Data_Direction_Reg_B, 4);//right motor direction
    set_bit(Data_Direction_Reg_B, 3);//right motor enable
  

    clear_bit(Data_Direction_Reg_B, 2);
    clear_bit(Data_Direction_Reg_B, 1);


}


void init_timer_pin()
{
    clear_bit(&DDRC, 5);   
}

