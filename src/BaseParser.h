//
// Created by commanderx on 07/12/16.
//

#ifndef EX2_CHECK_BASEPARSER_H
#define EX2_CHECK_BASEPARSER_H

#include<iostream>
#include "Vehicle.h"
#include "Trip.h"
#include "Graph.h"

class BaseParser {

public:

    virtual void checkGridInput(int height, int width) = 0;
    virtual Graph* parseGridInput() = 0;
    virtual int checkUserInput(char *stringToCheck) = 0;
    virtual Driver* parseDriverInput() = 0;
    virtual Trip* parseTripInput() = 0;
    virtual Vehicle* parseVehicleInput() = 0;

};

#endif //EX2_CHECK_BASEPARSER_H
