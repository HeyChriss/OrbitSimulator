#include <cmath>
#include <iostream>

class Velocity
{
private:
   float dx;
   float dy;

public:
   // Constructor
   Velocity() : dx(0.0f), dy(0.0f) {}

   // Copy constructor
   Velocity(const Velocity& other) : dx(other.dx), dy(other.dy) {}

   // Assignment operator
   void assign(const Velocity& velocity) {
       dx = velocity.dx;
       dy = velocity.dy;
   }

   // Getters
   float getDx() const { return dx; }
   float getDy() const { return dy; }
   float getSpeed() const {
       return sqrt(dx * dx + dy * dy);
   }

    // Get direction in radians
   float getDirection() const {
       return atan2(dy, dx);
   }

    // Setters
   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }
   void setSpeed(float speed) {
       if (getSpeed() == 0.0f)
           return;

       float ratio = speed / getSpeed();
       dx *= ratio;
       dy *= ratio;
   }

   void setDirection(float direction) {
       float speed = getSpeed();
       dx = speed * cos(direction);
       dy = speed * sin(direction);
   }

   // Adders
   void addDx(float dx) { this->dx += dx; }
   void addDy(float dy) { this->dy += dy; }

   // Add another velocity to this one
   void add(const Velocity& velocity) {
       dx += velocity.dx;
       dy += velocity.dy;
   }
};
