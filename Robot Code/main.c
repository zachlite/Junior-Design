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








int main(void) 
{

    set_up_motors(); //from motors.h

    init_ADC_for_obstacle_detection(); //from obstacle_detection.h

    set_up_IR_communications(); //from ir_comm.h

    setup_light_sensor_i2c_soft();
    setup_light_sensor_i2c_hw();
    //init light sensors

    init_game_timer(); //from gameplay.h

    sei(); //from avr/interrupt.h

    //motor_demo();
  
    motor_demo();

<<<<<<< HEAD
    //game_timer_test();
    //enable_motors();
    //play_game();
    //move_forward_by_distance(10);
=======


    //play_game();
>>>>>>> daf54bd420d0d6fa45aa7346a957a8fcdf6b685f


    //initialize_io();
    //set_up_IR_communications();
    //init_ADC();
    //sei(); after all timer set up




    //run_ADC_to_detect_obstacle();


    // set_up_motors();
    // move_forward_by_distance(20);

    // set_up_IR_communications();


    // bool value;
    // value = attempt_to_communicate_with_beacon();


    // while(1)
    // {
    //     //move_based_on_conditions() param 1: direction, param2: distance
    //     //move_forward_by_distance(1);
    //     if (flag_set_to_poll_light_sensors)
    //     {
    //         //poll light sensors
    //         if (beacon_detected)
    //         {
    //             //set_ir_comm_flag;
    //         }

    //     }

    //     if (if_comm_flag)
    //     {
    //         attempt_to_communicate_with_beacon();
    //     }

    // }
 

    set_bit(Data_Direction_Register_C,LED_SWITCH_1);
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





    //test program will run motors
    //and in background communicate with beacon
    //detect obstacles
    //and measure light sensors all in background


    

    // unsigned char obstacle_sensor = 0;

    // while(1)
    // {
    //     obstacle_sensor = read_bit(*Right_Motor_Pin, 7);
    //     if (!obstacle_sensor)
    //     {
    //       break;
    //     }
    // }
 

    // set_bit(&DDRC, 5);

    // set_bit(&PORTC, 5);

    //motor_demo();
    //set_bit(&DDRD, 2);

    // while(1)
    // {
    //         // set_bit(&PORTD, 2);
    //         // set_bit()
    //         enable_motors();
    
    // }


    //enable_motors();




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






