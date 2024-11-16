/***********************************************************************
 * Header File:
 *    SIMULATION OBJECT
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The base class for all kinds of satellite
 ************************************************************************/

#pragma once
#include "Position.h"
#include "velocity.h"
#include "Acceleration.h"
#include <list>

using namespace std;

class TestSimulationObject;

/***************************************************
 * SIMULATION OBJECT
 * The base class
 ***************************************************/
class SimulationObject
{
public:
   friend TestSimulationObject; // for unit test
   
   // constructor
   SimulationObject() { this->radius = 0.0; this->mass = 0.0; }
   SimulationObject(Position pos, Velocity vel, double radius, double mass)
   {
      
   }
   virtual ~SimulationObject() {}
   
   // getters
   virtual const Position & getPosition() { return pos; }
   virtual const Velocity & getVelocity() { return vel; }
   virtual const Acceleration & getAcceleration() { return a; }
   virtual const double getRadius() { return radius; }
   virtual const double getMass() { return mass; }
   
   virtual bool collidesWith(SimulationObject obj);
   
protected:
   Position pos;
   Velocity vel;
   Acceleration a;
   double radius;
   double mass;
   
private:
   void applyGravity();
};
