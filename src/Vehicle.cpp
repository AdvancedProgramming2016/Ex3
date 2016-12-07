
#include "Vehicle.h"

Vehicle::Vehicle(unsigned int vehicleId, Manufacturer carManufacturer,
                 Color color) : vehicleId(vehicleId),
                                carManufacturer(carManufacturer),
                                color(color), kmPassed(0) {}


unsigned int Vehicle::getVehicleId() const {
    return vehicleId;
}

unsigned int Vehicle::getKmPassed() const {
    return kmPassed;
}

Manufacturer Vehicle::getCarManufacturer() const {
    return carManufacturer;
}

Color Vehicle::getColor() const {
    return color;
}

unsigned int Vehicle::getMaxCapacity() const {
    return maxCapacity;
}

double Vehicle::getTariff() const {
    return tariff;
}

unsigned int Vehicle::getSpeedLimit() const {
//    return speedLimit;
}

void Vehicle::increaseKmPassed() {

}

