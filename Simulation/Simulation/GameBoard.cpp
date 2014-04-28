//
//  GameBoard.cpp
//  Simulation
//
//  Created by Zach Lite on 2/11/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//



#include "GameBoard.h"

#define RADIANSPERDEGREE 0.0174532925


//Private Init Functions
void InitGameBoardBoundary();
void InitializeNavigationGrid();
void RegisterGridSpace(GridSpace *gridSpace);

void CreateObstacles();
void CreateObstacle(CGPoint origin, CGSize size, CGFloat angle);
void RegisterObstacle(Obstacle *obstacle);

void InitBeacons();

void InitRobot();


//Private Drawing Functions
void DrawGrid();
void DrawObstacles();
void DrawArena();
void DrawGridUnits();
void DrawBeacons();
void DrawRobot();

//Private Math Functions
float AreaOfSquare(id square, CGPoint point);
bool SquareIntersectsSquare(id square1, id square2);//that is a subclass
bool CircleContainsPoint(CGPoint p, CGPoint c, float radius);
float distanceBetween(CGPoint p1, CGPoint p2);
float AreaOfTriangle(CGPoint p1, CGPoint p2, CGPoint p3);
float slope(float y2, float y1, float x2, float x1);
float b_intercept_of_line(float slope, CGPoint point);

float Pixels_To_Inches(float pixels);
float Inches_To_Pixels(int inches);


static const int twelveInchPixelValue = Inches_To_Pixels(12);


NSMutableArray *ArrayThatHoldsObstacles = [NSMutableArray arrayWithCapacity:1];
NSMutableArray *ArrayThatHoldsGridSpaces = [NSMutableArray arrayWithCapacity:5184];
//NSMutableArray *ArrayThatHoldsSonarField = [NSMutableArray arrayWithCapacity:1];
NSMutableArray *ArrayThatHoldsBeacons = [NSMutableArray arrayWithCapacity:3];
NSArray *BoardBoundaries;

NSArray *RobotHolder;
NSArray *ArenaHolder;


/*
 
           _
  ___  ___| |_ _   _ _ __
 / __|/ _ \ __| | | | '_ \
 \__ \  __/ |_| |_| | |_) |
 |___/\___|\__|\__,_| .__/
                    |_|

 
 */



void InitGameBoard()
{
    
    /*
     game board is responsible for making
     grid
     obstacles
     beacons
     
     
     */
    
  
    InitGameBoardBoundary();
    
    CreateObstacles();
    
    //InitializeNavigationGrid();

    InitBeacons();
    
    InitRobot();
    
    
}

