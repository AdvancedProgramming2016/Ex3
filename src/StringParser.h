
#ifndef EX2_CHECK_STRINGPARSER_H
#define EX2_CHECK_STRINGPARSER_H

#include "BaseParser.h"
#include "VehicleFactory.h"

class Graph;
class Driver;
class TaxiCenter;

class StringParser : BaseParser {

private:

    VehicleFactory vehicleFactory;

    void checkGridInput(int height, int width);

public:

    StringParser();

    void
    splitByComma(std::string *inputArr, int size, std::string userInput);

    virtual Grid *parseGridInput();

    virtual int checkUserInput(char *stringToCheck);

    virtual Driver *parseDriverInput();

    virtual Trip *parseTripInput();

    virtual Vehicle *parseVehicleInput();

    virtual unsigned int parseDriverLocation();

    virtual int addNewDriver(TaxiCenter &taxiCenter, Driver *driver);

    virtual int addNewVehicle(TaxiCenter &taxiCenter, Vehicle *vehicle);

    virtual int addNewTrip(TaxiCenter &taxiCenter, Trip *trip);

};

#endif //EX2_CHECK_STRINGPARSER_H
