

#include <cstring>
#include <sstream>
#include "StringParser.h"

#include "MainFlow.h"


StringParser::StringParser() {

}

void StringParser::checkGridInput(int height, int width) {

}

int StringParser::checkUserInput(char *stringToCheck) {

}

Driver *StringParser::parseDriverInput() {

    int numOfParams = 5;
    int id = 0;
    int age = 1;
    int experience = 2;
    int vehicleId = 3;
    int status = 4;
    std::string inputArr[numOfParams];
    std::string userInput;

    std::cin >> userInput;

    this->splitByComma(inputArr, numOfParams, userInput);

    return new Driver(atoi(inputArr[id]), atoi(inputArr[age]),
                      inputArr[status][0], atoi(inputArr[experience]),
                      atoi(inputArr[vehicleId]));

}

Graph *StringParser::parseGridInput() {

    int width = 0;
    int height = 0;
    int numOfObstacles = 0;
    int x = 0;
    int y = 0;

    // Receive input from the user
    std::cin >> width;
    std::cin >> height;
    std::cin >> numOfObstacles;
    //std::cin >> obstacles;

    std::vector<Point> obstacles;

    for (int i = 0; i < numOfObstacles; ++i) {
        std::cin >> x;
        std::cin >> y;
        obstacles.push_back(Point(x, y));
    }

    //TODO: Need to do something with obstacles


    // Create instance of graph
    Graph *graph = new Grid(height, width, obstacles);
    return graph;

}

Trip *StringParser::parseTripInput() {

    int numOfParams = 7;
    int id = 0;
    int startX = 1;
    int startY = 2;
    int endX = 3;
    int endY = 4;
    int numOfPassengers = 5;
    int tariff =6;
    std::string userInput;
    std::string inputArr[numOfParams];

    std::cin >> userInput;

    this->splitByComma(inputArr, numOfParams, userInput);

    Point sPoint(atoi(inputArr[startX]), atoi(inputArr[startY]));
    Point ePoint(atoi(inputArr[endX]), atoi(inputArr[endY]));

    return new Trip(atoi(inputArr[id]), sPoint, ePoint,
                    atoi(inputArr[numOfPassengers]), std::stod(inputArr[tariff]));

}

Vehicle *StringParser::parseVehicleInput() {

    int numOfinputs = 4;
    int id = 0;
    int taxiType = 1;
    int manufacturer = 2;
    int color = 3;
    std::string inputArr[numOfinputs];
    std::string userInput;

    std::cin >> userInput;

    // Splits the user input by commas and returns array of inputs
    this->splitByComma(inputArr, numOfinputs, userInput);

    return this->vehicleFactory.makeVehicle(atoi(inputArr[id]),
                                            atoi(inputArr[taxiType]),
                                            inputArr[manufacturer][0],
                                            inputArr[color][0]);

}

// TODO: What is this for??
unsigned int StringParser::parseDriverLocation() {

    unsigned int driverId;

    std::cin >> driverId;

    return driverId;
}

int StringParser::addNewDriver(TaxiCenter &taxiCenter, Driver *driver) {
    taxiCenter.getDrivers().push_back(driver);
}

int StringParser::addNewVehicle(TaxiCenter &taxiCenter, Vehicle *vehicle) {
    taxiCenter.getVehicles().push_back(vehicle);
}

int StringParser::addNewTrip(TaxiCenter &taxiCenter, Trip *trip) {
    taxiCenter.getTrips().push(trip);
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
