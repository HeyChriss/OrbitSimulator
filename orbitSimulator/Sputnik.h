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
      pos.setMetersX(this->config.initialX);
      pos.setMetersY(this->config.initialY);
      vel.setDx(this->config.initialDX);
      vel.setDy(this->config.initialDY);
      a.setDDx(this->config.initialDDX);
      a.setDDy(this->config.initialDDY);
   }
   list<SimulationObject> breakApart();
   void update(double deltaTime);
   void draw(ogstream & gout);
};
