#pragma once
#include "velocity.h"
#include "unitTest.h"
#include <cmath>
#define M_PI 3.14159265358979323846

class TestVelocity : public UnitTest
{
public:
    void run()
    {
        // Basic tests
        constructor_default();
        constructor_nonDefault();
        getDX();
        getDY();
        getSpeed_up();
        getSpeed_down();
        getSpeed_left();
        getSpeed_right();
        getSpeed_diagonal();
        setDX();
        setDY();

        // Direction tests
        getDirection();
        setDirection();

        // Add operations
        addDX_zero();
        addDX_value();
        addDY_zero();
        addDY_value();
        add_velocities();

        report("Velocity");
    }

private:
    void constructor_default()
    {
        // exercise
        Velocity v;
        // verify
        assertEquals(v.getDx(), 0.0f);
        assertEquals(v.getDy(), 0.0f);
    }

    void constructor_nonDefault()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        // verify
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 4.5f);
    }

    void getDX()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        float dx = 99.9f;
        // exercise
        dx = v.getDx();
        // verify
        assertEquals(dx, 2.3f);
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 4.5f);
    }

    void getDY()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        float dy = 99.9f;
        // exercise
        dy = v.getDy();
        // verify
        assertEquals(dy, 4.5f);
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 4.5f);
    }

    void getSpeed_up()
    {
        // setup
        Velocity v;
        v.setDx(0.0f);
        v.setDy(4.5f);
        float s = 99.9f;
        // exercise
        s = v.getSpeed();
        // verify
        assertEquals(s, 4.5f);
        assertEquals(v.getDx(), 0.0f);
        assertEquals(v.getDy(), 4.5f);
    }

    void getSpeed_down()
    {
        // setup
        Velocity v;
        v.setDx(0.0f);
        v.setDy(-4.5f);
        float s = 99.9f;
        // exercise
        s = v.getSpeed();
        // verify
        assertEquals(s, 4.5f);
        assertEquals(v.getDx(), 0.0f);
        assertEquals(v.getDy(), -4.5f);
    }

    void getSpeed_left()
    {
        // setup
        Velocity v;
        v.setDx(-2.3f);
        v.setDy(0.0f);
        float s = 99.9f;
        // exercise
        s = v.getSpeed();
        // verify
        assertEquals(s, 2.3f);
        assertEquals(v.getDx(), -2.3f);
        assertEquals(v.getDy(), 0.0f);
    }

    void getSpeed_right()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(0.0f);
        float s = 99.9f;
        // exercise
        s = v.getSpeed();
        // verify
        assertEquals(s, 2.3f);
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 0.0f);
    }

    void getSpeed_diagonal()
    {
        // setup
        Velocity v;
        v.setDx(3.0f);
        v.setDy(-4.0f);
        float s = 99.9f;
        // exercise
        s = v.getSpeed();
        // verify
        assertEquals(s, 5.0f);
        assertEquals(v.getDx(), 3.0f);
        assertEquals(v.getDy(), -4.0f);
    }

    void setDX()
    {
        // setup
        Velocity v;
        v.setDx(99.9f);
        v.setDy(88.8f);
        float dx = -1.1f;
        // exercise
        v.setDx(dx);
        // verify
        assertEquals(v.getDx(), -1.1f);
        assertEquals(v.getDy(), 88.8f);
        assertEquals(dx, -1.1f);
    }

    void setDY()
    {
        // setup
        Velocity v;
        v.setDx(99.9f);
        v.setDy(88.8f);
        float dy = -1.1f;
        // exercise
        v.setDy(dy);
        // verify
        assertEquals(v.getDx(), 99.9f);
        assertEquals(v.getDy(), -1.1f);
        assertEquals(dy, -1.1f);
    }

    void getDirection()
    {
        // setup
        Velocity v;
        v.setDx(1.0f);
        v.setDy(1.0f);
        // exercise
        float direction = v.getDirection();
        // verify
        assertEquals(direction, M_PI / 4.0f);
    }

    void setDirection()
    {
        // setup
        Velocity v;
        v.setDx(1.0f);
        v.setDy(0.0f);
        float newDirection = M_PI / 2.0f;
        // exercise
        v.setDirection(newDirection);
        // verify
        assertEquals(v.getDirection(), M_PI / 2.0f);
        assertEquals(v.getDx(), 0.0f);
        assertEquals(v.getDy(), 1.0f);
    }

    void addDX_zero()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        float dx = 0.0f;
        // exercise
        v.addDx(dx);
        // verify
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 4.5f);
        assertEquals(dx, 0.0f);
    }

    void addDX_value()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        float dx = 4.1f;
        // exercise
        v.addDx(dx);
        // verify
        assertEquals(v.getDx(), 6.4f);
        assertEquals(v.getDy(), 4.5f);
        assertEquals(dx, 4.1f);
    }

    void addDY_zero()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        float dy = 0.0f;
        // exercise
        v.addDy(dy);
        // verify
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 4.5f);
        assertEquals(dy, 0.0f);
    }

    void addDY_value()
    {
        // setup
        Velocity v;
        v.setDx(2.3f);
        v.setDy(4.5f);
        float dy = 4.1f;
        // exercise
        v.addDy(dy);
        // verify
        assertEquals(v.getDx(), 2.3f);
        assertEquals(v.getDy(), 8.6f);
        assertEquals(dy, 4.1f);
    }

    void add_velocities()
    {
        // setup
        Velocity v1;
        v1.setDx(2.3f);
        v1.setDy(4.5f);
        Velocity v2;
        v2.setDx(1.0f);
        v2.setDy(2.0f);
        // exercise
        v1.add(v2);
        // verify
        assertEquals(v1.getDx(), 3.3f);
        assertEquals(v1.getDy(), 6.5f);
        assertEquals(v2.getDx(), 1.0f);
        assertEquals(v2.getDy(), 2.0f);
    }
};