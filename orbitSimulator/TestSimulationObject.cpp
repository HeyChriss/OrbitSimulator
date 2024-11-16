/***********************************************************************
 * Source File:
 *    TEST SIMULATION OBJECT
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    Test the SimulationObject class
 ************************************************************************/

#include "TestSimulationObject.h"

/*************************************
 * Constructor : default
 * Input:
 * Output: source=INVALID
 *         dest  =INVALID
 **************************************/
void TestSimulationObject::constructor_default()
{
   // setup
   // exercise
   SimulationObject obj;
   
   // verify
   assertEquals(obj.radius, 0.0);
   assertEquals(obj.mass, 0.0);
   } // teardown

/*************************************
 * GetPosition: default
 * Input:
 * Output: Position
 **************************************/
void TestSimulationObject::test_getPosition()
{
   // setup
   SimulationObject obj;
   Position pos;
   Position p;
   
   // exercise
   p = obj.getPosition();
   
   // verify
   assertEquals(p.getMetersX(), pos.getMetersX());
   assertEquals(p.getMetersY(), pos.getMetersY());
} // teardown

/*************************************
 * GetVelocity: default
 * Input:
 * Output: Velocity
 **************************************/
void TestSimulationObject::test_getVelocity()
{
   // setup
   Velocity vel;
   SimulationObject obj;
   
   Velocity v;
   
   // exercise
   v = obj.getVelocity();
   
   // verify
   assertEquals(v.getSpeed(), vel.getSpeed());
} // teardown

/*************************************
 * GetAcceleration: default
 * Input:
 * Output: Acceleration
 **************************************/
void TestSimulationObject::test_getAcceleration()
{
   // setup
   SimulationObject obj;
   Acceleration acc;
   Acceleration a;
   
   // exercise
   a = obj.getAcceleration();
   
   // verify
   assertEquals(a.getDDx(), acc.getDDx());
   assertEquals(a.getDDy(), acc.getDDy());
} // teardown

/*************************************
 * GetRadius
 * Input:
 * Output: Radius
 **************************************/
void TestSimulationObject::test_getRadius()
{
   // setup
   SimulationObject obj;
   double r;
   
   // exercise
   r = obj.getRadius();
   
   // verify
   assertEquals(r, 0.0);
} // teardown

/*************************************
 * GetMass
 * Input:
 * Output: Mass
 **************************************/
void TestSimulationObject::test_getMass()
{
   // setup
   SimulationObject obj;
   double m;
   
   // exercise
   m = obj.getMass();
   
   // verify
   assertEquals(m, 0.0);
} // teardown

/*************************************
 * TEST COLLIDES WITH: collide
 * Input: SimulationObject
 * Output: bool
 **************************************/
void TestSimulationObject::collidesWith_collide()
{
   // setup
   SimulationObject obj1;
   obj1.radius = 0.5;
   
   SimulationObject obj2;
   obj2.pos.x = 1.0;
   obj2.pos.y = 1.0;
   obj2.radius = 0.5;
   
   bool isCollide;
   
   // exercise
   isCollide = obj1.collidesWith(obj2);
   
   // verify
   assertEquals(obj1.pos.x, 0.0);
   assertEquals(obj1.pos.y, 0.0);
   assertEquals(obj2.pos.x, 1.0);
   assertEquals(obj2.pos.y, 1.0);
   assertEquals(isCollide, true);
} // teardown

/*************************************
 * TEST COLLIDES WITH: nothing
 * Input: SimulationObject
 * Output: bool
 **************************************/
void TestSimulationObject::collidesWith_nothing()
{
   // setup
   SimulationObject obj1;
   obj1.radius = 5.0;
   
   SimulationObject obj2;
   obj2.pos.x = 1.0;
   obj2.pos.y = 1.1;
   obj2.radius = 5.0;

   bool isCollide;
   
   // exercise
   isCollide = obj1.collidesWith(obj2);
   
   // verify
   assertEquals(obj1.pos.x, 0.0);
   assertEquals(obj1.pos.y, 0.0);
   assertEquals(obj2.pos.x, 1.0);
   assertEquals(obj2.pos.y, 1.1);
   assertEquals(isCollide, false);
} // teardown
