#pragma once
#include <cmath>
#define M_PI 3.14159265358979323846

class Direction
{
private:
    float radians;    // Angle in radians

    /**
     * Normalizes an angle to be between 0 and 2π radians
     * @param angle The angle to normalize in radians
     * @return The normalized angle in radians
     */
    float normalize(float angle) const {
        const float TWO_PI = 2.0f * M_PI;
        while (angle < 0)
            angle += TWO_PI;
        while (angle >= TWO_PI)
            angle -= TWO_PI;
        return angle;
    }

public:

    Direction() : radians(0.0f) {}


    Direction(const Direction& other) : radians(other.radians) {}


    void setRadians(float radians) {
        this->radians = normalize(radians);
    }


    void setDegrees(float degrees) {
        this->radians = normalize(degrees * M_PI / 180.0f);
    }


    void setDxDy(float dx, float dy) {
        radians = normalize(atan2(dy, dx));
    }


    void setUp() {
        radians = normalize(-M_PI / 2.0f);
    }


    void setDown() {
        radians = normalize(M_PI / 2.0f);
    }


    void setLeft() {
        radians = normalize(M_PI);
    }

    void setRight() {
        radians = 0.0f;
    }


    float getRadians() const {
        return radians;
    }


    float getDegrees() const {
        return radians * 180.0f / M_PI;
    }


    float getDx() const {
        return cos(radians);
    }


    float getDy() const {
        return sin(radians);
    }


    void rotate(float amount) {
        radians = normalize(radians + amount);
    }
};

