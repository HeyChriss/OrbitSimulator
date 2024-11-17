/***********************************************************************
 * Source File:
 *    SIMULATION OBJECT
 * Author:
 *    Chris Mijangos and Seth Chan
 * Summary:
 *    The base class for all kinds of satellite
 ************************************************************************/


#include "SimulationObject.h"

 /***************************************************
  * COLLIDES WITH: return true if the satellite collides with another satellite
  * Input:
  * Output: bool
  ***************************************************/
bool SimulationObject::collidesWith(SimulationObject obj)
{
    if (sqrt((this->pos.getMetersX() - obj.pos.getMetersX()) * (this->pos.getMetersX() - obj.pos.getMetersX()) +
        (this->pos.getMetersY() - obj.pos.getMetersY()) * (this->pos.getMetersY() - obj.pos.getMetersY())) >=
        this->radius + obj.getRadius()
        )
        return true;
    return false;
}
