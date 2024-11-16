/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    All the test function sare defined here
 ************************************************************************/


#include "TestSatellite.h"

/*************************************
 * Constructor : SPUTNIK
 * Input:
 * Output
 **************************************/
void TestSatellite::constructor_SPUTNIK()
{
   // setup
   // exercise
   Satellite s(SPUTNIK);

   // verify
   assertEquals(s.config.initialX, -36515095.13);
   assertEquals(s.config.initialY, 21082000.0);
   assertEquals(s.config.initialDX, 2050.0);
   assertEquals(s.config.initialDY, 2684.68);
   assertEquals(s.config.initialDDX, 0.0);
   assertEquals(s.config.initialDDY, 0.0);
} // teadown

/*************************************
 * Constructor : HUBBLE
 * Input:
 * Output
 **************************************/
void TestSatellite::constructor_HUBBLE()
{
   // setup
   // exercise
   Satellite s(HUBBLE);

   // verify
   assertEquals(s.config.initialX, 0.0);
   assertEquals(s.config.initialY, -42164000.0);
   assertEquals(s.config.initialDX, 3100.0);
   assertEquals(s.config.initialDY, 0.0);
   assertEquals(s.config.initialDDX, 0.0);
   assertEquals(s.config.initialDDY, 0.0);
} // teadown

/*************************************
 * Constructor : DRAGONCREW
 * Input:
 * Output
 **************************************/
void TestSatellite::constructor_DRAGONCREW()
{
   // setup
   // exercise
   Satellite s(DRAGONCREW);

   // verify
   assertEquals(s.config.initialX, 0.0);
   assertEquals(s.config.initialY, 8000000.0);
   assertEquals(s.config.initialDX, -7900.0);
   assertEquals(s.config.initialDY, 0.0);
   assertEquals(s.config.initialDDX, 0.0);
   assertEquals(s.config.initialDDY, 0.0);
} // teadown

/*************************************
 * Constructor : STARLINK
 * Input:
 * Output
 **************************************/
void TestSatellite::constructor_STARLINK()
{
   // setup
   // exercise
   Satellite s(STARLINK);

   // verify
   assertEquals(s.config.initialX, 0.0);
   assertEquals(s.config.initialY, -13020000.0);
   assertEquals(s.config.initialDX, 5800.0);
   assertEquals(s.config.initialDY, 0.0);
   assertEquals(s.config.initialDDX, 0.0);
   assertEquals(s.config.initialDDY, 0.0);
} // teadown

/*************************************
 * Constructor : GPS
 * Input:
 * Output
 **************************************/
void TestSatellite::constructor_GPS()
{
   // setup
   // exercise
   Satellite s(GPS);

   // verify
   assertEquals(s.gpsConfig.size(), 6);
   assertEquals(s.gpsConfig[0].initialX, 0.0);
   assertEquals(s.gpsConfig[0].initialY, 26560000.0);
   assertEquals(s.gpsConfig[0].initialDX, -3880.0);
   assertEquals(s.gpsConfig[0].initialDY, 0.0);
   assertEquals(s.gpsConfig[1].initialX, 23001634.72);
   assertEquals(s.gpsConfig[1].initialY, 13280000.0);
   assertEquals(s.gpsConfig[1].initialDX, -1940.0);
   assertEquals(s.gpsConfig[1].initialDY, 3360.18);
   assertEquals(s.gpsConfig[2].initialX,  23001634.72);
   assertEquals(s.gpsConfig[2].initialY, -13280000.0);
   assertEquals(s.gpsConfig[2].initialDX, 1940.0);
   assertEquals(s.gpsConfig[2].initialDY, 3360.18);
   assertEquals(s.gpsConfig[3].initialX, 0.0);
   assertEquals(s.gpsConfig[3].initialY, -26560000.0);
   assertEquals(s.gpsConfig[3].initialDX, 3880.0);
   assertEquals(s.gpsConfig[3].initialDY, 0.0);
   assertEquals(s.gpsConfig[4].initialX,  -23001634.72);
   assertEquals(s.gpsConfig[4].initialY, -13280000.0);
   assertEquals(s.gpsConfig[4].initialDX, 1940.0);
   assertEquals(s.gpsConfig[4].initialDY, -3360.18);
   assertEquals(s.gpsConfig[5].initialX, -23001634.72);
   assertEquals(s.gpsConfig[5].initialY, 13280000.0);
   assertEquals(s.gpsConfig[5].initialDX, -1940.0);
   assertEquals(s.gpsConfig[5].initialDY, -3360.18);
} // teadown
