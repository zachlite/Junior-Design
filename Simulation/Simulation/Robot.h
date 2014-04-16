//
//  Robot.h
//  Simulation
//
//  Created by Zach Lite on 4/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "Obstacle.h"
#import "Sensors.h"



@interface Robot : Obstacle

@property (nonatomic, retain) Obstacle *sensors;

-(void)updateFrameOrigin:(CGPoint)point;
-(void)updateSensorFrameOrigin:(CGPoint)point;
@end
