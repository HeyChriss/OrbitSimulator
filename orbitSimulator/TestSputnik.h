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
      update_1frame();
      update_2frame();
//      test_draw();
//      test_breakApart();
      
      report("Sputnik");
   }
   
private:
   void constructor_default();
   void update_1frame();
   void update_2frame();
//   void test_draw();
//   void test_breakApart();
};
