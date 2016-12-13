
#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H


#include "TaxiCenter.h"
#include "Grid.h"
#include "VehicleFactory.h"

class MainFlow {

private:

    TaxiCenter     *taxiCenter;
    Grid           *map;
    VehicleFactory vehicleFactory;

public:

    /*
     * Constructor.
     */
    MainFlow(); //TODO maybe make as a singleton

    /*
     * Destructor.
     */
    virtual ~MainFlow();

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
