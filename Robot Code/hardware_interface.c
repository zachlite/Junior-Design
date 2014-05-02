
#include "hardware_interface.h"



void blink_led(unsigned char SWITCH)
{
  set_bit(SWITCH_PORT,SWITCH);
  _delay_ms(125);
  clear_bit(SWITCH_PORT,SWITCH);
  _delay_ms(125);


}



// void initialize_io(void)
// {
// 	set_up_left_motor();
// 	set_up_right_motor();

//     //return 0;
// }





//        |     |
//        |     |
//        |     | 
//        |     |
//    PB7 |     |
//    PD5 |     | PB4
//    PD6 |     | PB3
//    PD7 |     | PB2
//    PB0 |_____| PB1








