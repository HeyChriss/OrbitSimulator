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
   
   double initialX;
   double initialY;
   double initialDX;
   double initialDY;
   double initialDDX;
   double initialDDY;
   double radius;
   int fragmentCount;
};

//public:
//   SatelliteConfiguration(double x, double y, double dx, double dy)
//   {
//      initialX = x;
//      initialY = y;
//      initialDX = dx;
//      initialDY = dy;
//      initialDDX = 0.0;
//      initialDDY = 0.0;
//   }
//   
//   SatelliteConfiguration(const SatelliteConfiguration& other)
//       : initialX(other.initialX), initialY(other.initialY),
//         initialDX(other.initialDX), initialDY(other.initialDY) {}
//   
//   SatelliteConfiguration& operator=(const SatelliteConfiguration & rhs)
//   {
//      initialX = rhs.initialX;
//      initialY = rhs.initialY;
//      initialDX = rhs.initialDX;
//      initialDY = rhs.initialDY;
//      initialDDX = rhs.initialDDX;
//      initialDDY = rhs.initialDDY;
//      return *this;
//   }
