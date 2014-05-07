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
    set_bit(Data_Direction_Register_B,LED_SWITCH_1);

    setup_light_sensor_i2c_soft();
    setup_light_sensor_i2c_hw();
    //init light sensors

    init_game_timer(); //from gameplay.h

    sei(); //from avr/interrupt.h*/

    play_game();


//set_bit(Data_Direction_Register_B,LED_SWITCH_1);

    //play_game();


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
 

    set_bit(Data_Direction_Register_B,LED_SWITCH_1);
    //set_bit(Data_Direction_Register_C,LED_SWITCH_2);
    //uint8_t sensor_1_data = 0;
    //uint8_t sensor_2_data = 0;
    unsigned char heading;

    //unsigned char status;

    //while(1)
    //{

        /*status = attempt_to_communicate_with_beacon();

        if (status == SUCCESSFUL_COMMUNICATION)
            set_bit(SWITCH_PORT,LED_SWITCH_1);

        else if (status == UNSUCCESSFUL_COMMUNICATION)
            clear_bit(SWITCH_PORT,LED_SWITCH_1);*/


       

       /* heading = get_heading_from_light_sensors();

        

            


            if (heading == FORWARD)
                blink_led(LED_SWITCH_1);

            if (heading == RIGHT)
                set_bit(SWITCH_PORT,LED_SWITCH_1);

            if(heading == LEFT)
                set_bit(SWITCH_PORT,LED_SWITCH_1);


            if (heading == NO_LIGHT)
                clear_bit(SWITCH_PORT,LED_SWITCH_1);*/
        
        



    //}





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






