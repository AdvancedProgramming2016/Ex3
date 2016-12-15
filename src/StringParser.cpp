//
// Created by commanderx on 07/12/16.
//

#include <cstring>
#include <sstream>
#include "StringParser.h"
#include "Driver.h"
#include "Trip.h"
#include "Grid.h"
#include "MainFlow.h"


StringParser::StringParser() {

}

void StringParser::checkGridInput(int height, int width) {

}

int StringParser::checkUserInput(char *stringToCheck) {

}

Driver *StringParser::parseDriverInput() {

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

Graph *StringParser::parseGridInput() {

    int width;
    int height;

    // Receive input from the user
    std::cin >> width;
    std::cin >> height;
    //std::cin >> obstacles;

    //TODO: Need to do something with obstacles
    std::vector<Point> obstacles;

    // Create instance of graph
    Graph *graph = new Grid(height, width, obstacles);
    return graph;

}

Trip *StringParser::parseTripInput() {

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

    Point sPoint(startX, startY);
    Point ePoint(endX, endY);
    return new Trip(id, sPoint , ePoint,
                    numOfPassengers, tariff);

}

Vehicle *StringParser::parseVehicleInput() {

    int id, taxiType;
    char manufacturer, color;

    std::cin >> id;
    std::cin >> taxiType;
    std::cin >> manufacturer;
    std::cin >> color;

    return this->vehicleFactory.makeVehicle(id, taxiType, manufacturer, color);

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