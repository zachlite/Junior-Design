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
#import <Foundation/Foundation.h>


#include "SDL/SDL_opengl.h"
#include "SDL/SDL.h"


//Include Dependencies Here
#import "Obstacle.h"
#import "GridSpace.h"
#import "Beacon.h"

#include "GameBoard.h"
#include "Drawing.h"
#include "math.h"

#include "includes.h"




#import <iostream>
using namespace std;


#endif /* defined(__Simulation__GameBoard__) */





//Need public init function

void InitGameBoard();

//Need public drawing function
void DrawBoardComponents();



void CheckIfClickedAtCoordinate(CGPoint mouseCoord);
void PositionBeaconsClickedAtCoordinate(CGPoint mouseCoord);
void ResetBeaconManipulation();



//void SetSonarField(float angle);
//void RegisterSonarField(SonarField *sonarField);
//void DrawSonarField();





//BOOL SonarFieldIntersectsObstacle();







