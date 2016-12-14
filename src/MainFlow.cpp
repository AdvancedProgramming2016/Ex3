
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
    this->taxiCenter->getTrips().push(trip);
}

TaxiCenter *MainFlow::getTaxiCenter() const {
    return taxiCenter;
}

Grid *MainFlow::getMap() const {
    return map;
}

void MainFlow::startDriving() {

    unsigned int           i;
    Vehicle                *currVehicle;
    std::vector<Driver *>  driverVec  = this->taxiCenter->getDrivers();
    std::vector<Vehicle *> vehicleVec = this->taxiCenter->getVehicles();
    std::queue<Trip *>     tripQueue  = this->taxiCenter->getTrips();

    for (i = 0; i < driverVec.size(); i++) {

        // If trip queue is empty and there are not more trips
        if (tripQueue.empty()) {
            break;

        } else if (driverVec.at(i)->getVehicleId() == 0) {

            int j;

            // Find the relevant vehicle for a certain driver
            for (j = 0; j < vehicleVec.size(); j++) {
                if (vehicleVec.at(j)->getVehicleId() ==
                    driverVec.at(i)->getVehicleId()) {
                    currVehicle = vehicleVec.at(j);
                }
            }

            // TODO: Check what vehicle needs to be put in the constructor
            Taxi *newTaxi = new Taxi(driverVec.at(i), currVehicle,
                                     *(new Point(0, 0)), tripQueue.front());

            // Set the new taxi's current location to end point
            newTaxi->setCurrentPosition(tripQueue.front()->getEndPoint());
            tripQueue.pop();

            // Push the new taxi to the taxi vector
            this->taxiCenter->getTaxis().push_back(newTaxi);

        }
    }

}

void MainFlow::exitSystem() {


    //TODO: there is a confusion between int and unsigned
    delete taxiCenter;
    delete map;

    //exit the system
    exit(0);
}