void InitGameBoardBoundary()
{
    Obstacle *Arena_Piece_1 = [[Obstacle alloc] initWithFrame:CGRectMake(Inches_To_Pixels(0), Inches_To_Pixels(0), Inches_To_Pixels(8*12), Inches_To_Pixels(1*12))];
    Obstacle *Arena_Piece_2 = [[Obstacle alloc] initWithFrame:CGRectMake(Inches_To_Pixels(7*12), Inches_To_Pixels(1*12), Inches_To_Pixels(1*12), Inches_To_Pixels(6*12))];
    Obstacle *Arena_Piece_3 = [[Obstacle alloc] initWithFrame:CGRectMake(Inches_To_Pixels(0), Inches_To_Pixels(7*12), Inches_To_Pixels(8*12), Inches_To_Pixels(1*12))];
    Obstacle *Arena_Piece_4 = [[Obstacle alloc] initWithFrame:CGRectMake(Inches_To_Pixels(0), Inches_To_Pixels(1*12), Inches_To_Pixels(1*12), Inches_To_Pixels(6*12))];

        NSLog(@"arena1 shape coordinates:");
        NSLog(@"P1: %f %f",  Arena_Piece_1.P1.x, Arena_Piece_1.P1.y);
        NSLog(@"P2: %f %f", Arena_Piece_1.P2.x, Arena_Piece_1.P2.y);
        NSLog(@"P3: %f %f", Arena_Piece_1.P3.x, Arena_Piece_1.P3.y);
        NSLog(@"P4: %f %f", Arena_Piece_1.P4.x, Arena_Piece_1.P4.y);
        NSLog(@"****************************");

    NSLog(@"arena2 shape coordinates:");
    NSLog(@"P1: %f %f", Arena_Piece_2.P1.x, Arena_Piece_2.P1.y);
    NSLog(@"P2: %f %f", Arena_Piece_2.P2.x, Arena_Piece_2.P2.y);
    NSLog(@"P3: %f %f", Arena_Piece_2.P3.x, Arena_Piece_2.P3.y);
    NSLog(@"P4: %f %f", Arena_Piece_2.P4.x, Arena_Piece_2.P4.y);
    NSLog(@"****************************");
    
    NSLog(@"arena3 shape coordinates:");
    NSLog(@"P1: %f %f", Arena_Piece_3.P1.x, Arena_Piece_3.P1.y);
    NSLog(@"P2: %f %f", Arena_Piece_3.P2.x, Arena_Piece_3.P2.y);
    NSLog(@"P3: %f %f", Arena_Piece_3.P3.x, Arena_Piece_3.P3.y);
    NSLog(@"P4: %f %f", Arena_Piece_3.P4.x, Arena_Piece_3.P4.y);
    NSLog(@"****************************");
    
    NSLog(@"arena4 shape coordinates:");
    NSLog(@"P1: %f %f", Arena_Piece_4.P1.x, Arena_Piece_4.P1.y);
    NSLog(@"P2: %f %f", Arena_Piece_4.P2.x, Arena_Piece_4.P2.y);
    NSLog(@"P3: %f %f", Arena_Piece_4.P3.x, Arena_Piece_4.P3.y);
    NSLog(@"P4: %f %f", Arena_Piece_4.P4.x, Arena_Piece_4.P4.y);
    NSLog(@"****************************");
    
    
    //[Arena giveShapeAngle:0.0];
    ArenaHolder  = [NSArray arrayWithObjects:Arena_Piece_1,Arena_Piece_2,Arena_Piece_3,Arena_Piece_4, nil];
    //Arena = CGRectMake(Inches_To_Pixels(12), Inches_To_Pixels(12), Inches_To_Pixels(6*12), Inches_To_Pixels(6*12));//if the robot intersects this we're good.
 
    
    
}





void CreateObstacles()
{
    
    
    struct ObstacleParameters {
        CGPoint Origin;
        CGSize Size;
        CGFloat Angle;
    };
    
    
    ObstacleParameters obstacle1;
    obstacle1.Origin = CGPointMake(Inches_To_Pixels(12*1.5), Inches_To_Pixels(12*2));
    obstacle1.Size = CGSizeMake(Inches_To_Pixels(12*1),Inches_To_Pixels(12*2));
    obstacle1.Angle = M_PI/180.0 * 20;
    
    ObstacleParameters obstacle2;
    obstacle2.Origin = CGPointMake(Inches_To_Pixels(12*6), Inches_To_Pixels(12*1.25));
    obstacle2.Size = CGSizeMake(Inches_To_Pixels(7),Inches_To_Pixels(12));
    obstacle2.Angle = M_PI/180.0 * 135.0;
    
    ObstacleParameters obstacle3;
    obstacle3.Origin = CGPointMake(Inches_To_Pixels(12*5.0), Inches_To_Pixels(12*3.5));
    obstacle3.Size = CGSizeMake(Inches_To_Pixels(12*1),Inches_To_Pixels(12*3));
    obstacle3.Angle = M_PI/180.0 * 10.0;
    
    
    ObstacleParameters ArrayThatHoldsObstacleParameters[3] = {obstacle1, obstacle2, obstacle3};
    
    
    
    
    
    //    char randomNumberOfObstacles = (arc4random() % 2);
    //    if (randomNumberOfObstacles == 0)
    //    {
    //        randomNumberOfObstacles = 2;
    //    }
    //    else
    //{
    char randomNumberOfObstacles = 3;
    //}
    
    NSLog(@"number of obstacles %d", randomNumberOfObstacles);
    
    for (int i = 0; i <randomNumberOfObstacles; i++)
    {
        CreateObstacle(ArrayThatHoldsObstacleParameters[i].Origin, ArrayThatHoldsObstacleParameters[i].Size, ArrayThatHoldsObstacleParameters[i].Angle);
    }
    
    
    
    
    
    
}


