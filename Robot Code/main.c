/*

main.c
top-level robot control

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/




#include "main.h"


void motor_demo()
{

    while(1)
    { 

        // move_forward_by_distance(10, false);
        // _delay_ms(1000);

        // move_backward_by_distance(10, false);
        // _delay_ms(1000);

        turn_left();
        _delay_ms(3000);
        
        // turn_right();
        // _delay_ms(1000);
    }
   

}


void initialize_subsystems()
{
    set_up_motors(); //from motors.h

    init_ADC_for_obstacle_detection(); //from obstacle_detection.h

    set_up_IR_communications(); //from ir_comm.h

    setup_light_sensor_i2c_soft();
    setup_light_sensor_i2c_hw();
    
    sei(); //init global interrupts
}


int main(void) 
{

    initialize_subsystems();

    flash_led();
    _delay_ms(10000);
    led_off();

 
    play_game();



    return 0;
}




