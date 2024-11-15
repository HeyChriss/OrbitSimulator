class Position
{
private:
    float x;              // x-coordinate in pixels
    float y;              // y-coordinate in pixels
    float metersFromPixels; // Conversion ratio from pixels to meters

public:

    Position() : x(0.0f), y(0.0f), metersFromPixels(1.0f) {}


    Position(const Position& other)
        : x(other.x), y(other.y), metersFromPixels(other.metersFromPixels) {
    }


    void assign(const Position& pos) {
        x = pos.x;
        y = pos.y;
        metersFromPixels = pos.metersFromPixels;
    }

    float getMetersX() const { return x * metersFromPixels; }
    float getMetersY() const { return y * metersFromPixels; }
    float getPixelsX() const { return x; }
    float getPixelsY() const { return y; }


    void setMetersX(float xMeters) {
        x = xMeters / metersFromPixels;
    }


    void setMetersY(float yMeters) {
        y = yMeters / metersFromPixels;
    }


    void setPixelsX(float xPixels) {
        x = xPixels;
    }


    void setPixelsY(float yPixels) {
        y = yPixels;
    }


    void addMetersX(float dxMeters) {
        x += dxMeters / metersFromPixels;
    }


    void addMetersY(float dyMeters) {
        y += dyMeters / metersFromPixels;
    }


    void addPixelsX(float dxPixels) {
        x += dxPixels;
    }


    void addPixelsY(float dyPixels) {
        y += dyPixels;
    }


    void setZoom(float metersFromPix) {
        // Store current position in meters
        float xMeters = getMetersX();
        float yMeters = getMetersY();

        // Update conversion ratio
        metersFromPixels = metersFromPix;

        // Reset position using new ratio
        setMetersX(xMeters);
        setMetersY(yMeters);
    }


    float getZoom() const {
        return metersFromPixels;
    }
};
