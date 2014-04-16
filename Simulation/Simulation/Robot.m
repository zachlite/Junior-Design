//
//  Robot.m
//  Simulation
//
//  Created by Zach Lite on 4/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "Robot.h"

@interface Robot()
//Private API




@end

@implementation Robot
@synthesize sensors;



- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
       
        if (!self.sensors)
        {
            self.sensors = [[Obstacle alloc] init];
            [self.sensors setFrame:CGRectMake(self.frame.origin.x-8.0, self.frame.origin.y-8.0, 8*8, 8*8)];
        
            
            
            
            [self updateFrameOrigin:frame.origin];
            [self updateSensorFrameOrigin:sensors.frame.origin];
        
            //[self addSubview:self.sensors];
       
            
        }
      
        
    }
    return self;
}


-(void)updateFrameOrigin:(CGPoint)point
{
    self.P1 = point;
    self.P2 = CGPointMake(self.P1.x + self.frame.size.width, self.P1.y);
    self.P3 = CGPointMake(self.P1.x + self.frame.size.width, self.P1.y + self.frame.size.height);
    self.P4 = CGPointMake(self.P1.x, self.P1.y + self.frame.size.height);
    
    
}


-(void)updateSensorFrameOrigin:(CGPoint)point
{
    self.sensors.P1 = point;
    self.sensors.P2 = CGPointMake(self.sensors.P1.x + self.sensors.frame.size.width, self.sensors.P1.y);
    self.sensors.P3 = CGPointMake(self.sensors.P1.x + self.sensors.frame.size.width, self.sensors.P1.y + self.sensors.frame.size.height);
    self.sensors.P4 = CGPointMake(self.sensors.P1.x, self.sensors.P1.y + self.sensors.frame.size.height);
    
    
}


//-(void)setNeedsLayout:(BOOL)flag
//{
//    if (flag)
//    {
//        [self.sensors setFrameSize:CGSizeMake(8*8, 2*8)];
//        [self.sensors setFrameOrigin:CGPointMake(self.frame.origin.x-8.0, self.frame.origin.y-8.0)];
//        
//    }
//  
//}


- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    
}


@end
