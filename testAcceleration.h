#pragma once
#include "acceleration.h"
#include "unitTest.h"
#include "velocity.h"
#include <cmath>
#define M_PI 3.14159265358979323846

class TestAcceleration : public UnitTest
{
public:
    void run()
    {
        // Basic tests
        constructor_default();
        constructor_nonDefault();
        copyConstructor();
        assignment();
        getDDX();
        getDDY();

        // Magnitude and direction tests
        getMagnitude_zero();
        getMagnitude_positiveX();
        getMagnitude_positiveY();
        getMagnitude_diagonal();
        getDirection();

        // Setter tests
        setDDX();
        setDDY();
        setMagnitude();
        setDirection();

        // Add operations
        addDDX_zero();
        addDDX_value();
        addDDY_zero();
        addDDY_value();
        add_accelerations();

        // Velocity calculations
        getVelocity_fromRest();
        getVelocity_withInitial();
        updateVelocity();

        report("Acceleration");
    }

private:
    void constructor_default()
    {
        // exercise
        Acceleration a;
        // verify
        assertEquals(a.getDDx(), 0.0f);
        assertEquals(a.getDDy(), 0.0f);
    }

    void constructor_nonDefault()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        // verify
        assertEquals(a.getDDx(), 2.3f);
        assertEquals(a.getDDy(), 4.5f);
    }

    void copyConstructor()
    {
        // setup
        Acceleration a1;
        a1.setDDx(2.3f);
        a1.setDDy(4.5f);
        // exercise
        Acceleration a2(a1);
        // verify
        assertEquals(a2.getDDx(), 2.3f);
        assertEquals(a2.getDDy(), 4.5f);
    }

    void assignment()
    {
        // setup
        Acceleration a1;
        a1.setDDx(2.3f);
        a1.setDDy(4.5f);
        // exercise
        Acceleration a2;
        a2.assign(a1);
        // verify
        assertEquals(a2.getDDx(), 2.3f);
        assertEquals(a2.getDDy(), 4.5f);
    }

    void getDDX()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        float ddx = 99.9f;
        // exercise
        ddx = a.getDDx();
        // verify
        assertEquals(ddx, 2.3f);
        assertEquals(a.getDDx(), 2.3f);
        assertEquals(a.getDDy(), 4.5f);
    }

    void getDDY()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        float ddy = 99.9f;
        // exercise
        ddy = a.getDDy();
        // verify
        assertEquals(ddy, 4.5f);
        assertEquals(a.getDDx(), 2.3f);
        assertEquals(a.getDDy(), 4.5f);
    }

    void getMagnitude_zero()
    {
        // setup
        Acceleration a;
        a.setDDx(0.0f);
        a.setDDy(0.0f);
        // exercise
        float magnitude = a.getMagnitude();
        // verify
        assertEquals(magnitude, 0.0f);
    }

    void getMagnitude_positiveX()
    {
        // setup
        Acceleration a;
        a.setDDx(3.0f);
        a.setDDy(0.0f);
        // exercise
        float magnitude = a.getMagnitude();
        // verify
        assertEquals(magnitude, 3.0f);
    }

    void getMagnitude_positiveY()
    {
        // setup
        Acceleration a;
        a.setDDx(0.0f);
        a.setDDy(4.0f);
        // exercise
        float magnitude = a.getMagnitude();
        // verify
        assertEquals(magnitude, 4.0f);
    }

    void getMagnitude_diagonal()
    {
        // setup
        Acceleration a;
        a.setDDx(3.0f);
        a.setDDy(4.0f);
        // exercise
        float magnitude = a.getMagnitude();
        // verify
        assertEquals(magnitude, 5.0f);
    }

    void getDirection()
    {
        // setup
        Acceleration a;
        a.setDDx(1.0f);
        a.setDDy(1.0f);
        // exercise
        float direction = a.getDirection();
        // verify
        assertEquals(direction, M_PI / 4.0f);
    }

    void setDDX()
    {
        // setup
        Acceleration a;
        a.setDDx(99.9f);
        a.setDDy(88.8f);
        // exercise
        a.setDDx(-1.1f);
        // verify
        assertEquals(a.getDDx(), -1.1f);
        assertEquals(a.getDDy(), 88.8f);
    }

    void setDDY()
    {
        // setup
        Acceleration a;
        a.setDDx(99.9f);
        a.setDDy(88.8f);
        // exercise
        a.setDDy(-1.1f);
        // verify
        assertEquals(a.getDDx(), 99.9f);
        assertEquals(a.getDDy(), -1.1f);
    }

    void setMagnitude()
    {
        // setup
        Acceleration a;
        a.setDDx(3.0f);
        a.setDDy(4.0f);
        // exercise
        a.setMagnitude(10.0f);
        // verify
        assertEquals(a.getMagnitude(), 10.0f);
        assertEquals(a.getDDx(), 6.0f);
        assertEquals(a.getDDy(), 8.0f);
    }

    void setDirection()
    {
        // setup
        Acceleration a;
        a.setDDx(5.0f);
        a.setDDy(0.0f);
        float magnitude = a.getMagnitude();
        // exercise
        a.setDirection(M_PI / 2.0f);
        // verify
        assertEquals(a.getMagnitude(), magnitude);
        assertEquals(a.getDDx(), 0.0f);
        assertEquals(a.getDDy(), 5.0f);
    }

    void addDDX_zero()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        // exercise
        a.addDDx(0.0f);
        // verify
        assertEquals(a.getDDx(), 2.3f);
        assertEquals(a.getDDy(), 4.5f);
    }

    void addDDX_value()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        // exercise
        a.addDDx(4.1f);
        // verify
        assertEquals(a.getDDx(), 6.4f);
        assertEquals(a.getDDy(), 4.5f);
    }

    void addDDY_zero()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        // exercise
        a.addDDy(0.0f);
        // verify
        assertEquals(a.getDDx(), 2.3f);
        assertEquals(a.getDDy(), 4.5f);
    }

    void addDDY_value()
    {
        // setup
        Acceleration a;
        a.setDDx(2.3f);
        a.setDDy(4.5f);
        // exercise
        a.addDDy(4.1f);
        // verify
        assertEquals(a.getDDx(), 2.3f);
        assertEquals(a.getDDy(), 8.6f);
    }

    void add_accelerations()
    {
        // setup
        Acceleration a1;
        a1.setDDx(2.3f);
        a1.setDDy(4.5f);
        Acceleration a2;
        a2.setDDx(1.0f);
        a2.setDDy(2.0f);
        // exercise
        a1.add(a2);
        // verify
        assertEquals(a1.getDDx(), 3.3f);
        assertEquals(a1.getDDy(), 6.5f);
        assertEquals(a2.getDDx(), 1.0f);
        assertEquals(a2.getDDy(), 2.0f);
    }

    void getVelocity_fromRest()
    {
        // setup
        Acceleration a;
        a.setDDx(2.0f);
        a.setDDy(3.0f);
        float time = 2.0f;

        // exercise
        Velocity v = a.getVelocity(time);

        // verify
        assertEquals(v.getDx(), 4.0f);  // 2.0 * 2.0
        assertEquals(v.getDy(), 6.0f);  // 3.0 * 2.0
    }

    void getVelocity_withInitial()
    {
        // setup
        Acceleration a;
        a.setDDx(2.0f);
        a.setDDy(3.0f);
        Velocity initialV;
        initialV.setDx(1.0f);
        initialV.setDy(1.0f);
        float time = 2.0f;

        // exercise
        Velocity finalV = a.getVelocity(initialV, time);

        // verify
        assertEquals(finalV.getDx(), 5.0f);  // 1.0 + (2.0 * 2.0)
        assertEquals(finalV.getDy(), 7.0f);  // 1.0 + (3.0 * 2.0)
    }

    void updateVelocity()
    {
        // setup
        Acceleration a;
        a.setDDx(2.0f);
        a.setDDy(3.0f);
        Velocity v;
        v.setDx(1.0f);
        v.setDy(1.0f);
        float time = 2.0f;

        // exercise
        a.updateVelocity(v, time);

        // verify
        assertEquals(v.getDx(), 5.0f);  // 1.0 + (2.0 * 2.0)
        assertEquals(v.getDy(), 7.0f);  // 1.0 + (3.0 * 2.0)
    }
};