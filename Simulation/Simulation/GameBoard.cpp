//
//  GameBoard.cpp
//  Simulation
//
//  Created by Zach Lite on 2/11/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//
//#import "SDL/SDL_opengl.h"
//#import "SDL/SDL.h"
#include "GameBoard.h"
#include "Drawing.h"
#include "math.h"

#import <iostream>
using namespace std;

#define PixelInchConversion 8 //8 pixels per inch
#define ArenaWidthAndHeight 6 //feet

static const int twelveInchPixelValue = Inches_To_Pixels(12);




NSMutableArray *ArrayThatHoldsObstacles = [NSMutableArray arrayWithCapacity:1];
NSMutableArray *ArrayThatHoldsGridSpaces = [NSMutableArray arrayWithCapacity:5184];
//NSMutableArray *ArrayThatHoldsSonarField = [NSMutableArray arrayWithCapacity:1];



void DrawGrid()
{
    //need to establish how many pixels correspond to an inch.
    
    int increment = Inches_To_Pixels(GridSpacing);
    Coordinate start, end;
    bool incr_of_twelve;
    
    
    for (int x = 0; x < Width; x += increment)
    {
        //draw verticle grid lines
            
        start.x = x;
        start.y = 0;
            
        end.x = x;
        end.y = Height;

        if (x % twelveInchPixelValue == 0)
        {
            incr_of_twelve = true;
        }
        else
        {
            incr_of_twelve = false;
        }
        
        //Draw_Line(start.x, start.y, end.x, end.y, incr_of_twelve);
        Draw_Line(&start, &end, incr_of_twelve);
    }
    
    for (int y = 0; y < Height; y+= increment)
    {
        //draw horizontal grid lines
        start.x = 0;
        start.y = y;
        
        end.x = Width;
        end.y = y;
        
        if (y % twelveInchPixelValue == 0)
        {
            incr_of_twelve = true;
        }
        else
        {
            incr_of_twelve = false;
        }
        
        //Draw_Line(start.x, start.y, end.x, end.y, incr_of_twelve);
        Draw_Line(&start, &end, incr_of_twelve);

    }
    
}


void DrawArenaBoundary()
{
    Coordinate p1, p2, p3, p4;
    
    p1 = InitCoordinate(Inches_To_Pixels(12), Inches_To_Pixels(12));
    p2 = InitCoordinate(Inches_To_Pixels(12*7), Inches_To_Pixels(12));
    p3 = InitCoordinate(Inches_To_Pixels(12*7), Inches_To_Pixels(12*7));
    p4 = InitCoordinate(Inches_To_Pixels(12), Inches_To_Pixels(12*7));
    

    //Draw_Boundary(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
    Draw_Boundary(&p1, &p2, &p3, &p4);
    

}




void InitializeNavigationGrid()
{
    
    //need a grid of 72/n by 72/n spaces, where n is the grid spacing in inches
    
    for (float x = Inches_To_Pixels(12); x < Inches_To_Pixels(72+12)/GridSpacing; x += Inches_To_Pixels(GridSpacing))
    {
        for (float y = Inches_To_Pixels(12); y < Inches_To_Pixels(72+12)/GridSpacing; y+= Inches_To_Pixels(GridSpacing))
        {
        
       
            GridSpace *gridUnit = [[GridSpace alloc] init];
            [gridUnit initSizeAndColor:[NSColor colorWithRed:139 green:73 blue:221 alpha:100]];
            //[gridUnit initSizeAndColor:[NSColor redColor]];
            
            gridUnit.P1 = CGPointMake(x, y);
            gridUnit.P2 = CGPointMake(x + gridUnit.frame.size.width, y);
            gridUnit.P3 = CGPointMake(x + gridUnit.frame.size.width, y + gridUnit.frame.size.height);
            gridUnit.P4 = CGPointMake(x, y + gridUnit.frame.size.height);
            
            RegisterGridSpace(gridUnit);
            
            
            
        }
    }
    
    
    

}


void RegisterGridSpace(GridSpace *gridSpace)
{
    [ArrayThatHoldsGridSpaces addObject:gridSpace];
    
}



