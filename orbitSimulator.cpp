
// orbitSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "uiInteract.h"      // for INTERFACE
#include "uiDraw.h"            // for RANDOM and DRAW*
#include "SimulationObject.h"
#include "Satellite.h"
#include "Sputnik.h"
#include "test.h"
#include "test.h"
#include <iostream>
#include <cassert>             // for ASSERT


using namespace std;


/*************************************************************************
 * Simulator
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

       // Constants
      const double EARTH_RADIUS = 6378000.0;    // meters
      const double HOURS_PER_DAY = 24;
      const double MINUTES_PER_HOUR = 60;
      const double SECONDS_PER_DAY = 86400.0;

      // Time dilation calculations
      timeDilation = HOURS_PER_DAY * MINUTES_PER_HOUR;  // 1440
      timePerFrame = timeDilation / 30.0;  // 30 is the frameRate

      // Earth rotation per frame
      rotationPerFrame = -(2.0 * 3.1416 / 30.0) * (timeDilation / SECONDS_PER_DAY);
   }
   
   Sputnik sputnik;
   Position ptUpperRight;

   double angleShip;
   double angleEarth;
   double timeDilation;
   double timePerFrame;
   double rotationPerFrame;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Simulator* pSimulator = (Simulator*)p;
   
   // udpate Sputnik
   pSimulator->sputnik.update(pSimulator->timePerFrame);
   pSimulator->angleEarth += pSimulator->rotationPerFrame;
   
   // draw sputnik
   Position pt;
   ogstream pgout;
   
   pt.setMetersX(-3651.5095130000003);
   pt.setMetersY(2108.20000);
   // pSimulator->sputnik.draw(pgout);
   pgout.drawSputnik(pt, pSimulator->rotationPerFrame);
}

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator simulator(ptUpperRight);

   // set everything into action
   ui.run(callBack, &simulator);


   return 0;
}
