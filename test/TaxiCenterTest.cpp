#include "gtest/gtest.h"
#include "../src/TaxiCenter.h"

/**
 * The class performs unit tests upon the Taxi center class.
 */
class TaxiCenterTest : public ::testing::Test {
protected:

    TaxiCenter               taxiCenter;
    std::vector<Passenger *> passengerList;
    Point                    *point;

    virtual void SetUp() {

        point         = new Point(0, 0);
        Passenger *p = new Passenger(Point(1, 1), Point(2, 1));
        passengerList = {p};
    }

    virtual void TearDown() {

        delete point;

        for (int i = 0; i < passengerList.size(); ++i) {
            delete passengerList.at(i);
        }
    }

public:
    TaxiCenterTest() : taxiCenter(point) {}

};

/*
 * Checks that the standard TaxiCenter methods work.
 */
TEST_F(TaxiCenterTest, basicTest) {

    Vehicle *v1 = new Vehicle(1234, 'F', 'B');
    Driver *d1 = new Driver(2, 50, 'M', 4, 1234);

    // Check validity of addVehicle, addDriver and createTaxi functions
    taxiCenter.addVehicle(v1);
    taxiCenter.addDriver(d1);
    taxiCenter.createTaxi(d1);
    EXPECT_EQ(taxiCenter.getTaxis()[0]->getDriver()->getDriverId(), 2);

    // Check request Driver location
    testing::internal::CaptureStdout();
    taxiCenter.requestDriverLocation(2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output == "(0,0)\n");

    //delete d1;
    //delete v1; // TODO this caused an error!!!
}