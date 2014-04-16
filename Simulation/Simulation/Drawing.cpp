//
//  Drawing.cpp
//  Simulation
//
//  Created by Zach Lite on 2/11/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Drawing.h"



void Draw_Rectangle (unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha, float X1, float X2, float Y1, float Y2)
{
    
    glBegin(GL_QUADS);
    glColor4ub(R,G,B,Alpha);
    glVertex2f(X1, Y1);
    glVertex2f(X2, Y1);
    glVertex2f(X2, Y2);
    glVertex2f(X1, Y2);
    glEnd();
    
}

/*
void Draw_Line(int start_x, int start_y, int end_x, int end_y, bool INCR_of_twelve)
{
    
    glBegin(GL_LINES);
    if (INCR_of_twelve)
    {
        glColor4ub(0,0,0,255);
    }
    else
    {
        glColor4ub(200,200,200,255);
    }
    glVertex2f(start_x, start_y);
    glVertex2f(end_x, end_y);
    glEnd();
    glLineWidth(.5f);
}
 */

void Draw_Line(CGPoint start, CGPoint end, bool INCR_of_twelve)
{
    glBegin(GL_LINES);
    if (INCR_of_twelve)
    {
        glColor4ub(0,0,0,255);
    }
    else
    {
        glColor4ub(200,200,200,255);
    }
    glVertex2f(start.x, start.y);
    glVertex2f(end.x, end.y);
    glEnd();
    glLineWidth(.5f);
}

void Draw_Boundary(CGPoint p1, CGPoint p2, CGPoint p3, CGPoint p4)
{
    glBegin(GL_LINE_LOOP);
    glLineWidth(10.0f);

    glColor4ub(70,135,237,255);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(p3.x, p3.y);
    glVertex2f(p4.x, p4.y);
    glEnd();
    
}


void Draw_Obstacle(Obstacle *obstacle)
{
//    int origin_x = obstacle.frame.origin.x;//eventually obstacle.P1.x etc.
//    int origin_y = obstacle.frame.origin.y;
//    int width = obstacle.frame.size.width;
//    int height = obstacle.frame.size.height;
//
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    glBegin(GL_QUADS);
    glColor4ub(0,150,0,100);
    glVertex2f(obstacle.P1.x, obstacle.P1.y);
    glVertex2f(obstacle.P2.x, obstacle.P2.y);
    glVertex2f(obstacle.P3.x, obstacle.P3.y);
    glVertex2f(obstacle.P4.x, obstacle.P4.y);
    glEnd();
    glLineWidth(1.5f);
}


void Draw_Grid_Unit(GridSpace *gridUnit)
{
    
    NSColor *color = gridUnit.GridColor;
    GLbyte redByte, greenByte, blueByte, alphaByte;
    
    redByte = [color redComponent];
    greenByte = [color greenComponent];
    blueByte = [color blueComponent];
    alphaByte = [color alphaComponent];
    
    
    
    
    glBegin(GL_QUADS);
    glColor4ub(redByte,greenByte,blueByte,alphaByte);
    glVertex2f(gridUnit.P1.x, gridUnit.P1.y);
    glVertex2f(gridUnit.P2.x, gridUnit.P2.y);
    glVertex2f(gridUnit.P3.x, gridUnit.P3.y);
    glVertex2f(gridUnit.P4.x, gridUnit.P4.y);
    glEnd();
    glLineWidth(1.5f);
    
    
}

