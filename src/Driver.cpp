
#include "Driver.h"


Driver::Driver(unsigned int driverId, unsigned int age,
               MaritalStatus maritalStatus, unsigned int yearsOfExperience,
               unsigned int vehicleId)
        : driverId(driverId), age(age),
          yearsOfExperience(yearsOfExperience),
          avgSatisfaction(0),
          counterOfCustomers(0),
          maritalStatus(maritalStatus),
          taxi(0),
          vehicleId(vehicleId) {}

Driver::~Driver() {
    delete taxi;
}


unsigned int Driver::getDriverId() const {
    return driverId;
}

unsigned int Driver::getYearsOfExperience() const {
    return yearsOfExperience;
}

unsigned int Driver::getCounterOfCustomers() const {
    return counterOfCustomers;
}

void Driver::increaseExperience() {

    yearsOfExperience++;
}

void Driver::setCounterOfCustomers(unsigned int counterOfCustomers) {
    Driver::counterOfCustomers = counterOfCustomers;
}

Taxi *Driver::getTaxi() const {
    return taxi;
}

void Driver::setTaxi(Taxi *taxi) {
    Driver::taxi = taxi;
}

unsigned int Driver::getAvgSatisfaction() const {
    return avgSatisfaction;
}

unsigned int Driver::getVehicleId() const {
    return vehicleId;
}

void Driver::update(ISubject *subject) {

}
