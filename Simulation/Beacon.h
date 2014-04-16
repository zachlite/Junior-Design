//
//  Beacon.h
//  Simulation
//
//  Created by Zach Lite on 4/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "Obstacle.h"
#include "includes.h"

@interface Beacon : Obstacle

@property (nonatomic) BOOL isAvailableForCapture;
@property (nonatomic, retain) NSColor *LightColor;
@property (nonatomic, retain) NSColor *IRLightColor;
@property (nonatomic, retain) NSNumber *LightFieldRadius;
@property (nonatomic, retain) NSNumber *IRFieldRadius;

@property (nonatomic) BOOL hasBeenClicked;


-(void)Capture;
-(void)SimulateCaptureByOtherTeam;

@end
