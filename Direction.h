#pragma once
#include <cmath>
#define M_PI 3.14159265358979323846

class Direction {
private:
    float radians; // The angle stored in radians

    /**
     * @brief Normalizes an angle to the range [0, 2π) radians.
     * @param angle The input angle in radians.
     * @return The normalized angle in radians.
     */
    float normalize(float angle) const {
        const float TWO_PI = 2.0f * M_PI; // Define 2π for normalization
        while (angle < 0) // Ensure the angle is non-negative
            angle += TWO_PI;
        while (angle >= TWO_PI) // Ensure the angle is less than 2π
            angle -= TWO_PI;
        return angle;
    }

public:
    /**
     * @brief Default constructor: initializes the direction to 0 radians (facing right).
     */
    Direction() : radians(0.0f) {}

    /**
     * @brief Copy constructor: creates a new Direction object by copying another.
     * @param other The Direction object to copy.
     */
    Direction(const Direction& other) : radians(other.radians) {}

    /**
     * @brief Sets the direction using an angle in radians.
     * @param radians The angle in radians.
     */
    void setRadians(float radians) {
        this->radians = normalize(radians); // Normalize the input angle
    }

    /**
     * @brief Sets the direction using an angle in degrees.
     * @param degrees The angle in degrees.
     */
    void setDegrees(float degrees) {
        this->radians = normalize(degrees * M_PI / 180.0f); // Convert degrees to radians and normalize
    }

    /**
     * @brief Sets the direction based on a vector's components.
     * @param dx The x-component of the vector.
     * @param dy The y-component of the vector.
     */
    void setDxDy(float dx, float dy) {
        radians = normalize(atan2(dy, dx)); // Calculate the angle from vector components
    }

    /**
     * @brief Sets the direction to "up" (-π/2 radians).
     */
    void setUp() {
        radians = normalize(-M_PI / 2.0f);
    }

    /**
     * @brief Sets the direction to "down" (π/2 radians).
     */
    void setDown() {
        radians = normalize(M_PI / 2.0f);
    }

    /**
     * @brief Sets the direction to "left" (π radians).
     */
    void setLeft() {
        radians = normalize(M_PI);
    }

    /**
     * @brief Sets the direction to "right" (0 radians).
     */
    void setRight() {
        radians = 0.0f; // Right corresponds to 0 radians
    }

    /**
     * @brief Retrieves the direction as an angle in radians.
     * @return The direction in radians.
     */
    float getRadians() const {
        return radians;
    }

    /**
     * @brief Retrieves the direction as an angle in degrees.
     * @return The direction in degrees.
     */
    float getDegrees() const {
        return radians * 180.0f / M_PI; // Convert radians to degrees
    }

    /**
     * @brief Retrieves the x-component of a unit vector in the current direction.
     * @return The x-component (cosine of the angle).
     */
    float getDx() const {
        return cos(radians);
    }

    /**
     * @brief Retrieves the y-component of a unit vector in the current direction.
     * @return The y-component (sine of the angle).
     */
    float getDy() const {
        return sin(radians);
    }

    /**
     * @brief Rotates the direction by a specified angle in radians.
     * @param amount The angle to rotate by (in radians).
     */
    void rotate(float amount) {
        radians = normalize(radians + amount); // Add the rotation and normalize the result
    }
};

