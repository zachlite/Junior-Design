//
//  GridSpace.m
//  Simulation
//
//  Created by Zach Lite on 2/14/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import "GridSpace.h"

@implementation GridSpace
@synthesize P1;
@synthesize P2;
@synthesize P3;
@synthesize P4;
@synthesize GridColor;





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



-(void)initSizeAndColor:(NSColor*)Color;
{
    
    [self setFrameSize:CGSizeMake(8, 8)];    
    
    self.GridColor = Color;
    
}


@end
