
#ifndef EX2_TAXI_H
#define EX2_TAXI_H

#include <vector>
#include "Vehicle.h"
#include "Driver.h"
#include "Point.h"
#include "Passenger.h"
#include "Trip.h"

class Driver;

/**
 * The class represents a taxi which is made up of a driver and a vehicle.
 * It can switch both the driver and the vehicle during its existance.
 */
class Taxi {

private:

    Driver                 *driver;
    Vehicle                *vehicle;
    Point                  currentPosition;
    Trip                   *trip;
    std::vector<Passenger> passengers;

    void updateSatisfaction();

public:

    /*
     * Constructor
     */
    Taxi(Driver *driver, Vehicle *vehicle, const Point &currentPosition, Trip *trip);

    /*
     * Constructor.
     */
    Taxi(Driver *driver, Vehicle *vehicle, const Point &currentPosition);

    /*
     * Destructor.
     */
    ~Taxi();

    /*
     * Returns the taxi driver
     */
    Driver *getDriver() const;

    /*
     * Sets the taxi driver
     */
    void setDriver(Driver *driver);

    /*
     * Returns the taxi vehicle
     */
    Vehicle *getVehicle() const;

    /*
     * Sets the taxi vehicle
     */
    void setVehicle(Vehicle *vehicle);

    /*
     * Returns the current taxi position
     */
    const Point &getCurrentPosition() const;

    /*
     * Sets the current taxi position
     */
    void setCurrentPosition(const Point &currentPosition);

    /*
     * Returns the taxi trip
     */
    Trip *getTrip() const;

    /*
     * Sets the taxi trip
     */
    void setTrip(Trip *trip);

    /*
     * Returns the passengers in the taxi
     */
    const std::vector<Passenger> &getPassengers() const;

    /*
     * Sets the passengers in the taxi
     */
    void setPassengers(const std::vector<Passenger> &passengers);

    void endTrip();

};


#endif //EX2_TAXI_H