void CreateObstacle(CGPoint origin, CGSize size, CGFloat angle)
{
    
    //accepts typical obstacle information: origin, size, angle
    
    Obstacle *obstacle = [[Obstacle alloc] initWithFrame:CGRectMake(origin.x, origin.y, size.width, size.height)];
    //[obstacle setFrame:CGRectMake(origin.x, origin.y, size.width, size.height)];//this information is only to calculate the center.
    
    //[obstacle setCenter:CGPointMake(origin.x, origin.y)];
    //actual frame info will come from custom obstacle properties. P1, P2.. etc.
    
    
    //calculate the four points based on the origin, size, and angle
    
    [obstacle giveShapeAngle:angle];
    
    
    
    //    NSLog(@"P1: %f %f", Pixels_To_Inches(obstacle.P1.x),Pixels_To_Inches(obstacle.P1.y));
    //    NSLog(@"P2 : %f %f", Pixels_To_Inches(obstacle.P2.x), Pixels_To_Inches(obstacle.P2.y));
    //    NSLog(@"P3 : %f %f", Pixels_To_Inches(obstacle.P3.x), Pixels_To_Inches(obstacle.P3.y));
    //    NSLog(@"P4 : %f %f", Pixels_To_Inches(obstacle.P4.x), Pixels_To_Inches(obstacle.P4.y));
    
    RegisterObstacle(obstacle);
    
}

void RegisterObstacle(Obstacle *obstacle)
{
    [ArrayThatHoldsObstacles addObject:obstacle];
    NSLog(@"New Obstacle Registered");
}



void InitializeNavigationGrid()
{
    
    //need a grid of 72/n by 72/n spaces, where n is the grid spacing in inches
    
    for (float x = Inches_To_Pixels(12); x < Inches_To_Pixels(72+12)/GridSpacing; x += Inches_To_Pixels(GridSpacing))
    {
        for (float y = Inches_To_Pixels(12); y < Inches_To_Pixels(72+12)/GridSpacing; y+= Inches_To_Pixels(GridSpacing))
        {
        
       
            GridSpace *gridUnit = [[GridSpace alloc] init];
            [gridUnit initSizeAndColor:[NSColor colorWithRed:139 green:73 blue:221 alpha:100]];
            //[gridUnit initSizeAndColor:[NSColor redColor]];
            
            gridUnit.P1 = CGPointMake(x, y);
            gridUnit.P2 = CGPointMake(x + gridUnit.frame.size.width, y);
            gridUnit.P3 = CGPointMake(x + gridUnit.frame.size.width, y + gridUnit.frame.size.height);
            gridUnit.P4 = CGPointMake(x, y + gridUnit.frame.size.height);
            
            RegisterGridSpace(gridUnit);
            
            
            
        }
    }
    
    
    

}


void RegisterGridSpace(GridSpace *gridSpace)
{
    [ArrayThatHoldsGridSpaces addObject:gridSpace];
    
}

void InitBeacons()
{
    NSLog(@"Beacons Initialized");
    
    CGPoint coordArray[3] = {CGPointMake(100, 100),
                             CGPointMake(300, 100),
                             CGPointMake(500, 100)};
    
    for (int i = 0; i < 3; i++) //make 3 beacons
    {
       // Beacon *beacon = [[Beacon alloc] init];
        Beacon *beacon = [[Beacon alloc] initWithFrame:CGRectMake(0, 0, Inches_To_Pixels(2.75),Inches_To_Pixels(2.75))];
        
        [beacon setFrameOrigin:coordArray[i]];
        [beacon giveShapeAngle:0.0];
        
        [ArrayThatHoldsBeacons addObject:beacon];
       
    }
 
    
  
    
    
}

void InitRobot()
{
    NSLog(@"Robot Initialized");
    
    Robot *robot = [[Robot alloc] initWithFrame:CGRectMake(300, 300, Inches_To_Pixels(7.5), Inches_To_Pixels(7.5))];
    //[robot giveShapeAngle:5.0*RADIANSPERDEGREE + (90* RADIANSPERDEGREE)];
    
    RobotHolder = [NSArray arrayWithObject:robot];
    
        NSLog(@"P1: %f %f", (robot.P1.x),(robot.P1.y));
        NSLog(@"P2 : %f %f", (robot.P2.x), (robot.P2.y));
        NSLog(@"P3 : %f %f", (robot.P3.x), (robot.P3.y));
        NSLog(@"P4 : %f %f", (robot.P4.x), (robot.P4.y));
    
}



