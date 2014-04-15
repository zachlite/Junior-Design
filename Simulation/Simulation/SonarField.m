//
//  SonarField.m
//  Simulation
//
//  Created by Zach Lite on 2/16/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "SonarField.h"
#define FieldAngle 15.0 //degrees
#define FieldRadius 6.0 //feet

@implementation SonarField
@synthesize P1;
@synthesize P2;
@synthesize P3;
@synthesize angle;

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

-(void)SetSonarFieldAt:(CGPoint)MountPointOnRobot WithAngle:(CGFloat)Angle
{
    //MountPointOnRobot represents the first point of the field.. the anchor
    //Angle represents angle (direction) robot is facing
    
    self.angle = Angle;
    
    
    MountPointOnRobot = CGPointMake(768/2.0, 624);
    
    P1 = MountPointOnRobot; //always the center
    P2.x = P1.x - (FieldRadius*12*8)*tanf((M_PI/180.0) * FieldAngle);
    P2.y = P1.y - (FieldRadius*12*8);
    
    P3.x = P1.x + (FieldRadius*12*8)*tanf((M_PI/180.0) * FieldAngle);
    P3.y = P2.y;
    
    
    //NSLog(@"coordinate of point 2: %f %f", P2.x, P2.y);
    //NSLog(@"coordinate of point 3: %f %f", P3.x, P3.y);

    
    //if (Angle == 0.0)
    //{
        //no rotation
   // }
    //else
    //{
        //NSLog(@"need to adjust");
        CGPoint center = P1;
        //NSLog(@"center is %f %f", P1.x, P1.y);
        CGFloat radius = FieldRadius*12*8; //feet
    
    //NSLog(@"field radius is %f", radius);
        for (int i = 0; i < 2; i++)//only changing two points
        {
            CGPoint point;
            switch (i) {
                case 0:
                    point = P2;
                    //NSLog(@"first");
                    break;
                case 1:
                    point = P3;
                    //NSLog(@"second");
                    break;
                    
                default:
                    break;
            }
            
            
            //find the current angle of each point
            CGFloat angleOfPoint = acosf((point.x - center.x) / radius);
            //NSLog(@"angle of point % d is %f",i+2, angleOfPoint * (180.0/M_PI));
            
            //then add the new angle
            
            angleOfPoint -= self.angle;//(M_PI/180.0)*self.angle;
            
            //NSLog(@"new angle of point % d is %f",i+2, angleOfPoint * (180.0/M_PI));

            
            //then find the point's new position
            CGPoint newCoordinate = CGPointMake(center.x + radius * cosf(angleOfPoint), center.y - radius * sinf(angleOfPoint));
            
            //NSLog(@"new coordinate: %f %f", newCoordinate.x, newCoordinate.y);

            
            
            switch (i) {
                case 0:
                    P2 = newCoordinate;
                    //NSLog(@"new coordinate: %f %f", P2.x, P2.y);

                    break;
                case 1:
                    P3 = newCoordinate;
                    //NSLog(@"new coordinate: %f %f", P3.x, P3.y);

                    break;
                default:
                    break;
            }
            
            
            
            //NSLog(@"\n\n");
            
            
        }
   // }
    
    
    
    
    
    
    
   

    
    
    
    
    
    
    
    
    
}



@end
