

#include <cstring>
#include <sstream>
#include "StringParser.h"

#include "MainFlow.h"

Driver *StringParser::parseDriverInput() {

    int numOfParams = 5;
    int id          = 0;
    int age         = 1;
    int status      = 2;
    int experience  = 3;
    int vehicleId   = 4;

    std::string inputArr[numOfParams];
    std::string userInput;

    std::cin >> userInput;

    this->splitByComma(inputArr, numOfParams, userInput);

    return new Driver(stoi(inputArr[id]),
                      stoi(inputArr[age]),
                      inputArr[status][0],
                      stoi(inputArr[experience]),
                      stoi(inputArr[vehicleId]));

}

Grid *StringParser::parseGridInput() {

    unsigned width          = 0;
    unsigned height         = 0;
    int      numOfObstacles = 0;
    int      numOfParams    = 2;
    int      x              = 0;
    int      y              = 1;

    // Receive input from the user
    std::cin >> width;
    std::cin >> height;
    std::cin >> numOfObstacles;

    std::vector<Point> obstacles;
    std::string        inputArr[numOfParams];
    std::string        userInput;

    for (int i = 0; i < numOfObstacles; ++i) {

        std::cin >> userInput;
        this->splitByComma(inputArr, numOfParams, userInput);
        obstacles.push_back(Point(stoi(inputArr[x]), stoi(inputArr[y])));
    }

    return new Grid(height, width, obstacles);

}

Trip *StringParser::parseTripInput() {

    int         numOfParams     = 7;
    int         id              = 0;
    int         startX          = 1;
    int         startY          = 2;
    int         endX            = 3;
    int         endY            = 4;
    int         numOfPassengers = 5;
    int         tariff          = 6;
    std::string userInput;
    std::string inputArr[numOfParams];

    std::cin >> userInput;

    this->splitByComma(inputArr, numOfParams, userInput);

    Point sPoint(stoi(inputArr[startX]), stoi(inputArr[startY]));
    Point ePoint(stoi(inputArr[endX]), stoi(inputArr[endY]));

    return new Trip(stoi(inputArr[id]), sPoint, ePoint,
                    stoi(inputArr[numOfPassengers]),
                    std::stod(inputArr[tariff]));

}

Vehicle *StringParser::parseVehicleInput() {

    int         numOfInputs  = 4;
    int         id           = 0;
    int         taxiType     = 1;
    int         manufacturer = 2;
    int         color        = 3;
    std::string inputArr[numOfInputs];
    std::string userInput;

    std::cin >> userInput;

    // Splits the user input by commas and returns array of inputs
    this->splitByComma(inputArr, numOfInputs, userInput);

    return this->vehicleFactory.makeVehicle(stoi(inputArr[id]),
                                            stoi(inputArr[taxiType]),
                                            inputArr[manufacturer][0],
                                            inputArr[color][0]);
}

unsigned int StringParser::parseDriverLocation() {

    unsigned int driverId;

    std::cin >> driverId;

    return driverId;
}

void StringParser::splitByComma(std::string *inputArr, int size,
                                std::string userInput) {

    std::stringstream ss(userInput);

    int i = 0;
    // Split the input by commas
    for (i = 0; i < size; i++) {
        std::getline(ss, inputArr[i], ',');
    }

}
