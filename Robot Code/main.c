/*

main.c
top-level robot control

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/




//#include "hardware_interface.h"
#include "main.h"





void motor_demo()
{

    while(1)
    { 

        move_forward_by_distance(10, true);
        _delay_ms(1000);

        move_backward_by_distance(10, true);
        _delay_ms(1000);

        turn_left();
        _delay_ms(1000);
        
        turn_right();
        _delay_ms(1000);
    }
   

}







int main(void) 
{

    //set_up_motors(); //from motors.h

    //init_ADC_for_obstacle_detection(); //from obstacle_detection.h

    set_up_IR_communications(); //from ir_comm.h

    //setup_light_sensor_i2c_soft();
    //setup_light_sensor_i2c_hw();
    
    //init_game_timer(); //from gameplay.h

    sei(); //from avr/interrupt.h

    play_game();

    // while(1)
    // {
    //     turn_carrier_on();
    //     _delay_ms(2000);
    //     turn_carrier_off();
    //     _delay_ms(2000);

    // }

    //start_game();

    //motor_demo();
    //play_game();
    //motor_demo();
    

    //test_check_for_obstacle();

    //game_timer_test();
    //enable_motors();
    //play_game();
    //move_forward_by_distance(10);





  return 0;
}
