#include "gtest/gtest.h"
#include "../src/Vehicle.h"
#include "../src/StandardVehicle.h"
#include "../src/LuxuryVehicle.h"


class VehicleTest : public ::testing::Test {

protected:

    Vehicle *standardVehicle;
    Vehicle *luxuryVehicle;

    virtual void SetUp() {

        standardVehicle = new StandardVehicle(0, 'H', 'B');
        luxuryVehicle   = new LuxuryVehicle(1, 'T', 'W');
    }

    virtual void TearDown() {

        delete standardVehicle;
        delete luxuryVehicle;
    }
};

/*
 * Test that the basic vehicle methods work
 */
TEST_F(VehicleTest, basicCheck) {

    int kmPassedFirst = 0;
    int kmPassedLater = 0;

    kmPassedFirst = standardVehicle->getKmPassed();
    standardVehicle->increaseKmPassed();
    kmPassedLater = standardVehicle->getKmPassed();

    ASSERT_EQ(kmPassedFirst + 1,
              kmPassedLater); // check that the km counter increases by one.

}

/*
 * Compare between the different vehicles.
 */
TEST_F(VehicleTest, vehicleComparison) {

    double regularCoefficient = 0;
    double luxuryCoefficient  = 0;

    regularCoefficient = standardVehicle->getCoefficient();
    luxuryCoefficient  = luxuryVehicle->getCoefficient();

    //Checks that the coefficient of the standard vehicle,
    // is lower than the luxury kind.
    ASSERT_LT(regularCoefficient,
              luxuryCoefficient);
}



