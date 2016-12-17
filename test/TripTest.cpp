#include "gtest/gtest.h"
#include "../src/Trip.h"
#include "../src/StandardVehicle.h"

/**
 * The class performs unit tests upon the Trip class.
 */
class TripTest : public ::testing::Test {
protected:
    Trip    trip;
    Taxi    *taxi;
    Driver  *driver;
    Vehicle *vehicle;

    virtual void SetUp() {

        driver  = new Driver(0, 25, 'S', 5, 0);
        vehicle = new StandardVehicle(0, 'H', 'B');
        taxi    = new Taxi(driver, vehicle, Point(0, 0));
        Point start = Point(0,0);
        Point end = Point(2,2);
        trip = Trip(0, start, end, 1, 10);
    }

    virtual void TearDown() {

        delete driver;
        delete vehicle;
        delete taxi;
    }
};

//No checks were needed, yet.



