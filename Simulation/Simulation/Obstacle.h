//
//  Obstacle.h
//  Simulation
//
//  Created by Zach Lite on 2/12/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface Obstacle : NSView


@property (nonatomic) CGPoint P1;
@property (nonatomic) CGPoint P2;
@property (nonatomic) CGPoint P3;
@property (nonatomic) CGPoint P4;
@property (nonatomic) CGPoint Center;
@property (nonatomic) CGFloat Angle;

@property (nonatomic) BOOL detected;
@property (nonatomic) CGFloat DistanceFromRobot;

-(void)initObstacleWithAngle:(CGFloat)angle;


@end
