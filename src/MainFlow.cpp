
#include "MainFlow.h"

MainFlow::MainFlow() {

}

MainFlow::~MainFlow() {

    delete taxiCenter;
    delete map;
}

void MainFlow::createMap(unsigned height, unsigned width) {

}

void MainFlow::createTaxiCenter(Point *location) {

    taxiCenter = new TaxiCenter(location);
}

void MainFlow::createDriver(unsigned int driverId, unsigned int age,
                            MaritalStatus maritalStatus,
                            unsigned int yearsOfExperience,
                            unsigned int vehicleId) {

    Driver *driver = new Driver(driverId, age, maritalStatus, yearsOfExperience,
                                vehicleId);
    taxiCenter->addDriver(driver);
}

void MainFlow::createVehicle(int id, int vehicleType,
                             Manufacturer manufacturer, Color color) {

    Vehicle *vehicle = vehicleFactory.makeVehicle(id, vehicleType,
                                                  manufacturer, color);
    taxiCenter->addVehicle(vehicle);
}

void MainFlow::createTrip(unsigned int rideId, unsigned int startX,
                          unsigned int startY, unsigned int endX,
                          unsigned int endY, unsigned int numOfPassengers,
                          unsigned int tariff) {
    Point start(startX, startY);
    Point end(endX, endY);
    Trip *trip = new Trip(rideId, start, end, numOfPassengers, tariff);
}

TaxiCenter *MainFlow::getTaxiCenter() const {
    return taxiCenter;
}

Grid *MainFlow::getMap() const {
    return map;
}




