/***********************************************************************
 * Source File:
 *    SIMULATOR
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    Creates the simulator class 
 ************************************************************************/


#include <cassert>
#include "uiInteract.h"
#include "uiDraw.h"
#include "Position.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "test.h"
#include "Sputnik.h" 
using namespace std;

class Simulator
{
public:
    Simulator(Position ptUpperRight) : ptUpperRight(ptUpperRight)
    {
        // Create Sputnik instance
        sputnik = new Sputnik();

        // Initialize stars with random positions
        for (int i = 0; i < NUM_STARS; i++)
        {
            // Random position across the screen
            starPositions[i].setPixelsX(random(-500.0, 500.0));  
            starPositions[i].setPixelsY(random(-500.0, 500.0));

            // Random initial phase for twinkling
            starPhases[i] = random(0, 255);
        }

    }

    ~Simulator()
    {
        delete sputnik;
    }

    void update(double deltaTime)
    {
        if (sputnik != nullptr)
        {
            sputnik->update(deltaTime, SPUTNIK);
        }
    }

    Position getPosition() const
    {
        return sputnik->getPosition();
    }

    double getAngle() const
    {
        return atan2(sputnik->getVelocity().getDy(),
            sputnik->getVelocity().getDx());
    }

    // Add these methods to draw stars
    void drawStars(ogstream& gout)
    {
        for (int i = 0; i < NUM_STARS; i++)
        {
            gout.drawStar(starPositions[i], starPhases[i]);
            starPhases[i] = (starPhases[i] + 1) % 256;
        }
    }

private:
    Position ptUpperRight;
    Sputnik* sputnik;
    static const int NUM_STARS = 100;  // Number of stars to draw
    Position starPositions[NUM_STARS];
    unsigned char starPhases[NUM_STARS];

};

void callBack(const Interface* pUI, void* p)
{
    Simulator* pSim = (Simulator*)p;
    pSim->update(1);

    // Draw Earth at center
    Position ptEarth;
    ogstream gout(ptEarth);

    // Draw stars first (background)
    pSim->drawStars(gout);


    // Draw Sputnik last (foreground)
    gout.drawSputnik(pSim->getPosition(), pSim->getAngle());
}

int main(int argc, char** argv)
{
    testRunner();

    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);

    Interface ui(0, NULL, "Orbit Simulator", ptUpperRight);
    Simulator simulator(ptUpperRight);
    ui.run(callBack, &simulator);

    return 0;
}