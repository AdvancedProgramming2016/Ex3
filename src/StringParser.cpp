//
// Created by commanderx on 07/12/16.
//

#include <cstring>
#include <sstream>
#include "StringParser.h"
#include "Driver.h"
#include "Trip.h"
#include "Grid.h"


StringParser::StringParser() {

}

void StringParser::checkGridInput(int height, int width){

}

int StringParser::checkUserInput(char *stringToCheck) {

}

Driver* StringParser::parseDriverInput() {

    unsigned int id;
    unsigned int age;
    unsigned int experience;
    unsigned int vehicleId;
    char status;

    std::cin >> id;
    std::cin >> age;
    std::cin >> status;
    std::cin >> experience;
    std::cin >> vehicleId;

    return new Driver(id, age, status, experience, vehicleId);

}

Graph* StringParser::parseGridInput() {

    int width;
    int height;

    // Receive input from the user
    std::cin >> width;
    std::cin >> height;

    //TODO: Need to do something with obstacles
    std::vector<Point> obstacles;

    // Create instance of graph
    Graph *graph = new Grid(height, width, obstacles);
    return graph;

}

Trip* StringParser::parseTripInput() {

    unsigned int id;
    unsigned int startX;
    unsigned int startY;
    unsigned int endX;
    unsigned int endY;
    unsigned int numOfPassengers;
    double tariff;

    std::cin >> id;
    std::cin >> startX;
    std::cin >> startY;
    std::cin >> endX;
    std::cin >> endY;
    std::cin >> numOfPassengers;
    std::cin >> tariff;

    return new Trip(id, new Point(startX, startY), new Point(endX, endY), numOfPassengers, tariff);


}

Vehicle* StringParser::parseVehicleInput() {

    int id, taxiType;
    char manufacturer, color;

    std::cin >> id;
    std::cin >> taxiType;
    std::cin >> manufacturer;
    std::cin >> color;

    return this->vehicleFactory.makeVehicle(id, taxiType, manufacturer, color);

}

