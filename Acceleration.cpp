#include "acceleration.h"
#include "velocity.h"
#pragma once

/**
 * @brief Assigns the values of another Acceleration object to this one.
 * @param acceleration The Acceleration object to copy from.
 */
void Acceleration::assign(const Acceleration& acceleration) {
    ddx = acceleration.ddx;
    ddy = acceleration.ddy;
}

/**
 * @brief Retrieves the horizontal acceleration component (ddx).
 * @return The horizontal acceleration component.
 */
float Acceleration::getDDx() const {
    return ddx;
}

/**
 * @brief Retrieves the vertical acceleration component (ddy).
 * @return The vertical acceleration component.
 */
float Acceleration::getDDy() const {
    return ddy;
}

/**
 * @brief Calculates the magnitude of the acceleration vector.
 * @return The magnitude of acceleration (Euclidean norm of ddx and ddy).
 */
float Acceleration::getMagnitude() const {
    return sqrt(ddx * ddx + ddy * ddy); // Magnitude is the Euclidean norm
}

/**
 * @brief Calculates the direction of the acceleration vector in radians.
 * @return The direction of acceleration, measured counterclockwise from the positive x-axis.
 */
float Acceleration::getDirection() const {
    return atan2(ddy, ddx); // atan2 accounts for the signs of ddx and ddy
}

/**
 * @brief Sets the horizontal acceleration component (ddx).
 * @param ddx The new horizontal acceleration value.
 */
void Acceleration::setDDx(float ddx) {
    this->ddx = ddx;
}

/**
 * @brief Sets the vertical acceleration component (ddy).
 * @param ddy The new vertical acceleration value.
 */
void Acceleration::setDDy(float ddy) {
    this->ddy = ddy;
}

/**
 * @brief Sets the magnitude of the acceleration vector while preserving its direction.
 * @param magnitude The new magnitude of the acceleration vector.
 */
void Acceleration::setMagnitude(float magnitude) {
    if (getMagnitude() == 0.0f) // Avoid division by zero
        return;
    float ratio = magnitude / getMagnitude(); // Scaling factor for components
    ddx *= ratio;
    ddy *= ratio;
}

/**
 * @brief Sets the direction of the acceleration vector while preserving its magnitude.
 * @param direction The new direction in radians.
 */
void Acceleration::setDirection(float direction) {
    float magnitude = getMagnitude();      // Preserve the current magnitude
    ddx = magnitude * cos(direction);     // Update ddx based on the new direction
    ddy = magnitude * sin(direction);     // Update ddy based on the new direction
}

/**
 * @brief Adds a value to the horizontal acceleration component (ddx).
 * @param ddx The value to add.
 */
void Acceleration::addDDx(float ddx) {
    this->ddx += ddx;
}

/**
 * @brief Adds a value to the vertical acceleration component (ddy).
 * @param ddy The value to add.
 */
void Acceleration::addDDy(float ddy) {
    this->ddy += ddy;
}

/**
 * @brief Adds another Acceleration vector to this one.
 * @param acceleration The Acceleration vector to add.
 */
void Acceleration::add(const Acceleration& acceleration) {
    ddx += acceleration.ddx;
    ddy += acceleration.ddy;
}

/**
 * @brief Calculates the velocity after a given time assuming initial velocity is zero.
 * @param time The time duration for which acceleration is applied.
 * @return A Velocity object representing the resulting velocity.
 */
Velocity Acceleration::getVelocity(float time) const {
    Velocity v;
    v.setDx(ddx * time); // Velocity in x-direction = acceleration * time
    v.setDy(ddy * time); // Velocity in y-direction = acceleration * time
    return v;
}

/**
 * @brief Calculates the velocity after a given time with an initial velocity.
 * @param initial The initial velocity.
 * @param time The time duration for which acceleration is applied.
 * @return A Velocity object representing the resulting velocity.
 */
Velocity Acceleration::getVelocity(const Velocity& initial, float time) const {
    Velocity v;
    v.setDx(initial.getDx() + ddx * time); // Final velocity = initial + (acceleration * time)
    v.setDy(initial.getDy() + ddy * time);
    return v;
}

/**
 * @brief Updates an existing Velocity object by applying acceleration over a given time.
 * @param velocity The Velocity object to update.
 * @param time The time duration for which acceleration is applied.
 */
void Acceleration::updateVelocity(Velocity& velocity, float time) const {
    velocity.addDx(ddx * time); // Increment velocity in x-direction
    velocity.addDy(ddy * time); // Increment velocity in y-direction
}