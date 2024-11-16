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
   assertEquals(s.config.initialDDX, 0.0);
   assertEquals(s.config.initialDDY, 0.0);
   assertEquals(s.config.radius, 0.058);
} // teardown

/***************************************************
 * Update:
 * Input:
 * Output:
 ***************************************************/
void TestSputnik::test_update()
{
   // setup
   // exercise
   Sputnik s;
   
   // verify
   
} // teardown
