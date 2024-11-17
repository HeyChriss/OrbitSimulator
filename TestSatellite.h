/***********************************************************************
 * Header File:
 *    TEST SATELLITE
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The test satellite class
 ************************************************************************/


#pragma once

#include "unitTest.h"
#include "Satellite.h"

class TestSatellite : public UnitTest
{
public:
    void run()
    {
        constructor_SPUTNIK();
        constructor_HUBBLE();
        constructor_DRAGONCREW();
        constructor_STARLINK();
        constructor_GPS();

        report("Satellite");
    }

private:
    void constructor_SPUTNIK();
    void constructor_HUBBLE();
    void constructor_DRAGONCREW();
    void constructor_STARLINK();
    void constructor_GPS();
};

