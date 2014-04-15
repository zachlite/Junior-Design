//
//  GridSpace.h
//  Simulation
//
//  Created by Zach Lite on 2/14/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>



@interface GridSpace : NSView


@property (nonatomic) CGPoint P1;
@property (nonatomic) CGPoint P2;
@property (nonatomic) CGPoint P3;
@property (nonatomic) CGPoint P4;
@property (nonatomic, retain) NSColor *GridColor;

-(void)initSizeAndColor:(NSColor*)Color;




@end
