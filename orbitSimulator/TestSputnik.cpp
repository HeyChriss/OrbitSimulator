/***********************************************************************
 * Source File:
 *    TEST SPUTNIK
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The test sputnik class
 ************************************************************************/


#include "TestSputnik.h"

/***************************************************
 * Constructor: default
 * Input:
 * Output:
 ***************************************************/
void TestSputnik::constructor_default()
{
   // setup
   // exercise
   Sputnik s;
   
   // verify
   assertEquals(s.type, SPUTNIK);
   assertEquals(s.config.initialX, -36515095.13);
   assertEquals(s.config.initialY, 21082000.0);
   assertEquals(s.config.initialDX, 2050.0);
   assertEquals(s.config.initialDY, 2684.68);
   assertEquals(s.config.initialDDX, 0.86602540381309423);
   assertEquals(s.config.initialDDY, -0.49999999995036715);
   assertEquals(s.config.radius, 0.058);
} // teardown

/***************************************************
 * Update: 1 frame
 * Input: the change of orbital position in 1 frame(48 seconds)
 * Output:
 ***************************************************/
void TestSputnik::update_1frame()
{
   // setup
   Sputnik s;
   
   // exercise
   s.update(48);
   
   // verify
   assertEquals(s.pos.x, -36416528);
   assertEquals(s.pos.y, 21210768);
   assertEquals(s.vel.dx, 2057.0376);
   assertEquals(s.vel.dy, 2680.6167);
   assertEquals(s.a.ddx, 0.86602540381309423);
   assertEquals(s.a.ddy, -0.49999999995036715);
} // teardown

/***************************************************
 * Update: 2 frame
 * Input: the change of orbital position in 2 frame(96 seconds)
 * Output:
 ***************************************************/
void TestSputnik::update_2frame()
{
   // setup
   Sputnik s;
   
   // exercise
   s.update(96);
   
   // verify
   assertEquals(s.pos.x, -36317620.0);
   assertEquals(s.pos.y, 21339340.0);
   assertEquals(s.vel.dx, 2064.0752);
   assertEquals(s.vel.dy, 2676.55347);
   assertEquals(s.a.ddx, 0.866025388);
   assertEquals(s.a.ddy, -0.5);
} // teardown
