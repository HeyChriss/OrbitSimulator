#pragma once
#include "Position.h"
#include "unitTest.h"

class TestPosition : public UnitTest
{
public:
    void run()
    {
        Position().setZoom(1000.0f /* 1km equals 1 pixel */);
        defaultConstructor();
        nonDefaultConstructor();
        copyConstructor();
        assignment();
        setPixels();
        setMeters();
        addPixels();
        addMeters();

        report("Position");
    }

private:
    void defaultConstructor()
    {
        // setup
        // exercise
        Position pos;
        // verify
        assertEquals(pos.getMetersX(), 0.0f);
        assertEquals(pos.getMetersY(), 0.0f);
    }

    void nonDefaultConstructor()
    {
        // setup
        // exercise
        Position pos;
        pos.setMetersX(3000.0f);
        pos.setMetersY(9000.0f);
        // verify
        assertEquals(pos.getMetersX(), 3000.0f);
        assertEquals(pos.getMetersY(), 9000.0f);
    }

    void copyConstructor()
    {
        // setup
        Position pos1;
        pos1.setMetersX(4000.0f);
        pos1.setMetersY(2000.0f);
        // exercise
        Position pos2(pos1);
        // verify
        assertEquals(pos1.getMetersX(), 4000.0f);
        assertEquals(pos1.getMetersY(), 2000.0f);
        assertEquals(pos2.getMetersX(), 4000.0f);
        assertEquals(pos2.getMetersY(), 2000.0f);
    }

    void assignment()
    {
        // setup
        Position pos1;
        pos1.setMetersX(4000.0f);
        pos1.setMetersY(2000.0f);
        // exercise
        Position pos2;
        pos2.assign(pos1);
        // verify
        assertEquals(pos1.getMetersX(), 4000.0f);
        assertEquals(pos1.getMetersY(), 2000.0f);
        assertEquals(pos2.getMetersX(), 4000.0f);
        assertEquals(pos2.getMetersY(), 2000.0f);
    }

    void setMeters()
    {
        // setup
        Position pos;
        pos.setMetersX(0.0f);
        pos.setMetersY(0.0f);
        // exercise
        pos.setMetersX(5000.0f);
        pos.setMetersY(3000.0f);
        // verify
        assertEquals(pos.getMetersX(), 5000.0f);
        assertEquals(pos.getMetersY(), 3000.0f);
    }

    void setPixels()
    {
        // setup
        Position pos;
        pos.setZoom(1000.0f); // 1km per pixel
        pos.setMetersX(0.0f);
        pos.setMetersY(0.0f);
        // exercise
        pos.setPixelsX(6.0f);
        pos.setPixelsY(12.0f);
        // verify
        assertEquals(pos.getMetersX(), 6000.0f);
        assertEquals(pos.getMetersY(), 12000.0f);
    }

    void addMeters()
    {
        // setup
        Position pos;
        pos.setMetersX(800.0f);
        pos.setMetersY(1600.0f);
        // exercise
        pos.addMetersX(-400.0f);
        pos.addMetersY(800.0f);
        // verify
        assertEquals(pos.getMetersX(), 400.0f);
        assertEquals(pos.getMetersY(), 2400.0f);
    }

    void addPixels()
    {
        // setup
        Position pos;
        pos.setZoom(1000.0f); // 1km per pixel
        pos.setMetersX(2000.0f);
        pos.setMetersY(4000.0f);
        // exercise
        pos.addPixelsX(2.0f);
        pos.addPixelsY(3.0f);
        // verify
        assertEquals(pos.getMetersX(), 4000.0f);
        assertEquals(pos.getMetersY(), 7000.0f);
    }
};
