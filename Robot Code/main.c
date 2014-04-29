/*

main.c
top-level robot control

Written by Zach Lite
Spring 2014

Junior Design Project
Binghamton University


*/



#include "hardware_interface.h"
#include "ir_comm.h"
#include <stdbool.h>
//#include "obstacle_detection.h"





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



int main(void) 
{



    //initialize_io();
    //set_up_IR_communications();
    //init_ADC();




    //run_ADC_to_detect_obstacle();


    // set_up_motors();
    // move_forward_by_distance(20);

    set_up_IR_communications();


    bool value;
    value = attempt_to_communicate_with_beacon();
 



    

    // unsigned char obstacle_sensor = 0;

    // while(1)
    // {
    //     obstacle_sensor = read_bit(*Right_Motor_Pin, 7);
    //     if (!obstacle_sensor)
    //     {
    //       break;
    //     }
    // }

    // _delay_ms(20);
    // set_motor_directions_for_movement(Backward);
     //enable_motors();
    // _delay_ms(2000);
    // stop_motors();




  return 0;
}



