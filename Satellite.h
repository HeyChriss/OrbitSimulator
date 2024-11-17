/***********************************************************************
 * Header File:
 *    SATELLITE
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The satellite inheriting from SimulationObject
 ************************************************************************/


#pragma once

#include "SimulationObject.h"
#include "SatelliteType.h"
#include "SatelliteConfiguration.h"
#include <list>
#include <vector>

class SatellitePart;
class TestSatellite;
class TestSputnik;

/***************************************************
 * SATELLITE
 * The base class for various kinds of satellite
 ***************************************************/
class Satellite : public SimulationObject
{
public:

	friend TestSatellite;
	friend TestSputnik;

	Satellite(SatelliteType type) : SimulationObject() { initializeConfig(type); }
	void initializeConfig(SatelliteType type);
	virtual list<SimulationObject> breakApart();

protected:

	// member variable
	SatelliteType type;
	SatelliteConfiguration config;
	// list<SatellitePart> parts;

	// method
	virtual const SatelliteConfiguration getConfiguration();
private:
	vector<SatelliteConfiguration> gpsConfig;
};

