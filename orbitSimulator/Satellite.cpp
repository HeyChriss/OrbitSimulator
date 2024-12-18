/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The satellite inherits from SimulationObject
 ************************************************************************/


#include "Satellite.h"

/***************************************************
 * INITIALIZE CONFIG
 * Input:
 * Output: void
 ***************************************************/
void Satellite::initializeConfig(SatelliteType type)
{
   switch (type)
   {
      case SPUTNIK:
         this->config.initialX = -36515095.13;
         this->config.initialY = 21082000.0;
         this->config.initialDX = 2050.0;
         this->config.initialDY = 2684.68;
         this->config.initialDDX = cos(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.initialDDY = sin(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.radius = 0.058;
         break;
         
      case HUBBLE:
         this->config.initialX = 0.0;
         this->config.initialY = -42164000.0;
         this->config.initialDX = 3100.0;
         this->config.initialDY = 0.0;
         this->config.initialDDX = cos(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.initialDDY = sin(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.radius = 0.0;    // remember to change to its simulated radius
         break;
      case DRAGONCREW:
         this->config.initialX = 0.0;
         this->config.initialY = 8000000.0;
         this->config.initialDX = -7900.0;
         this->config.initialDY = 0.0;
         this->config.initialDDX = cos(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.initialDDY = sin(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.radius = 0.0;    // remember to change to its simulated radius
         break;
      case STARLINK:
         this->config.initialX = 0.0;
         this->config.initialY = -13020000.0;
         this->config.initialDX = 5800.0;
         this->config.initialDY = 0.0;
         this->config.initialDDX = cos(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.initialDDY = sin(atan2(0.0 - this->config.initialY, 0.0 - this->config.initialX));
         this->config.radius = 0.0;    // remember to change to its simulated radius
         break;
      case GPS:
         this->gpsConfig.push_back(SatelliteConfiguration(0.0, 26560000.0, -3880.0, 0.0));
         this->gpsConfig.push_back(SatelliteConfiguration(23001634.72, 13280000.0, -1940.0, 3360.18));
         this->gpsConfig.push_back(SatelliteConfiguration(23001634.72, -13280000.0, 1940.0, 3360.18));
         this->gpsConfig.push_back(SatelliteConfiguration(0.0, -26560000.0, 3880.0, 0.0));
         this->gpsConfig.push_back(SatelliteConfiguration(-23001634.72, -13280000.0, 1940.0, -3360.18));
         this->gpsConfig.push_back(SatelliteConfiguration(-23001634.72, 13280000.0, -1940.0, -3360.18));
      default:
         break;
   }
}

/***************************************************
 * BREAK APART
 * Input:
 * Output: a list of SimulationObject
 ***************************************************/
list<SimulationObject> Satellite::breakApart()
{
   return list<SimulationObject>();
}

/***************************************************
 * GET CONFIGURATION
 * Input:
 * Output: satellite configuration
 ***************************************************/
const SatelliteConfiguration Satellite::getConfiguration()
{
   return SatelliteConfiguration();
}
