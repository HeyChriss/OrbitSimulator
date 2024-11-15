
#include "Velocity.h"

class Acceleration
{
private:
    float ddx;    // Horizontal acceleration component (meters/second²)
    float ddy;    // Vertical acceleration component (meters/second²)

public:

    Acceleration() : ddx(0.0f), ddy(0.0f) {}


    Acceleration(const Acceleration& other) : ddx(other.ddx), ddy(other.ddy) {}


    void assign(const Acceleration& acceleration) {
        ddx = acceleration.ddx;
        ddy = acceleration.ddy;
    }


    float getDDx() const { return ddx; }


    float getDDy() const { return ddy; }


    Velocity getVelocity(float time) const {
        Velocity velocity;
        velocity.setDx(ddx * time);
        velocity.setDy(ddy * time);
        return velocity;
    }


    Velocity getVelocity(const Velocity& pVelocity, float time) const {
        Velocity velocityChange = getVelocity(time);
        Velocity finalVelocity = pVelocity;
        finalVelocity.add(velocityChange);
        return finalVelocity;
    }
};

