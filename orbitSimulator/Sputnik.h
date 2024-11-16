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
   Sputnik() : Satellite(SPUTNIK) { radius = this->config.radius; type = SPUTNIK; }
   list<SimulationObject> breakApart();
   void update(double deltaTime, SatelliteType type);
   // void draw(ogstream gout);
};
