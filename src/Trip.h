
#ifndef EX2_TRIP_H
#define EX2_TRIP_H


#include "Taxi.h"

/**
 * The class represents a trip, which a taxi takes along the map, from one point to another.
 */
class Taxi;

class Trip {

private:

    unsigned rideId;
    unsigned totalMetersPassed;
    unsigned numOfPassengers;
    double   tariff;
    Taxi     *taxi;
    Point    startPoint;
    Point    endPoint;

public:

    //TODO what about the taxi int the initialization of trip?
    /*
     * Constructor.
     */
    Trip(unsigned int rideId, const Point &startPoint,
         const Point &endPoint, unsigned int numOfPassengers,
         double tariff);

    /*
     * Destructor.
     */
    virtual ~Trip();

    /*
     * Returns the ride id.
     */
    unsigned int getRideId() const;

    /*
     * Returns the total number of meters passed from the beginning of the trip.
     */
    unsigned int getTotalMetersPassed() const;

    /*
     * Returns the number of passengers taking the trip.
     */
    unsigned int getNumOfPassengers() const;

    /*
     * Returns the trip coefficient
     */
    double getTariff() const;

    /*
     * Set the new trip coefficient
     */
    void setTariff(double newTariff);

    /*
     * Returns the taxi that is taking the trip.
     */
    Taxi *getTaxi() const;

    /*
     * Returns the starting point of the trip.
     */
    const Point &getStartPoint() const;

    /*
     * Returns the ending point of the trip.
     */
    const Point &getEndPoint() const;
};


#endif //EX2_TRIP_H