/*
 
 
  _                 _                           _        _   _
 (_)_ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_(_) ___  _ __
 | | '_ ` _ \| '_ \| |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | __| |/ _ \| '_ \
 | | | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | |
 |_|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|
             |_|
 
 
 
 
 */


//medium-low level motor simulation implementation

void move_forward_by_distance(unsigned short distance)//inches
{
    Robot *robot = [RobotHolder firstObject];
    
    NSLog(@"robot angle: %f", robot.Angle /RADIANSPERDEGREE);

    
    CGFloat xVector,yVector;
    
    xVector = cosf(robot.Angle+(90*RADIANSPERDEGREE));
    yVector = sinf(robot.Angle+(90*RADIANSPERDEGREE));
    
    //NSLog(@"xvector %f", xVector);
    //NSLog(@"yvector %f", yVector);

    
    //[robot updateFrameOrigin:CGPointMake(robot.P1.x - ((distance)*xVector), robot.P1.y-((distance)*yVector))];
    robot.P1 = CGPointMake(robot.P1.x - (distance*xVector), robot.P1.y - (distance*yVector));
    robot.P2 = CGPointMake(robot.P2.x - (distance*xVector), robot.P2.y - (distance*yVector));
    robot.P3 = CGPointMake(robot.P3.x - (distance*xVector), robot.P3.y - (distance*yVector));
    robot.P4 = CGPointMake(robot.P4.x - (distance*xVector), robot.P4.y - (distance*yVector));
    //[robot setFrame:CGRectMake(robot.P1.x, robot.P1.y, robot.frame.size.width, robot.frame.size.height)];

    
    //[robot updateSensorFrameOrigin:CGPointMake(robot.sensors.P1.x - (Inches_To_Pixels(distance)*xVector), robot.sensors.P1.y-(Inches_To_Pixels(distance)*yVector))];
    
    
}
void move_backward_by_distance(unsigned short distance)
{
    
    Robot *robot = [RobotHolder firstObject];
    
    NSLog(@"robot angle: %f", robot.Angle);
    
    CGFloat xVector,yVector;
    
    xVector = cosf(robot.Angle+(90*RADIANSPERDEGREE));
    yVector = sinf(robot.Angle+(90*RADIANSPERDEGREE));
    
    //NSLog(@"xvector %f", xVector);
    //NSLog(@"yvector %f", yVector);
    
    
    [robot updateFrameOrigin:CGPointMake(robot.P1.x + ((distance)*xVector), robot.P1.y+((distance)*yVector))];
    
    //[robot updateSensorFrameOrigin:CGPointMake(robot.sensors.P1.x + (Inches_To_Pixels(distance)*xVector), robot.sensors.P1.y+(Inches_To_Pixels(distance)*yVector))];
    
}
void turn_right_by_angle(unsigned short angle_to_turn)
{
    Robot *robot = [RobotHolder firstObject];
    
    float rad = angle_to_turn*0.0174532925;
    
    [robot giveShapeAngle:robot.Angle-rad];
    //[robot.sensors giveShapeAngle:robot.sensors.Angle-rad];
    NSLog(@"robot angle: %f", robot.Angle /.0174532925);

//    [robot setFrameCenterRotation:robot.Angle-rad];
//    [robot.sensors setFrameCenterRotation:robot.sensors.Angle-rad];
//    
}
void turn_left_by_angle(unsigned short angle_to_turn)
{
    Robot *robot = [RobotHolder firstObject];
    
    float rad = angle_to_turn*0.0174532925;
    
    [robot giveShapeAngle:robot.Angle+rad];
    
    NSLog(@"robot angle: %f", robot.Angle /.0174532925);
    //[robot.sensors giveShapeAngle:robot.sensors.Angle+rad];
    
//    [robot setFrameCenterRotation:robot.Angle+rad];
//    [robot.sensors setFrameCenterRotation:robot.sensors.Angle+rad];
}


