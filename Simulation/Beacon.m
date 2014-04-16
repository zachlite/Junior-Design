//
//  Beacon.m
//  Simulation
//
//  Created by Zach Lite on 4/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "Beacon.h"

#define DefaultLightRadiusAvailable 2.0 //feet
#define DefaultLightRadiusCaptured 0.25 //feet
#define DefaultIRRadius .5 //foot


@interface Beacon()
//private API here
@end

@implementation Beacon
@synthesize isAvailableForCapture = _isAvailableForCapture;
@synthesize LightColor = _LightColor;
@synthesize IRLightColor = _IRLightColor;
@synthesize LightFieldRadius = _LightFieldRadius;
@synthesize IRFieldRadius = _IRFieldRadius;
@synthesize hasBeenClicked = _hasBeenClicked;

-(void)Capture
{
    if (self.isAvailableForCapture)
    {
        self.LightColor = [NSColor redColor];
        self.LightFieldRadius = [NSNumber numberWithFloat:DefaultLightRadiusCaptured];
        self.isAvailableForCapture = NO;
    }
}

-(void)SimulateCaptureByOtherTeam
{
    self.LightColor = [NSColor greenColor];
    self.LightFieldRadius = [NSNumber numberWithFloat:DefaultLightRadiusAvailable];
    self.isAvailableForCapture = YES;
}



- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        
        self.LightFieldRadius = [NSNumber numberWithFloat:DefaultLightRadiusAvailable * PixelsPerInch * 12.0];
        self.IRFieldRadius = [NSNumber numberWithFloat:DefaultIRRadius * PixelsPerInch * 12.0];
        self.LightColor = [NSColor greenColor];
        self.IRLightColor = [NSColor purpleColor];
        
    }
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    
    // Drawing code here.
   
}

@end
