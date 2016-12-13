
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

void MainFlow::createDriver(Driver *driver) {

    taxiCenter->addDriver(driver);
    taxiCenter->createTaxi(driver);
}

void MainFlow::createVehicle(Vehicle *vehicle) {

    taxiCenter->addVehicle(vehicle);
}

void MainFlow::createTrip(Trip *trip) {

    // Push new trip to trip queue
}

TaxiCenter *MainFlow::getTaxiCenter() const {
    return taxiCenter;
}

Grid *MainFlow::getMap() const {
    return map;
}

void MainFlow::startDriving() {

    unsigned int i;
    std::vector<Driver *> driverVec = this->taxiCenter->getDrivers();

    for (i = 0; i < driverVec.size(); i++) {
    }

}

void MainFlow::exitSystem() {

    //delete all the taxis.
    for (int taxiIndex = 0;
         taxiIndex < taxiCenter->getTaxis().size(); ++taxiIndex) {
        delete taxiCenter->getTaxis().at(taxiIndex);
    }

    //delete all the drivers.
    for (int driverIndex = 0;
         driverIndex < taxiCenter->getDrivers().size(); ++driverIndex) {
        delete taxiCenter->getDrivers().at(driverIndex);
    }

    //delete all the vehicles.
    for (int vehicleIndex = 0;
         vehicleIndex < taxiCenter->getVehicles().size(); ++vehicleIndex) {
        delete taxiCenter->getVehicles().at(vehicleIndex);
    }

    //exit the system
    exit(0);
}




