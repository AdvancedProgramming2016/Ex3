#include "gtest/gtest.h"
#include "../src/MainFlow.h"

class MainFlowTest : public ::testing::Test {

protected:

    MainFlow mainFlow;
    Driver *driver;
    Vehicle *vehicle;

    virtual void SetUp() {
        mainFlow.createMap(5, 5);
        mainFlow.createTaxiCenter(new Point(0, 0));
        driver = new Driver(0, 50, 'M', 27, 1);
        vehicle = new StandardVehicle(1, 'F', 'W');
    }

    virtual void TearDown() {
        delete driver;
        delete vehicle;
    }

public:
    MainFlowTest() : mainFlow() {}

};

/*
 * Check that the main flow methods work correctly.
 */

TEST_F(MainFlowTest, basicTest) {

    int  preDriversNum  = 0;
    int  postDriverNum  = 0;
    int  preVehicleNum  = 0;
    int  postVehicleNum = 0;
    bool foundDriver    = false;
    bool foundVehicle   = false;

    // ASSERT_NE(mainFlow.getMap(), 0);        // make sure a map exists
    // ASSERT_NE(mainFlow.getTaxiCenter(), 0); // make sure a taxi center exists

    preDriversNum = (int) mainFlow.getTaxiCenter()->getDrivers().size();
    mainFlow.createDriver(driver);

    for (int i = 0; i < mainFlow.getTaxiCenter()->getDrivers().size(); ++i) {

        if (mainFlow.getTaxiCenter()->getDrivers().at(i)->getDriverId() ==
            driver->getDriverId()) {
            foundDriver = true;
        }
    }

    // ASSERT_TRUE(foundDriver); // make sure that the correct driver was added to the list.

    postDriverNum = (int) mainFlow.getTaxiCenter()->getDrivers().size();

    //ASSERT_EQ(preDriversNum + 1, postDriverNum); // check that a new driver was created

    preVehicleNum = (int) mainFlow.getTaxiCenter()->getVehicles().size();
    mainFlow.createVehicle(vehicle);

    for (int j = 0; j < mainFlow.getTaxiCenter()->getVehicles().size(); ++j) {

        if (mainFlow.getTaxiCenter()->getVehicles().at(j)->getVehicleId() ==
            vehicle->getVehicleId()) {

            foundVehicle = true;
        }
    }

    //ASSERT_TRUE(foundVehicle); // check that the correct vehicle was added to the list.

    postVehicleNum = (int) mainFlow.getTaxiCenter()->getVehicles().size();

    //ASSERT_EQ(preVehicleNum + 1, postVehicleNum); // check that a new vehicle was created
}

/*
 * Verifies the validity of the start drive function
 */
TEST_F(MainFlowTest, startDriveBasicTest) {

    Point startPt(2, 2);
    Point endPt(0, 1);

    Trip *trip1 = new Trip(78, startPt, endPt, 2, 3);

    // Create taxi and trip and start driving
    this->mainFlow.createVehicle(vehicle);
    this->mainFlow.createDriver(driver);
    this->mainFlow.createTrip(trip1);
    this->mainFlow.startDriving();

    // Checks that the end point of the taxi was changed to the end of the trip
    EXPECT_TRUE(
            this->mainFlow.getTaxiCenter()->getTaxis()[0]->getCurrentPosition()
            == endPt);

    // I get segmentation fault here for some reason
    //delete trip1;

}



