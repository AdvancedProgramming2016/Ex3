
#include "Taxi.h"

Taxi::Taxi(Driver *driver, Vehicle *vehicle, const Point &currentPosition, Trip *trip) : driver(
        driver), vehicle(vehicle), currentPosition(currentPosition), trip(trip) {}

Taxi::Taxi(Driver *driver, Vehicle *vehicle, const Point &currentPosition) : driver(
        driver), vehicle(vehicle), currentPosition(currentPosition), trip(0) {}

Taxi::~Taxi() {
    delete trip;
}

Driver *Taxi::getDriver() const {
    return driver;
}

void Taxi::setDriver(Driver *driver) {
    Taxi::driver = driver;
}

Vehicle *Taxi::getVehicle() const {
    return vehicle;
}

void Taxi::setVehicle(Vehicle *vehicle) {
    Taxi::vehicle = vehicle;
}

const Point &Taxi::getCurrentPosition() const {
    return currentPosition;
}

void Taxi::setCurrentPosition(const Point &currentPosition) {
    Taxi::currentPosition = currentPosition;
}

Trip *Taxi::getTrip() const {
    return trip;
}

void Taxi::setTrip(Trip *trip) {
    Taxi::trip = trip;
}

const std::vector<Passenger> &Taxi::getPassengers() const {
    return passengers;
}

void Taxi::setPassengers(const std::vector<Passenger> &passengers) {
    Taxi::passengers = passengers;
}

void Taxi::updateSatisfaction() {

}

void Taxi::endTrip() {

}