//light sensor simulation implementation
bool light_detected()
{
    Robot *robot = [RobotHolder firstObject];

    for (Beacon *beacons in ArrayThatHoldsBeacons)
    {
        if (CircleContainsPoint(robot.Center, beacons.Center, [beacons.LightFieldRadius floatValue]))
        {
            
            return true;
        }
    
    }
    
    return false;
}


bool beacon_captured()
{
    return false;
}


//IR simulation implementation
void capture_beacon()
{
    //nothing now
    
}


//Obstacle ADC simulation implementation
bool obstacle_detected()
{

    
    Robot *robot = [RobotHolder firstObject];

  
    for (Obstacle *obstacle in ArrayThatHoldsObstacles)
    {
        if (SquareIntersectsSquare(obstacle, robot)) {
            NSLog(@"obstacle detected");

            return true;
        }
        
       
        
    }
    //or
  
    for (Obstacle *arena_piece in ArenaHolder)
    {
        NSLog(@"testing robot with arena_piece %lu", [ArenaHolder indexOfObject:arena_piece] + 1);
        if (SquareIntersectsSquare(arena_piece, robot))
        {
            NSLog(@"collision detected with arena piece %lu", [ArenaHolder indexOfObject:arena_piece] + 1);
            NSLog(@"obstacle detected");
            return true;
        }
    }
  
    
    return false;
    
}





/*
 
 
                        _             _       _   _
 _ __ ___   __ _ _ __  (_)_ __  _   _| | __ _| |_(_) ___  _ __
 | '_ ` _ \ / _` | '_ \| | '_ \| | | | |/ _` | __| |/ _ \| '_ \
 | | | | | | (_| | | | | | |_) | |_| | | (_| | |_| | (_) | | | |
 |_| |_| |_|\__,_|_| |_|_| .__/ \__,_|_|\__,_|\__|_|\___/|_| |_|
                         |_|
 

 
 */

void MoveRobot()
{
    Robot *robot = [RobotHolder firstObject];

    [robot updateFrameOrigin:CGPointMake(robot.P1.x,robot.P1.y+1.0)];
    [robot updateSensorFrameOrigin:CGPointMake(robot.sensors.P1.x, robot.sensors.P1.y+1.0)];
    

    
}

void RotateRobot()
{
    Robot *robot = [RobotHolder firstObject];
    
    [robot giveShapeAngle:robot.Angle+.1];
    [robot.sensors giveShapeAngle:robot.sensors.Angle+.1];

}


void PositionBeaconsClickedAtCoordinate(CGPoint mouseCoord)
{
    for (Beacon *b in ArrayThatHoldsBeacons)
    {
        if (b.hasBeenClicked)
        {
            [b setFrameOrigin:mouseCoord];
            [b setCenter:mouseCoord];
            //need to figure out a better system for coordinates regarding beacon frame

        }
    }
    
}

void CheckIfClickedAtCoordinate(CGPoint mouseCoord)
{
    //first check to see if a beacon has been touched
   
    for (Beacon *b in ArrayThatHoldsBeacons)
    {
        if (CGRectContainsPoint(b.frame, mouseCoord))
        {
            b.hasBeenClicked = YES;
            
        }
    }
    
}

void ResetBeaconManipulation()
{
    for (Beacon *b in ArrayThatHoldsBeacons)
    {
        b.hasBeenClicked = NO;
    }
}










/*
  _     _       _           _                _       _                    _
 | |__ (_) __ _| |__       | | _____   _____| |   __| |_ __ __ ___      _(_)_ __   __ _
 | '_ \| |/ _` | '_ \ _____| |/ _ \ \ / / _ \ |  / _` | '__/ _` \ \ /\ / / | '_ \ / _` |
 | | | | | (_| | | | |_____| |  __/\ V /  __/ | | (_| | | | (_| |\ V  V /| | | | | (_| |
 |_| |_|_|\__, |_| |_|     |_|\___| \_/ \___|_|  \__,_|_|  \__,_| \_/\_/ |_|_| |_|\__, |
          |___/                                                                   |___/
 
 */


void DrawBoardComponents()
{
    
    DrawGrid();//increment in inches
    DrawArena();
    
    DrawObstacles();
    //DrawGridUnits();
    DrawBeacons();
    DrawRobot();
}


