
#ifndef EX2_DRIVER_H
#define EX2_DRIVER_H

#include <unwind.h>
#include "Taxi.h"
#include "IObserver.h"

/**
 * This enum represents the marital status a driver has.
 */
enum MaritalStatus{
    SINGLE,
    MARRIED,
    DIVORCED,
    WIDOWED
};

/**
 * The class represents a driver of a taxi vehicle.
 *
 */
class Driver: public IObserver {

private:

    unsigned      driverId;
    unsigned      age;
    unsigned      yearsOfExperience;
    unsigned      vehicleId;
    unsigned      avgSatisfaction;
    unsigned      counterOfCustomers;
    MaritalStatus maritalStatus;
    Taxi          *taxi;

public:
    /*
    * Constructor.
    */
    Driver(unsigned int driverId, unsigned int age,
           MaritalStatus maritalStatus, unsigned int yearsOfExperience,
           unsigned int vehicleId);

    /*
     * Destructor
     */
    virtual ~Driver();

    /*
    * Returns the driver id.
    */
    unsigned int getDriverId() const;


    /*
    * Returns the driver's years of experience.
    */
    unsigned int getYearsOfExperience() const;


    /*
    * Returns the counter of customers.
    */
    unsigned int getCounterOfCustomers() const;


    /*
    * Increases the driver's years of experience by one.
    */
    void increaseExperience();

    /*
    * Sets the counter of customers to the received number.
    */
    void setCounterOfCustomers(unsigned int counterOfCustomers);

    /*
     * Returns the driver's taxi.
     */
    Taxi *getTaxi() const;

    /*
     * Sets the drivers taxi.
     */
    void setTaxi(Taxi *taxi);

    /*
     * Returns the average driver satisfaction.
     */
    unsigned int getAvgSatisfaction() const;

    /*
     * Returns the driver's vehicle's id number.
     */
    unsigned int getVehicleId() const;

    /*
     * Send update about the driver.
     */
    virtual void update(ISubject *subject);
};


#endif //EX2_DRIVER_H
