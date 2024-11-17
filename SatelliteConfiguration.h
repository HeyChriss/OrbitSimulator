/***********************************************************************
 * Header File:
 *    SATELLITE CONFIGURATION
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    A struct  to handle the configuration for different satellite
 ************************************************************************/


#pragma once

struct SatelliteConfiguration
{
    SatelliteConfiguration() {}
    SatelliteConfiguration(SatelliteConfiguration&&) = default;
    SatelliteConfiguration(double x, double y, double dx, double dy)
    {
        initialX = x;
        initialY = y;
        initialDX = dx;
        initialDY = dy;
        initialDDX = 0.0;
        initialDDY = 0.0;
    }
    // Inline initialization method
    inline void initializeConfig(SatelliteType type)
    {
        switch (type)
        {
        case SPUTNIK:
            initialX = 100;    
            initialY = 0.0;
            initialDX = 0.0;
            initialDY = 0.5;      // 0.5 pixels/frame * 1000 meters/pixel
            initialDDX = 0.0;
            initialDDY = 0.0;
            radius = 0.058;
            break;
        case HUBBLE:
            initialX = 0.0;
            initialY = -42164000.0;
            initialDX = 3100.0;
            initialDY = 0.0;
            initialDDX = 0.0;
            initialDDY = 0.0;
            radius = 0.0;
            break;
        case DRAGONCREW:
            initialX = 0.0;
            initialY = 8000000.0;
            initialDX = -7900.0;
            initialDY = 0.0;
            initialDDX = 0.0;
            initialDDY = 0.0;
            radius = 0.0;
            break;
        case STARLINK:
            initialX = 0.0;
            initialY = -13020000.0;
            initialDX = 5800.0;
            initialDY = 0.0;
            initialDDX = 0.0;
            initialDDY = 0.0;
            radius = 0.0;
            break;
        default:
            initialX = 0.0;
            initialY = 0.0;
            initialDX = 0.0;
            initialDY = 0.0;
            initialDDX = 0.0;
            initialDDY = 0.0;
            radius = 0.0;
            break;
        }
    }

    double initialX;
    double initialY;
    double initialDX;
    double initialDY;
    double initialDDX;
    double initialDDY;
    double radius;
    int fragmentCount;
};


