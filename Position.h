#pragma once

class TestPosition;
class Acceleration;
class Velocity;
class TestSimulationObject;      // For unit test


class Position {
private:
    float x;                 // Horizontal position in meters
    float y;                 // Vertical position in meters
    float metersFromPixels;  // Conversion factor from pixels to meters

public:
   friend TestPosition; // Allows the TestPosition class to access private members
   friend TestSimulationObject;
   
    // Default constructor: initializes position to (0, 0)
    // and sets a default conversion factor.
    Position() : x(0.0f), y(0.0f), metersFromPixels(1.0f) {}

    // Copy constructor: copies data from another Position object.
    Position(const Position& other)
        : x(other.x), y(other.y), metersFromPixels(other.metersFromPixels) {}

    /**
     * @brief Assigns the values of another Position object to this one.
     * @param pos The Position object to copy from.
     */
    void assign(const Position& pos) {
        x = pos.x;
        y = pos.y;
        metersFromPixels = pos.metersFromPixels;
    }

    // Getters for position in meters
    float getMetersX() const { return x; }
    float getMetersY() const { return y; }

    // Getters for position in pixels
    float getPixelsX() const { return x / metersFromPixels; }
    float getPixelsY() const { return y / metersFromPixels; }

    // Setters for position in meters
    void setMetersX(float xMeters) { x = xMeters; }
    void setMetersY(float yMeters) { y = yMeters; }

    // Setters for position in pixels (converts to meters internally)
    void setPixelsX(float xPixels) { x = xPixels * metersFromPixels; }
    void setPixelsY(float yPixels) { y = yPixels * metersFromPixels; }

    // Methods to adjust position incrementally in meters
    void addMetersX(float dxMeters) { x += dxMeters; }
    void addMetersY(float dyMeters) { y += dyMeters; }

    // Methods to adjust position incrementally in pixels 
    // (converts to meters internally)
    void addPixelsX(float dxPixels) { x += dxPixels * metersFromPixels; }
    void addPixelsY(float dyPixels) { y += dyPixels * metersFromPixels; }

    /**
     * @brief Sets the zoom level by defining the conversion factor from pixels to meters.
     * @param metersFromPix The new conversion factor.
     */
    void setZoom(float metersFromPix) { metersFromPixels = metersFromPix; }

    /**
     * @brief Retrieves the current zoom level (conversion factor).
     * @return The conversion factor from pixels to meters.
     */
    float getZoom() const { return metersFromPixels; }
};
