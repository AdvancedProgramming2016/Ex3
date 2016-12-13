//
// Created by commanderx on 07/12/16.
//

#ifndef EX2_CHECK_STRINGPARSER_H
#define EX2_CHECK_STRINGPARSER_H


#include <vector>
#include "BaseParser.h"
#include "Graph.h"
#include "VehicleFactory.h"

class StringParser: public BaseParser {

private:

    VehicleFactory vehicleFactory;

public:

    StringParser();
    virtual Graph* parseGridInput();
    virtual int checkUserInput(char *stringToCheck);
    virtual Driver* parseDriverInput();
    virtual Trip* parseTripInput();
    virtual Vehicle* parseVehicleInput();

private:
    void checkGridInput(int height, int width);
};

#endif //EX2_CHECK_STRINGPARSER_H
