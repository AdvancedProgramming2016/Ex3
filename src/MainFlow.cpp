
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

    unsigned int i = 0;
    std::vector<Taxi *> taxiVec = this->taxiCenter->getTaxis();
    std::queue<Trip *> tripQueue = this->taxiCenter->getTrips();

    for (i = 0; i < taxiVec.size(); i++) {

        Trip *currTrip = tripQueue.front();
        Taxi *currTaxi = taxiVec.at(i);

        // If trip queue is empty and there are not more trips
        if (tripQueue.empty()) {
            break;
        }
        else if (currTaxi->getTrip() != 0) {
            continue;
        }
        else {

            // Calculate new coefficient according to vehicle type
            currTrip->setTariff(currTrip->getTariff()
                                * currTaxi->getVehicle()->getCoefficient());

            // Assign trip to taxi
            currTaxi->setTrip(currTrip);

            // Set the new taxi's current location to end point
            currTaxi->setCurrentPosition(currTrip->getEndPoint());
            tripQueue.pop();

        }
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
    //TODO: there is a confusion between int and unsigned
    for (int vehicleIndex = 0;
         vehicleIndex < taxiCenter->getVehicles().size(); ++vehicleIndex) {
        delete taxiCenter->getVehicles().at(vehicleIndex);
    }

    //exit the system
    exit(0);
}