//void SetSonarField(float angle)
//{
//    SonarField *sonarField = [[SonarField alloc] init];
//    [sonarField SetSonarFieldAt:CGPointMake(Inches_To_Pixels(4), Inches_To_Pixels(6.5)) WithAngle:angle];
//    
//    RegisterSonarField(sonarField);
//    
//        //NSLog(@"P1: %f %f", (sonarField.P1.x),(sonarField.P1.y));
//        //NSLog(@"P2 : %f %f", (sonarField.P2.x), (sonarField.P2.y));
//        //NSLog(@"P3 : %f %f", (sonarField.P3.x), (sonarField.P3.y));
//    
//    
//}

//
//void RegisterSonarField(SonarField *sonarField)
//{
//    [ArrayThatHoldsSonarField removeAllObjects];
//    [ArrayThatHoldsSonarField addObject:sonarField];
//    
//}
//





void CreateObstacles()
{
    
    
    struct ObstacleParameters {
        CGPoint Origin;
        CGSize Size;
        CGFloat Angle;
    };
    
    
    ObstacleParameters obstacle1;
    obstacle1.Origin = CGPointMake(Inches_To_Pixels(12*1.5), Inches_To_Pixels(12*2));
    obstacle1.Size = CGSizeMake(Inches_To_Pixels(12*1),Inches_To_Pixels(12*2));
    obstacle1.Angle = M_PI/180.0 * 20;
    
    ObstacleParameters obstacle2;
    obstacle2.Origin = CGPointMake(Inches_To_Pixels(12*6), Inches_To_Pixels(12*1.25));
    obstacle2.Size = CGSizeMake(Inches_To_Pixels(7),Inches_To_Pixels(12));
    obstacle2.Angle = M_PI/180.0 * 135.0;
    
    ObstacleParameters obstacle3;
    obstacle3.Origin = CGPointMake(Inches_To_Pixels(12*5.0), Inches_To_Pixels(12*3.5));
    obstacle3.Size = CGSizeMake(Inches_To_Pixels(12*1),Inches_To_Pixels(12*3));
    obstacle3.Angle = M_PI/180.0 * 10.0;
    
    
    ObstacleParameters ArrayThatHoldsObstacleParameters[3] = {obstacle1, obstacle2, obstacle3};
    
    
    
    
    
//    char randomNumberOfObstacles = (arc4random() % 2);
//    if (randomNumberOfObstacles == 0)
//    {
//        randomNumberOfObstacles = 2;
//    }
//    else
    //{
      char randomNumberOfObstacles = 3;
    //}
    
    NSLog(@"number of obstacles %d", randomNumberOfObstacles);
    
    for (int i = 0; i <randomNumberOfObstacles; i++)
    {
        CreateObstacle(ArrayThatHoldsObstacleParameters[i].Origin, ArrayThatHoldsObstacleParameters[i].Size, ArrayThatHoldsObstacleParameters[i].Angle);
    }
    
    
    
    
    
    
}



void CreateObstacle(CGPoint origin, CGSize size, CGFloat angle)
{
    
    //accepts typical obstacle information: origin, size, angle
 
    Obstacle *obstacle = [[Obstacle alloc] init];
    [obstacle setFrame:CGRectMake(origin.x, origin.y, size.width, size.height)];//this information is only to calculate the center.
    
    //actual frame info will come from custom obstacle properties. P1, P2.. etc.
    
    
    //calculate the four points based on the origin, size, and angle
    
    [obstacle initObstacleWithAngle:angle];
    
    
    
//    NSLog(@"P1: %f %f", Pixels_To_Inches(obstacle.P1.x),Pixels_To_Inches(obstacle.P1.y));
//    NSLog(@"P2 : %f %f", Pixels_To_Inches(obstacle.P2.x), Pixels_To_Inches(obstacle.P2.y));
//    NSLog(@"P3 : %f %f", Pixels_To_Inches(obstacle.P3.x), Pixels_To_Inches(obstacle.P3.y));
//    NSLog(@"P4 : %f %f", Pixels_To_Inches(obstacle.P4.x), Pixels_To_Inches(obstacle.P4.y));
    
    RegisterObstacle(obstacle);
    
    
    
}

