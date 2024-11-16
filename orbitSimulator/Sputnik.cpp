/***********************************************************************
 * Source File:
 *    SATELLITE: SPUTNIK
 * Author:
 *    Chris Mijangos and Seth Chan
 ************************************************************************/


#include "Sputnik.h"

/***************************************************
 * BREAK APART
 * Input:
 * Output: a list of SimulationObject
 ***************************************************/
list<SimulationObject> Sputnik::breakApart()
{
   // not for this week
   return list<SimulationObject>();
}

/***************************************************
 * UPDATE
 * Input:
 * Output:
 ***************************************************/
void Sputnik::update(double deltaTime)
{
   // Calculate gravity
   double altitude = (sqrt(this->getPosition().getMetersX() * this->getPosition().getMetersX() +
                      this->getPosition().getMetersY() * this->getPosition().getMetersY() -
                           6378000.0));
   double gMagnitude = 9.80665 * (6378000.0 / (6378000.0 + altitude)) * (6378000.0 / (6378000.0 + altitude));
   double gDirection = atan2(0.0 - this->getPosition().getMetersY(), 0.0 - this->getPosition().getMetersX());
   
   // Calculate acceleration components - gravity points toward Earth's center
   double ddx = gMagnitude * cos(gDirection);
   double ddy = gMagnitude * sin(gDirection);
   
   // Update velocity using: v = v₀ + at
   double x0 = this->getPosition().getMetersX();
   double y0 = this->getPosition().getMetersY();
   double dx0 = this->getVelocity().getDx();
   double dy0 = this->getVelocity().getDy();
   
   // Then update position using updated velocity: s = s₀ + vt
   this->vel.setDx(dx0 + ddx * deltaTime);
   this->vel.setDy(dy0 + ddy * deltaTime);

   // Update positions using: x = x₀ + v₀t + ½at²
   double newX = x0 + dx0 * deltaTime + 0.5 * ddx * deltaTime * deltaTime;
   double newY = y0 + dy0 * deltaTime + 0.5 * ddy * deltaTime * deltaTime;

   // Update position
   this->pos.setMetersX(newX);
   this->pos.setMetersY(newY);

   // Calculate angle for satellite display
   this->radius = atan2(this->vel.getDy(), this->vel.getDx());
   
   // Rotation per frame
   // rotationPerFrame = -(2.0 * 3.1416 / 30.0) * (timeDilation / 86400.0);
}

/***************************************************
 * DRAW
 * Input:
 * Output:
 ***************************************************/
void Sputnik::draw(ogstream & gout)
{
   gout.drawSputnik(this->pos, 0.0);
}
