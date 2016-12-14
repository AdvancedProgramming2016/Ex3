
#include "TaxiCenter.h"

TaxiCenter::TaxiCenter(Point *taxiCenterLocation) : taxiCenterLocation(
        taxiCenterLocation) {}

TaxiCenter::~TaxiCenter() {

    Trip *tempTrip = 0;

    //delete all the trips
    while (!trips.empty()) {

        //Save trip instance in a temporary pointer.
        tempTrip = trips.front();
        trips.pop();

        //Delete the trip and pop the queue.
        delete tempTrip;
    }

    //delete all the taxis.
    for (int taxisIndex = 0; taxisIndex < taxis.size(); ++taxisIndex) {
        delete taxis[taxisIndex];
    }

    for (int driversIndex = 0; driversIndex < drivers.size(); ++driversIndex) {
        delete drivers[driversIndex];
    }

    //delete all the vehicles.
    //TODO: there is a confusion between int and unsigned
    for (int vehiclesIndex = 0;
         vehiclesIndex < vehicles.size(); ++vehiclesIndex) {
        delete vehicles[vehiclesIndex];
    }

}

std::vector<Driver *> &TaxiCenter::getDrivers() {
    return drivers;
}

std::vector<Vehicle *> &TaxiCenter::getVehicles() {
    return vehicles;
}

std::queue<Trip *> &TaxiCenter::getTrips() {
    return trips;
}

std::vector<Taxi *> &TaxiCenter::getTaxis() {
    return taxis;
}

Point *TaxiCenter::getTaxiCenterLocation() {
    return taxiCenterLocation;
}

void TaxiCenter::addDriver(Driver *driver) {

    drivers.push_back(driver);
}

void TaxiCenter::addVehicle(Vehicle *vehicle) {

    vehicles.push_back(vehicle);
}

Trip *TaxiCenter::answerCall() {
    // not implemented yet
}

void TaxiCenter::createTaxi(Driver *driver) {

    for (int i = 0; i < vehicles.size(); ++i) {

        if (driver->getDriverId() == vehicles.at(i)->getVehicleId()) {

            Taxi *taxi = new Taxi(driver, vehicles.at(i), Point(0, 0));
            addTaxi(taxi);
        }
    }
}

void TaxiCenter::registerObserver(IObserver *observer) {

}

void TaxiCenter::unregisterObserver(IObserver *observer) {

}

void TaxiCenter::notifyObserver() {

}

const std::vector<IObserver> &TaxiCenter::getObservers() const {
    return observers;
}

void TaxiCenter::printDriverLocation(const Driver &driver) {

}

void TaxiCenter::addTaxi(Taxi *taxi) {

    taxis.push_back(taxi);
}

std::queue<Trip *> &TaxiCenter::getTrip() {
    return this->trips;
}

void TaxiCenter::addTrip(Trip *trip) {
    this->trips.push(trip);
}