void DrawGrid()
{
    //need to establish how many pixels correspond to an inch.
    
    int increment = Inches_To_Pixels(GridSpacing);
    CGPoint start, end;
    bool incr_of_twelve;
    
    
    for (int x = 0; x < Width_Of_Viewport_In_Pixels; x += increment)
    {
        //draw verticle grid lines
        
        start = CGPointMake(x, 0);
        
        
        end.x = x;
        end.y = Height_Of_Viewport_In_Pixels;
        
        if (x % twelveInchPixelValue == 0)
        {
            incr_of_twelve = true;
        }
        else
        {
            incr_of_twelve = false;
        }
        
        //Draw_Line(start.x, start.y, end.x, end.y, incr_of_twelve);
        Draw_Line(start, end, incr_of_twelve);
    }
    
    for (int y = 0; y < Height_Of_Viewport_In_Pixels; y+= increment)
    {
        //draw horizontal grid lines
        start = CGPointMake(0, y);
        
        
        end.x = Width_Of_Viewport_In_Pixels;
        end.y = y;
        
        if (y % twelveInchPixelValue == 0)
        {
            incr_of_twelve = true;
        }
        else
        {
            incr_of_twelve = false;
        }
        
        //Draw_Line(start.x, start.y, end.x, end.y, incr_of_twelve);
        Draw_Line(start, end, incr_of_twelve);
        
    }
    
}

void DrawArena()
{
//    CGPoint p1, p2, p3, p4;
//    
//    p1 = CGPointMake(Inches_To_Pixels(12), Inches_To_Pixels(12));
//    p2 = CGPointMake(Inches_To_Pixels(12*7), Inches_To_Pixels(12));
//    p3 = CGPointMake(Inches_To_Pixels(12*7), Inches_To_Pixels(12*7));
//    p4 = CGPointMake(Inches_To_Pixels(12), Inches_To_Pixels(12*7));
//    
//    
//    //Draw_Boundary(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
//    Draw_Boundary(p1, p2, p3, p4);
    
    for (Obstacle *arena_piece in ArenaHolder)
    {
        Draw_Boundary(arena_piece);

    }

    
}

void DrawObstacles()
{
    for (Obstacle *obstacle in ArrayThatHoldsObstacles)
    {
        Draw_Obstacle(obstacle);
    }
    
}

void DrawGridUnits()
{
    for (GridSpace *gridUnit in ArrayThatHoldsGridSpaces)
    {
        
        
        Draw_Grid_Unit(gridUnit);
    }
    
}

void DrawBeacons()
{
    for (Beacon *b in ArrayThatHoldsBeacons)
    {
        Draw_Beacon(b);
    }
}

void DrawRobot()
{
    Draw_Robot([RobotHolder firstObject]);
}



/*
 
 _   _ _   _ _ _ _           _____                 _   _
 | | | | |_(_) (_) |_ _   _  |  ___|   _ _ __   ___| |_(_) ___  _ __  ___
 | | | | __| | | | __| | | | | |_ | | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |_| | |_| | | | |_| |_| | |  _|| |_| | | | | (__| |_| | (_) | | | \__ \
  \___/ \__|_|_|_|\__|\__, | |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
                      |___/
 
 */

float AreaOfSquare(id square, CGPoint point)
{
    if ([square isKindOfClass:[Obstacle class]])
    {
        ///square has point properties
        //need to typecast
        
        Obstacle *s = square;
        
        float area_of_square = 0;
        area_of_square += AreaOfTriangle(s.P1, s.P2, point);
        area_of_square += AreaOfTriangle(s.P2, s.P3, point);
        area_of_square += AreaOfTriangle(s.P3, s.P4, point);
        area_of_square += AreaOfTriangle(s.P4, s.P1, point);
        
        return area_of_square;

    }
    else
    {
        NSLog(@"worse");
        exit(EXIT_FAILURE);
    }
}

