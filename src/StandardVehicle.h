
#ifndef EX2_STANDARDVEHICLE_H
#define EX2_STANDARDVEHICLE_H


#include "Vehicle.h"

/**
 * The class inherits from the Vehicle class, and represents a standard kind of vehicle.
 */
class StandardVehicle: public Vehicle {

public:

    /*
     * Constructor
     */
    StandardVehicle(unsigned int vehicleId, Manufacturer carManufacturer, Color color);

};


#endif //EX2_STANDARDVEHICLE_H
