//
//  GameBoard.h
//  Simulation
//
//  Created by Zach Lite on 2/11/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#ifndef __Simulation__GameBoard__
#define __Simulation__GameBoard__

#import <Cocoa/Cocoa.h>

#include "SDL/SDL_opengl.h"
#include "SDL/SDL.h"

#define Width 768
#define Height 768
#define GridSpacing 1 //inch

#import "Obstacle.h"
#import "GridSpace.h"
#import "SonarField.h"
//using namespace std;

#endif /* defined(__Simulation__GameBoard__) */





void DrawGrid();
void DrawArenaBoundary();

void InitializeNavigationGrid();
void RegisterGridSpace(GridSpace *gridSpace);
void DrawGridUnits();


void SetSonarField(float angle);
void RegisterSonarField(SonarField *sonarField);
void DrawSonarField();


void CreateObstacles();
void CreateObstacle(CGPoint origin, CGSize size, CGFloat angle);
void RegisterObstacle(Obstacle *obstacle);
void DrawObstacles();


BOOL SonarFieldIntersectsObstacle();

float distanceBetween(CGPoint p1, CGPoint p2);
float AreaOfTriangle(CGPoint p1, CGPoint p2, CGPoint p3);
float slope(float y2, float y1, float x2, float x1);
float b_intercept_of_line(float slope, CGPoint point);



float Pixels_To_Inches(float pixels);
float Inches_To_Pixels(int inches);

struct Coordinate {
    int x;
    int y;
};
//typedef struct Coordinate Coordinate;


struct Coordinate InitCoordinate(int x, int y);