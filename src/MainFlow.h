
#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H


#include "TaxiCenter.h"
#include "Grid.h"
#include "VehicleFactory.h"
#include "StringParser.h"

class BaseParser;
class Trip;
class TaxiCenter;

class MainFlow {

private:

    BaseParser     *parser;
    TaxiCenter     *taxiCenter;
    Grid           *map;
    VehicleFactory vehicleFactory;

public:

    /*
     * Constructor.
     */
    MainFlow(); //TODO maybe make as a singleton

    /*
     * Connects all the vacant drivers and trip to taxis and drives.
     */
    void startDriving();

    /*
     * Creates a map with obstacles.
     */
    void createMap(unsigned height, unsigned width);

    /*
     * Creates a taxi center.
     */
    void createTaxiCenter(Point *location);

    /*
     * Creates a new driver.
     */
    void createDriver(Driver *driver);

    /*
     * Creates a new vehicle.
     */
    void createVehicle(Vehicle *vehicle);

    void createTrip(Trip * trip);

    /*
     * Returns the taxi center.
     */
    TaxiCenter *getTaxiCenter() const;

    /*
     * Returns the map.
     */
    Grid *getMap() const;

    /*
     * Exits the taxiCenter system by deleting all the instances and exiting.
     */
    void exitSystem();

};


#endif //EX2_MAINFLOW_H
