
// orbitSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>      // for ASSERT
//#include "uiInteract.h" // for INTERFACE
//#include "uiDraw.h"     // for RANDOM and DRAW*
#include "SimulationObject.h"
#include "test.h"
using namespace std;

#include <iostream>
#include "test.h"

int main()
{
    testRunner();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


///*************************************************************************
// * Simulator
// * Test structure to capture the LM that will move around the screen
// *************************************************************************/
//class Simulator
//{
//public:
//   Simulator(Position ptUpperRight) :
//      ptUpperRight(ptUpperRight)
//   {
//
//       // Constants
//      const double EARTH_RADIUS = 6378000.0;    // meters
//      const double HOURS_PER_DAY = 24;
//      const double MINUTES_PER_HOUR = 60;
//      const double SECONDS_PER_DAY = 86400.0;
//
//      // Time dilation calculations
//      timeDilation = HOURS_PER_DAY * MINUTES_PER_HOUR;  // 1440
//      timePerFrame = timeDilation / 30.0;  // 30 is the frameRate
//
//      // Earth rotation per frame
//      rotationPerFrame = -(2.0 * 3.1416 / 30.0) * (timeDilation / SECONDS_PER_DAY);
//
//      // Place the ptGPS at the equator
//      ptGPS.setMetersX(0.0);
//      ptGPS.setMetersY(42164000.0);
//      
//      // Initial velocity for GEO
//      dx = -3100.0;  // m/s
//      dy = 0.0;      // m/s
//
//      // Star information
//      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      angleShip = 0.0;
//      angleEarth = 0.0;
//      phaseStar = 100;
//   }
//
//   // Calculate height above Earth's surface
//   double getHeight()
//   {
//      double x = ptGPS.getMetersX();
//      double y = ptGPS.getMetersY();
//      return sqrt(x * x + y * y) - 6378000.0;  // Earth radius in meters
//   }
//
//   // Calculate gravitational acceleration at current position
//   double getGravityMagnitude()
//   {
//      double h = getHeight();
//      const double G = 9.80665;  // m/s^2
//      const double R = 6378000.0; // Earth radius in meters
//      return G * pow(R / (R + h), 2.0);
//   }
//
//   // Get direction of gravity (angle from satellite to Earth's center)
//   double getGravityDirection()
//   {
//      double xe = 0.0;  // Earth's center x position
//      double ye = 0.0;  // Earth's center y position
//      double xs = ptGPS.getMetersX();  // Satellite x position
//      double ys = ptGPS.getMetersY();  // Satellite y position
//
//      return atan2(ye - ys, xe - xs);  // atan2 takes (y, x)
//   }
//
//
//   Position ptHubble;
//   Position ptSputnik;
//   Position ptStarlink;
//   Position ptCrewDragon;
//   Position ptShip;
//   Position ptGPS;
//   Position ptStar;
//   Position ptUpperRight;
//   Position velocityGPS;  // Velocity of the satellite
//
//   double dx;               // horizontal velocity (m/s)
//   double dy;               // vertical velocity (m/s)
//
//   unsigned char phaseStar;
//
//   double angleShip;
//   double angleEarth;
//   double timeDilation;
//   double timePerFrame;
//   double rotationPerFrame;
//};
//
///*************************************
// * All the interesting work happens here, when
// * I get called back from OpenGL to draw a frame.
// * When I am finished drawing, then the graphics
// * engine will wait until the proper amount of
// * time has passed and put the drawing on the screen.
// **************************************/
//void callBack(const Interface* pUI, void* p)
//{
//   // the first step is to cast the void pointer into a game object. This
//   // is the first step of every single callback function in OpenGL.
//   Simulator* pSimulator = (Simulator*)p;
//
//   
//
//   //
//   // accept input
//   //
//
//   // move by a little
//   if (pUI->isUp())
//      pSimulator->ptShip.addPixelsY(1.0);
//   if (pUI->isDown())
//      pSimulator->ptShip.addPixelsY(-1.0);
//   if (pUI->isLeft())
//      pSimulator->ptShip.addPixelsX(-1.0);
//   if (pUI->isRight())
//      pSimulator->ptShip.addPixelsX(1.0);
//
//
//   //
//   // perform all the game logic
//   //
//
//   // Update Earth's rotation
//   pSimulator->angleEarth += pSimulator->rotationPerFrame;
//   pSimulator->phaseStar++;
//
//   //
//   // draw everything
//   //
//
//   Position pt;
//   ogstream gout(pt);
//
//   // draw satellites
//   //gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
//   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
//   gout.drawSputnik   (pSimulator->ptSputnik,    pSimulator->angleShip);
//   //gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
//   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
//   //gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
//
//   // draw parts
//   //pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
//   //pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
//   //gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
//   //pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
//   //pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
//   //gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
//   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
//   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
//   //gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
//   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
//   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
//   //gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set
//
//   // draw fragments
//   //pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
//   //pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
//   //gout.drawFragment(pt, pDemo->angleShip);
//   //pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
//   //pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
//   //gout.drawFragment(pt, pDemo->angleShip);
//
//   // draw a single star
//   gout.drawStar(pSimulator->ptStar, pSimulator->phaseStar);
//
//   // draw the earth
//   pt.setMetersX(0.0);
//   pt.setMetersY(0.0);
//   gout.drawEarth(pt, pSimulator->angleEarth);
//}
//
//
///*********************************
// * Initialize the simulation and set it in motion
// *********************************/
//#ifdef _WIN32_X
//#include <windows.h>
//int WINAPI wWinMain(
//   _In_ HINSTANCE hInstance,
//   _In_opt_ HINSTANCE hPrevInstance,
//   _In_ PWSTR pCmdLine,
//   _In_ int nCmdShow)
//#else // !_WIN32
//int main(int argc, char** argv)
//#endif // !_WIN32
//{
//
//   testRunner();
//
//   // Initialize OpenGL
//   Position ptUpperRight;
//   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
//   ptUpperRight.setPixelsX(1000.0);
//   ptUpperRight.setPixelsY(1000.0);
//   Interface ui(0, NULL,
//      "Demo",   /* name on the window */
//      ptUpperRight);
//
//   // Initialize the demo
//   Simulator simulator(ptUpperRight);
//
//   // set everything into action
//   ui.run(callBack, &simulator);
//
//
//   return 0;
//}
