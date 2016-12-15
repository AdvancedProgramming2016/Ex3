
#include "MainFlow.h"

MainFlow::MainFlow() {
//TODO remove this
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

            //TODO make sure it is added to the original queue and not as a copy, might want to use a pointer.
            // Set the new taxi's current location to end point
            currTaxi->setCurrentPosition(currTrip->getEndPoint());
            tripQueue.pop();

        }
    }
}


void MainFlow::exitSystem() {

    delete taxiCenter;
    delete map;

    //exit the system
    exit(0);
}




