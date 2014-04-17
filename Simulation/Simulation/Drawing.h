//
//  Drawing.h
//  Simulation
//
//  Created by Zach Lite on 2/11/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __Simulation__Drawing__
#define __Simulation__Drawing__

#include <iostream>
#include "SDL/SDL_opengl.h"
#include "SDL/SDL.h"

#import "GameBoard.h"
#import "Obstacle.h"
#import "GridSpace.h"
#import "SonarField.h"
#import "Beacon.h"
#import "Robot.h"

#define CircleEdges 100

const float PI = 3.1415927;

using namespace std;
#endif /* defined(__Simulation__Drawing__) */



void Draw_Rectangle (unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha, float X1, float X2, float Y1, float Y2);


void Draw_Boundary(CGRect rect);
//void Draw_Boundary(CGPoint p1, CGPoint p2, CGPoint p3, CGPoint p4);
//void Draw_Boundary(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y, int p4_x, int p4_y);

void Draw_Line(CGPoint start, CGPoint end, bool INCR_of_twelve);
//void Draw_Line(struct Coordinate *start, struct Coordinate *end, bool INCR_of_twelve);
//void Draw_Line(int start_x, int start_y, int end_x, int end_y, bool INCR_of_twelve);

//void Draw_Obstacle(struct Coordinate *origin, struct Size *size);

void Draw_Obstacle(Obstacle *obstacle);

void Draw_Grid_Unit(GridSpace *gridUnit);

void Draw_Beacon(Beacon *beacon);

void Draw_Robot(Robot *robot);
//void Draw_Sonar_Field(SonarField *sonarField);
