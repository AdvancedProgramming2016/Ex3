
#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

#include <vector>
#include <queue>
#include "Driver.h"
#include "Vehicle.h"
#include "Taxi.h"
#include "ISubject.h"
#include "StringParser.h"

class Driver;

class Taxi;

class Point;

class Trip;

class Passenger;

/**
 * The class represents a taxi center, which manages all the taxis.
 * It receives passengers calls, and assigns drivers to vehicles.
 * Searches for the best route a taxi can take to complete a trip.
 */
class TaxiCenter : public ISubject {

private:
    std::vector<Driver *>  drivers;
    std::vector<Vehicle *> vehicles;
    std::vector<Taxi *>    taxis;
    std::queue<Trip *>     trips;
    Point                  *taxiCenterLocation;
    std::vector<IObserver> observers;

    void addTaxi(Taxi *taxi);

public:

    /*
     * Constructor
     */
    TaxiCenter(Point *taxiCenterLocation);

    /*
     * Destructor
     */
    virtual ~TaxiCenter();

    Trip *answerCall();

    /*
    * Creates a new taxi by connecting a driver with a vehicle.
    */
    void createTaxi(Driver *driver);

    const std::vector<IObserver> &getObservers() const;

    /*
     * Add a driver to the drivers the taxi center has.
     */
    void addDriver(Driver *driver);

    void addTrip(Trip *trip);

    /*
     * Adds a vehicle to the vehicles the taxi center has.
     */
    void addVehicle(Vehicle *vehicle);

    /*
     * Returns the taxi center location on the map.
     */
    Point *getTaxiCenterLocation();

    /*
     * Returns the drivers the taxi center has.
     */
    std::vector<Driver *> &getDrivers();

    /*
     * Returns the vehicles the taxi center has.
     */
    std::vector<Vehicle *> &getVehicles();

    std::queue<Trip *> &getTrip();

    /*
     * Returns the taxis the taxi center has.
     */
    std::vector<Taxi *> &getTaxis();

    /*
     * Returns the trips that are waiting for a taxi.
     */
    std::queue<Trip *> &getTrips();

    virtual void registerObserver(IObserver *observer);

    virtual void unregisterObserver(IObserver *observer);

    virtual void notifyObserver();

    void printDriverLocation(const Driver &driver);

    friend int StringParser::addNewDriver(TaxiCenter &taxiCenter, Driver *driver);

    friend int StringParser::addNewTrip(TaxiCenter &taxiCenter, Trip *trip);

    friend int StringParser::addNewVehicle(TaxiCenter &taxiCenter, Vehicle *vehicle);
};


#endif //EX2_TAXICENTER_H
