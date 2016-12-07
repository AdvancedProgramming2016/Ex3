
#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

#include <vector>
#include "Driver.h"
#include "Vehicle.h"
#include "Taxi.h"
#include "ISubject.h"

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
    Point       *           taxiCenterLocation;
    std::vector<IObserver> observers;

    /*
     * Creates a new taxi.
     */
    void createTaxi();

public:

    /*
     * Constructor
     */
    TaxiCenter(Point *taxiCenterLocation);

    /*
     * Destructor
     */
    virtual ~TaxiCenter();

    Trip* answerCall();

    const std::vector<IObserver> &getObservers() const;

    /*
     * Add a driver to the drivers the taxi center has.
     */
    void addDriver(Driver *driver);

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

    /*
     * Returns the taxis the taxi center has.
     */
    std::vector<Taxi *> &getTaxis();

    virtual void registerObserver(IObserver *observer);

    virtual void unregisterObserver(IObserver *observer);

    virtual void notifyObserver();

    void printDriverLocation(const Driver &driver);

};


#endif //EX2_TAXICENTER_H
