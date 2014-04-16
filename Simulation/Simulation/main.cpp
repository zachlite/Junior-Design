//
//  JD Simulation
//  Based off of OpenGL SDL Template created by Zach Lite
//
//  Created by Zach Lite on 2/10/14.
//  Copyright (c) 2014 Zach. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>


#include "SDL/SDL_opengl.h"
#include "SDL/SDL.h"


#include "GameBoard.h"
#include "Drawing.h"
#import "Obstacle.h"



#include "includes.h"


#include <iostream>
using namespace std;



//Function Prototypes
void Initialize_Memory_Attributes();
void Setup_Window_And_Rendering(int screenWidth, int screenHeight);







int main(int argc, char** argv)
{
    
    
    //initialize SDL hardware
	SDL_Init(SDL_INIT_EVERYTHING);
    Initialize_Memory_Attributes();
	Setup_Window_And_Rendering(Width_Of_Viewport_In_Pixels, Height_Of_Viewport_In_Pixels);
    

    NSLog(@"Begin Simulation");
    

    InitGameBoard();
    
    //InitRobot();
    
    
    bool runProgram = true;
    SDL_Event event;

   
    bool mouse_is_clicked = false;
	while (runProgram) //Begin main program loop
	{
		//Events are tied to key presses, mouse movements, etc
		while ( SDL_PollEvent(&event) )
		{
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                cout << "Mouse Pressed" <<endl;
                mouse_is_clicked = true;
            }
            if (event.type == SDL_MOUSEBUTTONUP)
            {
                cout << "Mouse released" <<endl;
                mouse_is_clicked = false;
            }
         
		    if (event.type == SDL_QUIT)
			{
                runProgram = false;
			}
            
		    if ( (event.type == SDL_KEYUP) && (event.key.keysym.sym == SDLK_ESCAPE))//release a key
			{
                runProgram = false;
			}
        }
        
        
        
        //Logic Goes Here
  
        if (mouse_is_clicked)
        {   CGPoint mouseCoord = CGPointMake(event.motion.x, event.motion.y);
            NSLog(@"mouse at %f %f", mouseCoord.x, mouseCoord.y);
            CheckIfClickedAtCoordinate(mouseCoord);
            PositionBeaconsClickedAtCoordinate(mouseCoord);
        }
        else
        {
            ResetBeaconManipulation();
        }
        
        
        
        
        
        
        //Render to the screen
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();//start phase
        glOrtho(0,Width_Of_Viewport_In_Pixels,Height_Of_Viewport_In_Pixels,0,-1,1);//set the matrix
        /////////////////////////////////////////////
    
 
       
        DrawBoardComponents();
       
        
     
       
        
        ///////////////////////////////////////////
        //end rendering
		glPopMatrix();//end
		SDL_GL_SwapBuffers();//re-draws
        
        SDL_Delay(100);//ms
    }//end while
    
    return 0;
}//end main




















void Initialize_Memory_Attributes()
{
    //Set OpenGL memory usage
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
    
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
        
}

void Setup_Window_And_Rendering(int screenWidth, int screenHeight)
{
    
    SDL_WM_SetCaption ("Simulation", NULL); //window caption
    SDL_SetVideoMode(screenWidth,screenHeight,32,SDL_OPENGL); //window size, rendering settings
    //draw something every frame
    glClearColor(1,1,1,1); // color used to clear screen every frame
        



    glViewport(0,0,screenWidth,screenHeight); //viewing area
        
    glShadeModel(GL_SMOOTH);//shader model
        
    glMatrixMode(GL_PROJECTION);//2D rendering
    glLoadIdentity();//"save" it
        
    glDisable(GL_DEPTH_TEST);//disable depth checking for 2D rendering
        
        
}




