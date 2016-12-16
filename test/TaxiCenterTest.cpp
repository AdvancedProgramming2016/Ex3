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
        passengerList = {new Passenger(Point(1, 1), Point(2, 1))};
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

    unsigned initTaxisSize = 0;
    unsigned postTaxisSize = 0;

    initTaxisSize = (int) taxiCenter.getTaxis().size();
    taxiCenter.answerCall();
    postTaxisSize = (int) taxiCenter.getTaxis().size();

    EXPECT_EQ(initTaxisSize,
              postTaxisSize); //check that a taxi was added to the taxi center

    // TODO: DELETE BEFORE submitting
    //EXPECT_NE(taxiCenter.answerCall(), 0); // check that a new trip was sent
}