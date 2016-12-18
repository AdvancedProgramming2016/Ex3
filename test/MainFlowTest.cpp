#include "gtest/gtest.h"
#include "../src/MainFlow.h"

class MainFlowTest : public ::testing::Test {

protected:

    MainFlow           mainFlow;
    Driver             *driver;
    Vehicle            *vehicle;
    std::vector<Point> obstacles;
    Grid               *grid;

    virtual void SetUp() {
        grid = new Grid(5, 5, obstacles);
        mainFlow.createMap(grid);
        mainFlow.createTaxiCenter(new Point(0, 0));
        driver  = new Driver(0, 50, 'M', 27, 1);
        vehicle = new StandardVehicle(1, 'F', 'W');
    }

    virtual void TearDown() {
        delete driver;
        delete vehicle;
        delete grid;
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

    EXPECT_FALSE(mainFlow.getMap() == 0);        // make sure a map exists
    EXPECT_FALSE(
            mainFlow.getTaxiCenter() == 0); // make sure a taxi center exists

    preDriversNum = (int) mainFlow.getTaxiCenter()->getDrivers().size();
    mainFlow.createDriver(driver);

    for (int i = 0; i < mainFlow.getTaxiCenter()->getDrivers().size(); ++i) {

        if (mainFlow.getTaxiCenter()->getDrivers().at(i)->getDriverId() ==
            driver->getDriverId()) {
            foundDriver = true;
        }
    }

    EXPECT_TRUE(
            foundDriver); // make sure that the correct driver was added to the list.

    postDriverNum = (int) mainFlow.getTaxiCenter()->getDrivers().size();

    EXPECT_TRUE(preDriversNum + 1 ==
                postDriverNum); // check that a new driver was created

    preVehicleNum = (int) mainFlow.getTaxiCenter()->getVehicles().size();
    mainFlow.createVehicle(vehicle);

    for (int j = 0; j < mainFlow.getTaxiCenter()->getVehicles().size(); ++j) {

        if (mainFlow.getTaxiCenter()->getVehicles().at(j)->getVehicleId() ==
            vehicle->getVehicleId()) {

            foundVehicle = true;
        }
    }

    EXPECT_TRUE(
            foundVehicle);
    // check that the correct vehicle was added to the list.

    postVehicleNum = (int) mainFlow.getTaxiCenter()->getVehicles().size();

    EXPECT_TRUE(preVehicleNum + 1 ==
                postVehicleNum); // check that a new vehicle was created
}

/*
 * Verifies the validity of the start drive function
 */
TEST_F(MainFlowTest, startDriveBasicTest) {

    Point startPt(0, 0);
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

}
