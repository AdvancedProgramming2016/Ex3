
#include "TaxiCenter.h"

TaxiCenter::TaxiCenter(Point *taxiCenterLocation) : taxiCenterLocation(taxiCenterLocation) {}

TaxiCenter::~TaxiCenter() {

}

std::vector<Driver *> &TaxiCenter::getDrivers() {
    return drivers;
}

std::vector<Vehicle *> &TaxiCenter::getVehicles() {
    return vehicles;
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

Trip* TaxiCenter::answerCall() {

}

void TaxiCenter::createTaxi() {

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


