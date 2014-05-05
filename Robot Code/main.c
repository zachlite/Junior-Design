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

        move_forward_by_distance(10);
        _delay_ms(1000);

        move_backward_by_distance(10);
        _delay_ms(1000);

        turn_left();
        _delay_ms(1000);
        
        turn_right();
        _delay_ms(1000);
    }
   

}




void light_sensor_test()
{






    set_bit(Data_Direction_Register_B,LED_SWITCH_1);
    //set_bit(Data_Direction_Register_C,LED_SWITCH_2);
    //uint8_t sensor_1_data = 0;
    //uint8_t sensor_2_data = 0;
    unsigned char heading;

    while(1)
    {
        /*sensor_2_data = read_light_sensor_i2c_soft();

        if (sensor_2_data > 0x05)
            set_bit(SWITCH_PORT,LED_SWITCH_2);

            else
                clear_bit(SWITCH_PORT,LED_SWITCH_2);

        sensor_1_data = read_light_sensor_i2c_hw();

        if (sensor_1_data > 0x05)
            set_bit(SWITCH_PORT,LED_SWITCH_1);
        else
                clear_bit(SWITCH_PORT,LED_SWITCH_1);*/

        heading = get_heading_from_light_sensors();

        /*if (heading == FORWARD)
        {
            set_bit(SWITCH_PORT,LED_SWITCH_1);
            set_bit(SWITCH_PORT,LED_SWITCH_2);
        }

        if (heading == LEFT)
        {
            set_bit(SWITCH_PORT,LED_SWITCH_2);
            clear_bit(SWITCH_PORT,LED_SWITCH_1);
        }

        if (heading == RIGHT)
        {

            clear_bit(SWITCH_PORT,LED_SWITCH_2);
            set_bit(SWITCH_PORT,LED_SWITCH_1);
        
        }
        
        if (heading == NO_LIGHT)
        {

            clear_bit(SWITCH_PORT,LED_SWITCH_1);
            clear_bit(SWITCH_PORT,LED_SWITCH_2);
        
        }*/

            if ((heading == FORWARD) || (heading == LEFT) || (heading == RIGHT))
                set_bit(SWITCH_PORT,LED_SWITCH_1);


            if (heading == NO_LIGHT)
        {

            clear_bit(SWITCH_PORT,LED_SWITCH_1);
        
        }
        /*else
        {

            blink_led(LED_SWITCH_1);
            blink_led(LED_SWITCH_2);
        }*/



    }

}




int main(void) 
{

    set_up_motors(); //from motors.h

    init_ADC_for_obstacle_detection(); //from obstacle_detection.h

    set_up_IR_communications(); //from ir_comm.h

    setup_light_sensor_i2c_soft();
    setup_light_sensor_i2c_hw();
    
    init_game_timer(); //from gameplay.h

    sei(); //from avr/interrupt.h

  
    //motor_demo();


    test_check_for_obstacle();

    //game_timer_test();
    //enable_motors();
    //play_game();
    //move_forward_by_distance(10);





  return 0;
}







//test light sensors
    //deterimine which light sensor is receiving a larger value


// void IR_test()
// {
//     unsigned char data_received, data_received_inverted;

//     while(1)
//     {
//         data_received = uart_receive();

//         data_received_inverted = ~data_received; 
        
//         uart_transmit(data_received_inverted);

//     }
// }


// void test_obstacle_sensor()
// {
//       run_ADC();
// }



// void motor_test()
// {
//     while(1)

//     {
//          move_forward_by_distance(5);
//         _delay_ms(1000);
//         move_backward_by_distance(5);
//         _delay_ms(1000); 
//     }


// }






