#include "gtest/gtest.h"
#include "../src/Driver.h"
#include "../src/StandardVehicle.h"
#include "../src/TaxiCenter.h"

/*
 * Checks the basic driver functionality.
 */
TEST(DriverTest, basicTest) {

    Driver   *driver;
    unsigned initialExp = 0;
    unsigned postExp    = 0;

    driver     = new Driver(0, 30, 'M', 7, 0);
    initialExp = driver->getYearsOfExperience();
    driver->increaseExperience();
    postExp = driver->getYearsOfExperience();

    ASSERT_EQ(initialExp + 1,
              postExp); // check that the experience increased by one.

    delete driver;
}

TEST(DriverTest, observerTest) {

    Driver     *driver     = new Driver(0, 30, 'M', 7, 0);
    Vehicle    *vehicle    = new StandardVehicle(0, 'H', 'G');
    Taxi       *taxi       = new Taxi(driver, vehicle, Point(0, 0));
    TaxiCenter *taxiCenter = new TaxiCenter(new Point(0, 0));


    int       initObserverNum = 0;
    int       postObserverNum = 0;
    IObserver *observer;

    initObserverNum = (int) taxi->getObservers().size();
    taxi->registerObserver(taxiCenter);
    postObserverNum = (int) taxi->getObservers().size();

    ASSERT_EQ(initObserverNum + 1,
              postObserverNum); //check that adding an observer works

    taxi->unregisterObserver(taxiCenter);

    postObserverNum = (int) taxi->getObservers().size();

    ASSERT_EQ(initObserverNum,
              postObserverNum); //check that removing an observer works
}


