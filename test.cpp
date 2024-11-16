#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testAcceleration.h"
#include "testDirection.h"
#include "TestSimulationObject.h"
#include "TestSatellite.h"
#include "TestSputnik.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
	TestPosition().run();
	TestVelocity().run();
	TestAcceleration().run();
	TestDirection().run();
   TestSimulationObject().run();
   TestSatellite().run();
   TestSputnik().run();
   

}
