//
//  SonarField.h
//  Simulation
//
//  Created by Zach Lite on 2/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface SonarField : NSView

@property (nonatomic) CGPoint P1;
@property (nonatomic) CGPoint P2;
@property (nonatomic) CGPoint P3; //the sonar field is modeled by a triangle
@property (nonatomic) CGFloat angle;


-(void)SetSonarFieldAt:(CGPoint)MountPointOnRobot WithAngle:(CGFloat)Angle;

@end
