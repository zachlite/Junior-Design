//
//  Sensors.m
//  Simulation
//
//  Created by Zach Lite on 4/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "Sensors.h"

@implementation Sensors
@synthesize sensor1;
@synthesize sensor2;
@synthesize sensor3;
- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
    }
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

@end
