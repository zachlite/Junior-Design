//
//  Obstacle.m
//  Simulation
//
//  Created by Zach Lite on 2/12/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "Obstacle.h"

//obstacle objects are not what gets drawn to the screen.  they simply exist to store information.  let objective c do the heavy lifting!
//object information is what is rendered... not the actual object!

@implementation Obstacle
@synthesize P1;
@synthesize P2;
@synthesize P3;
@synthesize P4;
@synthesize Center;
@synthesize Angle;
@synthesize detected;
@synthesize DistanceFromRobot;


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

-(void)initObstacleWithAngle:(CGFloat)angle
{
    //the heigh and width do not change
    
    //calculate 4 points with angle.
    self.Angle = angle;
    
    P1 = self.frame.origin;
    
    P2.x = self.frame.origin.x + self.frame.size.width;
    P2.y = P1.y;
    
    P3.x = P2.x;
    P3.y = P1.y + self.frame.size.height;
    
    P4.x = P1.x;
    P4.y = P3.y;
    
    CGPoint center = CGPointMake(NSMidX([self frame]), NSMidY([self frame]));
    CGFloat radius =  sqrtf( powf((self.frame.size.width/2.0), 2) + powf((self.frame.size.height/2.0), 2));
    self.Center = center;
    
    
    if (self.Angle == 0)
    {
        
      
        
    }
    
    else
    {
   
        
        
        for (int i = 0; i < 4; i++)
        {
            CGPoint point;
            switch (i) {
                case 0:
                    point = P1;
                    break;
                case 1:
                    point = P2;
                    break;
                case 2:
                    point = P3;
                    break;
                case 3:
                    point = P4;
                    break;
                default:
                    break;
            }
            
       
            
            //need to find the current angle of each point.
            CGFloat angle = acosf((point.x - center.x) / radius);
          
            //then add the new angle
            if (CGPointEqualToPoint(point, P3) || CGPointEqualToPoint(point, P4))
            {
                angle = (M_PI*2 - angle);
            }
            
            
                angle -= self.Angle;
            
    

            
            //then find the point's new position
            CGPoint newCoordinate = CGPointMake(center.x + radius * cosf(angle), center.y + radius * sinf(angle));
            
            switch (i) {
                case 0:
                    P1 = newCoordinate;
                    break;
                case 1:
                    P2 = newCoordinate;
                    break;
                case 2:
                    P3 = newCoordinate;
                    break;
                case 3:
                    P4 = newCoordinate;
                    break;
                default:
                    break;
            }
            
            
        }
        
      
    }
      
        
        
        
        
        
        
        
    
       
        
    
    
    
}




@end
