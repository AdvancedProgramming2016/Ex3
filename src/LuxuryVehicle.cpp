

#include "LuxuryVehicle.h"

LuxuryVehicle::LuxuryVehicle(unsigned int vehicleId,
                             Manufacturer carManufacturer, Color color)
        : Vehicle(vehicleId, carManufacturer, color) {
    //speedLimit *= 2;
    //tariff = trip coefficient TODO add this attribute
}
