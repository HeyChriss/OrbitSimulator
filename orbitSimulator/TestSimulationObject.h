/***********************************************************************
 * Header File:
 *    TEST SIMULATION OBJECT
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    Test the SimulationObject class
 ************************************************************************/

#pragma once
#include "unitTest.h"
#include "SimulationObject.h"

class TestSimulationObject : public UnitTest
{
public:
   void run()
   {
      constructor_default();
      
      // test getters
      test_getPosition();
      test_getVelocity();
      test_getAcceleration();
      test_getRadius();
      test_getMass();
      collidesWith_collide();
      collidesWith_nothing();
      
      report("SimulationObject");
      
   }
   
private:
   void constructor_default();
   
   void test_getPosition();
   void test_getVelocity();
   void test_getAcceleration();
   void test_getRadius();
   void test_getMass();
   void collidesWith_collide();
   void collidesWith_nothing();
};
