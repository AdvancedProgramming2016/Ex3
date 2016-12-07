
#ifndef EX2_LUXURYVEHICLE_H
#define EX2_LUXURYVEHICLE_H


#include "Vehicle.h"

/**
 * The class inherites from the Vehicle class, and represents a luxury vehicle.
 * It drives twice the speed of a standard vehicle, and is more expensive.
 */
class LuxuryVehicle : public Vehicle {

public:
    LuxuryVehicle(unsigned int vehicleId,
                  Manufacturer carManufacturer, Color color);
};


#endif //EX2_LUXURYVEHICLE_H
