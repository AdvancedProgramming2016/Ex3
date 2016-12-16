#include "gtest/gtest.h"
#include "../src/Taxi.h"

class TaxiTest : public ::testing::Test {
protected:
    Taxi    *taxi;
    Driver  *driver;
    Vehicle *vehicle;
    Trip    *trip;

    virtual void SetUp() {

        driver  = new Driver(1, 40, 'M', 20, 1);
        vehicle = new StandardVehicle(1, 'S', 'P');
        Point start = Point(0, 0);
        Point end   = Point(2, 3);

        trip = new Trip(1, start, end, 3, 20);
        taxi = new Taxi(driver, vehicle, Point(0,0), trip);
    }

    virtual void TearDown() {

        delete driver;
        delete vehicle;
        delete trip;
    }

};

TEST_F(TaxiTest, basicTest) {

    unsigned initSatisfaction = 0;
    unsigned newSatisfaction  = 0;

    initSatisfaction = taxi->getDriver()->getAvgSatisfaction();
    taxi->endTrip();
    newSatisfaction = taxi->getDriver()->getAvgSatisfaction();

    ASSERT_EQ(taxi->getTrip(), 0);                 //check that the trip was set to NULL
    EXPECT_NE(initSatisfaction, newSatisfaction); //check that the average satisfaction was changed, not mandatory //TODO might be a bad way to check

}

