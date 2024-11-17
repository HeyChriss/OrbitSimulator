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
        this->config.initialX = 100;
        this->config.initialY = 100;
        this->config.initialDX = 0.0;
        this->config.initialDY = 0.5;
        this->config.initialDDX = 0.0;
        this->config.initialDDY = 15;
        this->config.radius = 0.058;
        radius = 0.058;
        break;

    case HUBBLE:
        this->config.initialX = 0.0;
        this->config.initialY = -42164000.0;
        this->config.initialDX = 3100.0;
        this->config.initialDY = 0.0;
        this->config.initialDDX = 0.0;
        this->config.initialDDY = 0.0;
        this->config.radius = 0.0;    // Change to its simulated radius
        break;
    case DRAGONCREW:
        this->config.initialX = 0.0;
        this->config.initialY = 8000000.0;
        this->config.initialDX = -7900.0;
        this->config.initialDY = 0.0;
        this->config.initialDDX = 0.0;
        this->config.initialDDY = 0.0;
        this->config.radius = 0.0;    // Change to its simulated radius
        break;
    case STARLINK:
        this->config.initialX = 0.0;
        this->config.initialY = -13020000.0;
        this->config.initialDX = 5800.0;
        this->config.initialDY = 0.0;
        this->config.initialDDX = 0.0;
        this->config.initialDDY = 0.0;
        this->config.radius = 0.0;    // Change to its simulated radius
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
    list<SimulationObject> fragments;

    // For now, return an empty list of fragments
    // You can implement the actual fragmentation logic later

    return fragments;
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
