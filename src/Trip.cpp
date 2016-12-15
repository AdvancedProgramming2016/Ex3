
#include "Trip.h"

Trip::Trip(unsigned int rideId, Point &tartPoint,
           Point &endPoint, unsigned int numOfPassengers,
           double tariff) : rideId(rideId), numOfPassengers(numOfPassengers), tariff(tariff),
                                  startPoint(startPoint),
                                  endPoint(endPoint),
                                  totalMetersPassed(0) {}

Trip::~Trip() {

}

unsigned int Trip::getRideId() const {
    return rideId;
}

unsigned int Trip::getTotalMetersPassed() const {
    return totalMetersPassed;
}

unsigned int Trip::getNumOfPassengers() const {
    return numOfPassengers;
}

void Trip::setTariff(double newTariff) {
    this->tariff = newTariff;
}

double Trip::getTariff() const {
    return tariff;
}

Taxi *Trip::getTaxi() const {
    return taxi;
}

const Point &Trip::getStartPoint() const {
    return startPoint;
}

const Point &Trip::getEndPoint() const {
    return endPoint;
}



