
#ifndef EX3_VEHICLEFACTORY_H
#define EX3_VEHICLEFACTORY_H

#include "StandardVehicle.h"
#include "LuxuryVehicle.h"

/**
 * The class implements the factory design pattern which prodeuces vehicles,
 * depending on user input.
 */
class VehicleFactory {

public:
    Vehicle* makeVehicle(int id, int vehicleType,
                        Manufacturer manufacturer, Color color);
};


#endif //EX3_VEHICLEFACTORY_H
