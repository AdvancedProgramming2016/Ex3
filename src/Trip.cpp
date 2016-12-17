
#include "Trip.h"

Trip::Trip(unsigned int rideId, Point &startPoint,
           Point &endPoint, unsigned int numOfPassengers,
           double tariff){
    this->rideId = rideId;
    this->numOfPassengers = numOfPassengers;
    this->tariff = tariff;
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->totalMetersPassed = 0;
}

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

const Point &Trip::getStartPoint() const {
    return startPoint;
}

const Point &Trip::getEndPoint() const {
    return endPoint;
}



