
#include <stdio.h>


#define Backward 0
#define Forward 1
#define Left 2
#define Right 3


//high level - Public API
void turn_left();
void turn_right();
void turn_left_by_angle(unsigned short angle_to_turn);
void turn_right_by_angle(unsigned short angle_to_turn);
void turn_around();
void move_forward_by_distance(unsigned short distance_in_inches);
void move_backward_by_distance(unsigned short distance_in_inches); 
void stop();


