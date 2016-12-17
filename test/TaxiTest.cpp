#include "gtest/gtest.h"
#include "../src/Taxi.h"
#include "../src/StandardVehicle.h"

class TaxiTest : public ::testing::Test {

};

TEST_F(TaxiTest, basicTest) {

    // Init variables
    unsigned initSatisfaction = 0;
    unsigned newSatisfaction = 0;
    Driver *driver = new Driver(1, 40, 'M', 20, 1);
    Vehicle *vehicle = new StandardVehicle(1, 'S', 'P');
    Point start(0, 0);
    Point end(2, 3);

    Trip *trip = new Trip(1, start, end, 3, 20);
    Taxi *taxi = new Taxi(driver, vehicle, Point(0, 0));

    initSatisfaction = taxi->getDriver()->getAvgSatisfaction();
    taxi->endTrip();
    newSatisfaction = taxi->getDriver()->getAvgSatisfaction();

    // TODO: delete before submitting
   // ASSERT_TRUE(taxi->getTrip() == 0);                 //check that the trip was set to NULL
    //EXPECT_NE(initSatisfaction,
      //        newSatisfaction); //check that the average satisfaction was changed, not mandatory //TODO might be a bad way to check

    //Delete Variables
    delete taxi;
    delete vehicle;
    delete driver;

}
