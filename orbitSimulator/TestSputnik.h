/***********************************************************************
 * Header File:
 *    TEST SPUTNIK
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The test sputnik class
 ************************************************************************/


#pragma once
#include "Sputnik.h"
#include "unitTest.h"

class TestSputnik : UnitTest
{
public:
   void run()
   {
      constructor_default();
      test_update();
//      test_draw();
//      test_breakApart();
      
      report("Sputnik");
   }
   
private:
   void constructor_default();
   void test_update();
//   void test_draw();
//   void test_breakApart();
};
