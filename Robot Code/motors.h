
#include <stdio.h>

#define Backward 0
#define Forward 1
#define Left 2
#define Right 3

#define WheelCircumference 8.875

//high level - Public API
void turn_left();
void turn_right();
void turn_left_by_angle(unsigned short angle_to_turn);
void turn_right_by_angle(unsigned short angle_to_turn);
void turn_around();
void move_forward_by_distance(unsigned short distance_in_inches);
void move_backward_by_distance(unsigned short distance_in_inches); 
void stop();



void turn_left_by_degree(unsigned short degree);
void turn_right_by_degree(unsigned short degree);



int convert_degrees_to_quad_ticks(unsigned short degrees);
int convert_inches_to_quad_ticks(unsigned short inches);






//mid level

//movement
//starting


//low level

void set_motor_directions_for_movement(unsigned char type_of_movement);
void set_left_motor_direction(unsigned char direction);
void set_right_motor_direction(unsigned char direction);



void enable_motors();
void enable_left_motor();
void enable_right_motor();
void stop_motors();
void stop_left_motor();
void stop_right_motor();



void move_distance(unsigned int distance_in_quad_ticks);
unsigned char motors_move_at_same_rate(unsigned int *left_ticks, unsigned int *right_ticks);
void get_duty_cycle(unsigned int distance, unsigned int quad_ticks, unsigned char *duty_cycle);