void RegisterObstacle(Obstacle *obstacle)
{
    [ArrayThatHoldsObstacles addObject:obstacle];
    NSLog(@"New Obstacle Registered");
}


void DrawObstacles()
{
    for (Obstacle *obstacle in ArrayThatHoldsObstacles)
    {
        Draw_Obstacle(obstacle);
    }
    
}




void DrawGridUnits()
{
    for (GridSpace *gridUnit in ArrayThatHoldsGridSpaces)
    {
       
        
        Draw_Grid_Unit(gridUnit);
    }
    
}



//void DrawSonarField()
//{
//    Draw_Sonar_Field([ArrayThatHoldsSonarField firstObject]);
//    
//}





/*
BOOL SonarFieldIntersectsObstacle ()
{
    
    
    SonarField *sonarField = [ArrayThatHoldsSonarField firstObject];

    for (Obstacle *obstacle in ArrayThatHoldsObstacles)
    {
        CGPoint arrayOfFieldPoints[3] = {sonarField.P1, sonarField.P2, sonarField.P3};
        CGPoint arrayOfObstaclePoints[5] = {obstacle.P1, obstacle.P2, obstacle.P3, obstacle.P4, obstacle.Center};
        
        
        float A = AreaOfTriangle(sonarField.P1, sonarField.P2, sonarField.P3);
        //NSLog(@"area of sonar field %f", A);
        
        
        //for each of the obstacles 4 points, check if at least one of the points is bounded by the triangle
        for (int m = 0; m < 5; m++)
        {
            float A_1 = 0;
            
            for (int i = 0; i < 2; i++) //for each of the three triangles lines
            {
                for (int j = 0; j < 3; j++)
                {
                    if (j == i || i > j)
                    {
                        continue;
                    }
                    else
                    {
                        A_1 += AreaOfTriangle(arrayOfObstaclePoints[m], arrayOfFieldPoints[i], arrayOfFieldPoints[j]);
                        
                    }
                }
            }
            
            
            if (fabsf(A - A_1) <= .1)
            {
                obstacle.detected = YES;
                break;
            }
            else
            {
                obstacle.detected = NO;
            }
            
        }
    }
    
    

  
    float smallest_distance = 1e9;
        
    for (Obstacle *obstacle in ArrayThatHoldsObstacles)
    {
        if (obstacle.detected)
        {
            obstacle.DistanceFromRobot = distanceBetween(obstacle.Center, sonarField.P1);
            
            if (obstacle.DistanceFromRobot < smallest_distance)
            {
                smallest_distance = obstacle.DistanceFromRobot;
            }
    
        }
            //figure out its distance to the sonarfield mount point on robot
            
            
            
    }
        
    for (Obstacle *obstacle in ArrayThatHoldsObstacles)
    {
        if (obstacle.detected)
        {
            if (obstacle.DistanceFromRobot == smallest_distance)
            {
                NSLog(@"obstacle %lu detected", (unsigned long)[ArrayThatHoldsObstacles indexOfObject:obstacle]);
                return YES;
            }
        }
        
    }
        
        
    
    return NO;
    
    
}
 
 
*/



float distanceBetween(CGPoint p1, CGPoint p2)
{
    float d;
    d = sqrtf((powf(p2.x-p1.x, 2.0))+(powf(p2.y-p1.y, 2.0)));
    return d;
}

float AreaOfTriangle(CGPoint p1, CGPoint p2, CGPoint p3)
{
    return fabsf((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
}

float slope(float y2, float y1, float x2, float x1)
{
    return (y2-y1)/(x2-x1);
}

float b_intercept_of_line(float slope, CGPoint point)
{
    //y = slope*x + b_intercept
    return point.y - (slope*point.x);
    
}







////////Establish pixel to inches conversion
float Pixels_To_Inches(float pixels)
{
    return pixels/PixelInchConversion ;
}


///////Establish inches to pixel conversion
float Inches_To_Pixels(int inches)
{
    return inches*PixelInchConversion;
}


Coordinate InitCoordinate(int x, int y)
{
    Coordinate point;
    point.x = x;
    point.y = y;
    
    return point;
    
}


