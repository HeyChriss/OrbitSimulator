/***********************************************************************
 * Header File:
 *    SATELLITE: SPUTNIK
 * Author:
 *    Chris Mijangos and Seth Chan
 ************************************************************************/


#pragma once
#include "cmath"
#include "Satellite.h"
#include "velocity.h"
#include "uiDraw.h"

class Sputnik : public Satellite
{
public:
    Sputnik() : Satellite(SPUTNIK)
    {
        radius = this->config.radius;
        type = SPUTNIK;

        // Initialize position in meters
        pos.setPixelsX(config.initialX);
        pos.setPixelsY(config.initialY);

        // Initialize velocity
        vel.setDx(config.initialDX);
        vel.setDy(config.initialDY);

        a.setDDx(config.initialDDX);
        a.setDDy(config.initialDDY);
    }

    //list<SimulationObject> breakApart();
    void update(double deltaTime, SatelliteType type)
    {
        // Get position in pixels for calculation
        double x = pos.getPixelsX();  // This converts from meters to pixels
        double y = pos.getPixelsY();

        // Calculate distance from center in meters
        double r = sqrt(x * x + y * y);
        if (r < 1.0) r = 1.0;

        // Calculate acceleration towards center
        double aScale = 0.01;  // Adjusted for meters
        double ax = -(aScale * x / r);
        double ay = -(aScale * y / r);

        // Set acceleration
        a.setDDx(ax);
        a.setDDy(ay);

        // Update velocity using acceleration
        vel.addDx(a.getDDx() * deltaTime);
        vel.addDy(a.getDDy() * deltaTime);

        // Update position using velocity in meters
        pos.addPixelsX(vel.getDx() * deltaTime);
        pos.addPixelsY(vel.getDy() * deltaTime);
    }

    void draw(ogstream gout);
};

