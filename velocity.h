#include <cmath>
#include <iostream>
#pragma once

class TestVelocity;
class Acceleration;

class Velocity
{
private:
    float dx;  // Horizontal velocity component (meters/second)
    float dy;  // Vertical velocity component (meters/second)

public:
    // Friends of this class can access private members
    friend TestVelocity;   // Allows TestVelocity to access private members
    friend Acceleration;   // Allows Acceleration to access private members

    /**
     * @brief Default constructor: initializes velocity to (0, 0).
     */
    Velocity() : dx(0.0f), dy(0.0f) {}

    /**
     * @brief Copy constructor: creates a new Velocity object by copying another.
     * @param other The Velocity object to copy.
     */
    Velocity(const Velocity& other) : dx(other.dx), dy(other.dy) {}

    /**
     * @brief Assigns the values of another Velocity object to this one.
     * @param velocity The Velocity object to copy from.
     */
    void assign(const Velocity& velocity) {
        dx = velocity.dx;
        dy = velocity.dy;
    }

    /**
     * @brief Retrieves the horizontal velocity component.
     * @return The horizontal velocity component (dx).
     */
    float getDx() const { return dx; }

    /**
     * @brief Retrieves the vertical velocity component.
     * @return The vertical velocity component (dy).
     */
    float getDy() const { return dy; }

    /**
     * @brief Calculates the magnitude of the velocity vector.
     * @return The speed (magnitude of velocity).
     */
    float getSpeed() const {
        return sqrt(dx * dx + dy * dy); // Speed is the Euclidean norm of (dx, dy)
    }

    /**
     * @brief Calculates the direction of the velocity vector in radians.
     * @return The direction in radians, measured counterclockwise from the positive x-axis.
     */
    float getDirection() const {
        return atan2(dy, dx); // atan2 accounts for the signs of dx and dy
    }

    /**
     * @brief Sets the horizontal velocity component.
     * @param dx The new horizontal velocity component.
     */
    void setDx(float dx) { this->dx = dx; }

    /**
     * @brief Sets the vertical velocity component.
     * @param dy The new vertical velocity component.
     */
    void setDy(float dy) { this->dy = dy; }

    /**
     * @brief Sets the speed (magnitude of velocity) while preserving the direction.
     * @param speed The new speed.
     */
    void setSpeed(float speed) {
        if (getSpeed() == 0.0f)  // Avoid division by zero if current speed is zero
            return;

        float ratio = speed / getSpeed(); // Scaling factor for velocity components
        dx *= ratio;
        dy *= ratio;
    }

    /**
     * @brief Sets the direction of the velocity while preserving the speed.
     * @param direction The new direction in radians.
     */
    void setDirection(float direction) {
        float speed = getSpeed();      // Preserve the magnitude of velocity
        dx = speed * cos(direction);  // Update dx based on the new direction
        dy = speed * sin(direction);  // Update dy based on the new direction
    }

    /**
     * @brief Increments the horizontal velocity component by a given value.
     * @param dx The increment for the horizontal velocity component.
     */
    void addDx(float dx) { this->dx += dx; }

    /**
     * @brief Increments the vertical velocity component by a given value.
     * @param dy The increment for the vertical velocity component.
     */
    void addDy(float dy) { this->dy += dy; }

    /**
     * @brief Adds another velocity vector to this one.
     * @param velocity The velocity vector to add.
     */
    void add(const Velocity& velocity) {
        dx += velocity.dx;
        dy += velocity.dy;
    }
};