void Draw_Beacon(Beacon *beacon)
{
    
    CGPoint center = CGPointMake(NSMidX([beacon frame]), NSMidY([beacon frame]));
    //need to figure out a better system for coordinates regarding beacon frame
    
    //visible light is represented as a line loop
    
    NSColor *light_color = beacon.LightColor;
    //NSLog(@"%@ beacon light color", [beacon.LightColor description]);
    GLbyte redByte, greenByte, blueByte, alphaByte;
    
    redByte = [light_color redComponent] * 255.0;
    greenByte = [light_color greenComponent]* 255.0;
    blueByte = [light_color blueComponent]* 255.0;
    alphaByte = [light_color alphaComponent]* 255.0;
    

    
    glBegin(GL_LINE_LOOP);
    glColor4ub(redByte,greenByte,blueByte,alphaByte);

        for (float angle = 0; angle < CircleEdges; angle += 1)
        {

            CGPoint newCoordinate = CGPointMake(center.x + [beacon.LightFieldRadius floatValue] * cosf((angle*2*PI)/CircleEdges), center.y + [beacon.LightFieldRadius floatValue] * sinf((angle*2*PI)/CircleEdges));
            glVertex2f(newCoordinate.x, newCoordinate.y);

        }

        
    glEnd();

    
    
    
    
    //IR light is represented as a circle
    NSColor *IR_color = beacon.IRLightColor;

    redByte = [IR_color redComponent] * 255.0;
    greenByte = [IR_color greenComponent]* 255.0;
    blueByte = [IR_color blueComponent]* 255.0;
    alphaByte = [IR_color alphaComponent]* 100.0;
    
    
    
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(redByte,greenByte,blueByte,alphaByte);
    glVertex2f(center.x, center.y); // center of circle
    for (float angle = 0; angle <= CircleEdges; angle += 1)
    {
        
        CGPoint newCoordinate = CGPointMake(center.x + [beacon.IRFieldRadius floatValue] * cosf((angle*2*PI)/CircleEdges), center.y + [beacon.IRFieldRadius floatValue] * sinf((angle*2*PI)/CircleEdges));
        glVertex2f(newCoordinate.x, newCoordinate.y);
        
    }
    
    
    glEnd();
    
    
    
    
    
    
    
    ///beacon body
    glBegin(GL_QUADS);
    glColor4ub(0.0,0.0,0.0,255.0);
    glVertex2f(beacon.frame.origin.x, beacon.frame.origin.y);
    glVertex2f(beacon.frame.origin.x+beacon.frame.size.width, beacon.frame.origin.y);
    glVertex2f(beacon.frame.origin.x+beacon.frame.size.width, beacon.frame.origin.y+beacon.frame.size.height);
    glVertex2f(beacon.frame.origin.x, beacon.frame.origin.y+beacon.frame.size.height);
    glEnd();
    glLineWidth(1.5f);
    
}


void Draw_Robot(Robot *robot)
{
    
    
 

    //Sensors
    
    glBegin(GL_QUADS);
    glColor4ub(0.0,45.0,100.0,100.0);
    glVertex2f(robot.sensors.P1.x, robot.sensors.P1.y);
    glVertex2f(robot.sensors.P2.x, robot.sensors.P2.y);
    glVertex2f(robot.sensors.P3.x, robot.sensors.P3.y);
    glVertex2f(robot.sensors.P4.x, robot.sensors.P4.y);
    glEnd();
  
    
    
    //Robot
    
    glBegin(GL_QUADS);
    glColor4ub(180.0,45.0,0.0,255.0);
    glVertex2f(robot.P1.x, robot.P1.y);
    glVertex2f(robot.P2.x, robot.P2.y);
    glVertex2f(robot.P3.x, robot.P3.y);
    glVertex2f(robot.P4.x, robot.P4.y);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(5.0);
    glColor4ub(255.0,255.0,255.0,255.0);
    glVertex2f(robot.P1.x, robot.P1.y);
    glVertex2f(robot.P2.x, robot.P2.y);
    glEnd();
    
  
    
}

void Draw_Sonar_Field(SonarField *sonarField)
{
    
    glBegin(GL_TRIANGLES);
    glColor4ub(0,0,0,75);
    glVertex2f(sonarField.P1.x, sonarField.P1.y);
    glVertex2f(sonarField.P2.x, sonarField.P2.y);
    glVertex2f(sonarField.P3.x, sonarField.P3.y);
    glEnd();

    
}










