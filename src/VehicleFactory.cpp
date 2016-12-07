
#include "VehicleFactory.h"

Vehicle *VehicleFactory::makeVehicle(int id, int vehicleType, Manufacturer manufacturer, Color color) {

    Vehicle *vehicle = 0;

    if (vehicleType == 1) {

        return new StandardVehicle(id, manufacturer, color);
    }

    else if(vehicleType == 2){

        return new LuxuryVehicle(id, manufacturer, color);
    }

    return 0;
}
