

#include "LuxuryVehicle.h"

LuxuryVehicle::LuxuryVehicle(unsigned int vehicleId,
                             char carManufacturer, char color)
        : Vehicle(vehicleId, carManufacturer, color) {
    tariff = 2;
}
