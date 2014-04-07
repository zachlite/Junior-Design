


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


//#include "uart_communications.h"
#include "carrier_wave.h"
#include "motors.h"
#include "inputoutput.h"
#include "binary.h"

#include "ir_comm.h"
#include "ADC.h"


#define input 0
#define output 1




int main(void) 
{



    initialize_io();
  

    

  
    // set_up_IR_communications();

    // unsigned char data_received, data_received_inverted;

    



    // while(1)
    // {
    //     data_received = uart_receive();

    //     data_received_inverted = ~data_received; 
        
    //     uart_transmit(data_received_inverted);

    // }

    

     //init_ADC();
     //run_ADC();





 



    

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
     enable_motors();
    // _delay_ms(2000);
    // stop_motors();




  
  
  	

 

  return 0;
}



