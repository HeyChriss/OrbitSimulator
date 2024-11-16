#pragma once
#include <cmath>

// Forward declarations
class TestAcceleration;
class TestSputnik;
class Velocity;  // Forward declare Velocity here

class Acceleration {
private:
    float ddx;
    float ddy;

public:
    friend TestAcceleration;
    friend TestSputnik;

    // Constructors
    Acceleration() : ddx(0.0f), ddy(0.0f) {}

    // Copy constructor
    Acceleration(const Acceleration& other) : ddx(other.ddx), ddy(other.ddy) {}

    void assign(const Acceleration& acceleration);
    float getDDx() const;
    float getDDy() const;
    float getMagnitude() const;
    float getDirection() const;
    void setDDx(float ddx);
    void setDDy(float ddy);
    void setMagnitude(float magnitude);
    void setDirection(float direction);
    void addDDx(float ddx);
    void addDDy(float ddy);
    void add(const Acceleration& acceleration);
    Velocity getVelocity(float time) const;
    Velocity getVelocity(const Velocity& initial, float time) const;
    void updateVelocity(Velocity& velocity, float time) const;
};
