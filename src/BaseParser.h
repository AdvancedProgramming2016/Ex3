
#ifndef EX2_CHECK_BASEPARSER_H
#define EX2_CHECK_BASEPARSER_H

class Driver;
class Grid;
class Trip;
class Vehicle;

class BaseParser {

public:

    virtual void checkGridInput(int height, int width) = 0;

    virtual Grid *parseGridInput() = 0;

    virtual int checkUserInput(char *stringToCheck) = 0;

    virtual Driver *parseDriverInput() = 0;

    virtual Trip *parseTripInput() = 0;

    virtual Vehicle *parseVehicleInput() = 0;

};

#endif //EX2_CHECK_BASEPARSER_H