bool SquareIntersectsSquare(id square1, id square2)//that is a subclass of Obstacle
{
    if ([square1 isKindOfClass:[Obstacle class]] && [square2 isKindOfClass:[Obstacle class]])
    {
        //both squares have p1..p4 parameters
         Obstacle *s = square1;
         Obstacle *s2 = square2;
        //first need area of square 1
        float square_1_area = AreaOfSquare(square1, s.Center);
        
 
        //calculate the area of square 1 with each of square 2's points
  
        if ( fabs( AreaOfSquare(square1, s2.P1) - square_1_area ) <= 1 )
        {
            //square overlaps
            return true;
        }
        else if ( fabs( AreaOfSquare(square1, s2.P2) - square_1_area ) <= 1 )
        {
                        //square overlaps
            return true;
        }
        else if ( fabs( AreaOfSquare(square1, s2.P3) - square_1_area ) <= 1 )
        {
            //square overlaps
            return true;
        }
        else if ( fabs( AreaOfSquare(square1, s2.P4) - square_1_area ) <= 1 )
        {
            //square overlaps
            return true;
        }
        else return false;
        
        
    }
    else
    {
        NSLog(@"bad");
        exit(EXIT_FAILURE);
    }
    
}

bool CircleContainsPoint(CGPoint p, CGPoint c, float radius)
{
    if (distanceBetween(p, c) <= radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}


float distanceBetween(CGPoint p1, CGPoint p2)
{
    float d;
    d = sqrtf((powf(p2.x-p1.x, 2.0))+(powf(p2.y-p1.y, 2.0)));
    return d;
}

float AreaOfTriangle(CGPoint p1, CGPoint p2, CGPoint p3)
{
    return fabsf((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
}

float slope(float y2, float y1, float x2, float x1)
{
    return (y2-y1)/(x2-x1);
}

float b_intercept_of_line(float slope, CGPoint point)
{
    //y = slope*x + b_intercept
    return point.y - (slope*point.x);
    
}



////////Establish pixel to inches conversion
float Pixels_To_Inches(float pixels)
{
    return pixels/PixelsPerInch ;
}


///////Establish inches to pixel conversion
float Inches_To_Pixels(int inches)
{
    return inches*PixelsPerInch;
}





/*
 BOOL SonarFieldIntersectsObstacle ()
 {
 
 
 SonarField *sonarField = [ArrayThatHoldsSonarField firstObject];
 
 for (Obstacle *obstacle in ArrayThatHoldsObstacles)
 {
 CGPoint arrayOfFieldPoints[3] = {sonarField.P1, sonarField.P2, sonarField.P3};
 CGPoint arrayOfObstaclePoints[5] = {obstacle.P1, obstacle.P2, obstacle.P3, obstacle.P4, obstacle.Center};
 
 
 float A = AreaOfTriangle(sonarField.P1, sonarField.P2, sonarField.P3);
 //NSLog(@"area of sonar field %f", A);
 
 
 //for each of the obstacles 4 points, check if at least one of the points is bounded by the triangle
 for (int m = 0; m < 5; m++)
 {
 float A_1 = 0;
 
 for (int i = 0; i < 2; i++) //for each of the three triangles lines
 {
 for (int j = 0; j < 3; j++)
 {
 if (j == i || i > j)
 {
 continue;
 }
 else
 {
 A_1 += AreaOfTriangle(arrayOfObstaclePoints[m], arrayOfFieldPoints[i], arrayOfFieldPoints[j]);
 
 }
 }
 }
 
 
 if (fabsf(A - A_1) <= .1)
 {
 obstacle.detected = YES;
 break;
 }
 else
 {
 obstacle.detected = NO;
 }
 
 }
 }
 
 
 
 
 float smallest_distance = 1e9;
 
 for (Obstacle *obstacle in ArrayThatHoldsObstacles)
 {
 if (obstacle.detected)
 {
 obstacle.DistanceFromRobot = distanceBetween(obstacle.Center, sonarField.P1);
 
 if (obstacle.DistanceFromRobot < smallest_distance)
 {
 smallest_distance = obstacle.DistanceFromRobot;
 }
 
 }
 //figure out its distance to the sonarfield mount point on robot
 
 
 
 }
 
 for (Obstacle *obstacle in ArrayThatHoldsObstacles)
 {
 if (obstacle.detected)
 {
 if (obstacle.DistanceFromRobot == smallest_distance)
 {
 NSLog(@"obstacle %lu detected", (unsigned long)[ArrayThatHoldsObstacles indexOfObject:obstacle]);
 return YES;
 }
 }
 
 }
 
 
 
 return NO;
 
 
 }
 
 
 */



