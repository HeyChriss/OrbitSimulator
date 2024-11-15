#pragma once
#pragma once
#include "direction.h"
#include "unitTest.h"
#include <cmath>
#define M_PI 3.14159265358979323846

class TestDirection : public UnitTest
{
public:
    void run()
    {
        // Basic constructor tests
        constructor_default();
        constructor_copy();

        // Basic getter/setter tests
        setRadians();
        setDegrees();
        setDxDy();
        getRadians();
        getDegrees();
        getDxDy();

        // Cardinal direction tests
        setUp();
        setDown();
        setLeft();
        setRight();

        // Rotation tests
        rotate_positive();
        rotate_negative();
        rotate_multiple_revolutions();

        // Normalization tests
        normalize_negative();
        normalize_large();

        report("Direction");
    }

private:
    void constructor_default()
    {
        // exercise
        Direction d;
        // verify
        assertEquals(d.getRadians(), 0.0f);
        assertEquals(d.getDx(), 1.0f);
        assertEquals(d.getDy(), 0.0f);
    }

    void constructor_copy()
    {
        // setup
        Direction d1;
        d1.setRadians(M_PI / 4.0f);
        // exercise
        Direction d2(d1);
        // verify
        assertEquals(d2.getRadians(), M_PI / 4.0f);
    }

    void setRadians()
    {
        // setup
        Direction d;
        // exercise
        d.setRadians(M_PI / 2.0f);
        // verify
        assertEquals(d.getRadians(), M_PI / 2.0f);
    }

    void setDegrees()
    {
        // setup
        Direction d;
        // exercise
        d.setDegrees(90.0f);
        // verify
        assertEquals(d.getRadians(), M_PI / 2.0f);
    }

    void setDxDy()
    {
        // setup
        Direction d;
        // exercise
        d.setDxDy(1.0f, 1.0f);
        // verify
        assertEquals(d.getRadians(), M_PI / 4.0f);
    }

    void getRadians()
    {
        // setup
        Direction d;
        d.setRadians(M_PI / 3.0f);
        // exercise
        float radians = d.getRadians();
        // verify
        assertEquals(radians, M_PI / 3.0f);
    }

    void getDegrees()
    {
        // setup
        Direction d;
        d.setRadians(M_PI / 2.0f);
        // exercise
        float degrees = d.getDegrees();
        // verify
        assertEquals(degrees, 90.0f);
    }

    void getDxDy()
    {
        // setup
        Direction d;
        d.setRadians(0.0f);
        // exercise & verify
        assertEquals(d.getDx(), 1.0f);
        assertEquals(d.getDy(), 0.0f);

        // Now test at 45 degrees
        d.setRadians(M_PI / 4.0f);
        assertEquals(d.getDx(), 0.707107f, 0.0001f);  // cos(45°)
        assertEquals(d.getDy(), 0.707107f, 0.0001f);  // sin(45°)
    }

    void setUp()
    {
        // setup
        Direction d;
        // exercise
        d.setUp();
        // verify
        assertEquals(d.getRadians(), 3.0f * M_PI / 2.0f);  // -π/2 normalized to 3π/2
        assertEquals(d.getDy(), -1.0f);
    }

    void setDown()
    {
        // setup
        Direction d;
        // exercise
        d.setDown();
        // verify
        assertEquals(d.getRadians(), M_PI / 2.0f);
        assertEquals(d.getDy(), 1.0f);
    }

    void setLeft()
    {
        // setup
        Direction d;
        // exercise
        d.setLeft();
        // verify
        assertEquals(d.getRadians(), M_PI);
        assertEquals(d.getDx(), -1.0f);
    }

    void setRight()
    {
        // setup
        Direction d;
        // exercise
        d.setRight();
        // verify
        assertEquals(d.getRadians(), 0.0f);
        assertEquals(d.getDx(), 1.0f);
    }

    void rotate_positive()
    {
        // setup
        Direction d;
        // exercise
        d.rotate(M_PI / 2.0f);
        // verify
        assertEquals(d.getRadians(), M_PI / 2.0f);
    }

    void rotate_negative()
    {
        // setup
        Direction d;
        // exercise
        d.rotate(-M_PI / 2.0f);
        // verify
        assertEquals(d.getRadians(), 3.0f * M_PI / 2.0f);  // -π/2 normalized to 3π/2
    }

    void rotate_multiple_revolutions()
    {
        // setup
        Direction d;
        // exercise
        d.rotate(4.0f * M_PI + M_PI / 2.0f);  // Two full rotations plus 90 degrees
        // verify
        assertEquals(d.getRadians(), M_PI / 2.0f);
    }

    void normalize_negative()
    {
        // setup
        Direction d;
        // exercise
        d.setRadians(-M_PI / 2.0f);
        // verify
        assertEquals(d.getRadians(), 3.0f * M_PI / 2.0f);
    }

    void normalize_large()
    {
        // setup
        Direction d;
        // exercise
        d.setRadians(5.0f * M_PI / 2.0f);  // 450 degrees
        // verify
        assertEquals(d.getRadians(), M_PI / 2.0f);  // Should normalize to 90 degrees
    }
};

