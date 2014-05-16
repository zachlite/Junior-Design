
#include "hardware_interface.h"
#include "binary.h"


void blink_led(unsigned char SWITCH)
{
  set_bit(SWITCH_PORT,SWITCH);
  _delay_ms(10);
  clear_bit(SWITCH_PORT,SWITCH);


}

void flash_led()
{
	  set_bit(SWITCH_PORT,LED_SWITCH_1);

}

void led_off()
{
	clear_bit(SWITCH_PORT,LED_SWITCH_1);
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








