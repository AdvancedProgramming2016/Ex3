
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
    void createDriver(unsigned int driverId, unsigned int age,
                      MaritalStatus maritalStatus,
                      unsigned int yearsOfExperience,
                      unsigned int vehicleId);

    /*
     * Creates a new vehicle.
     */
    void createVehicle(int id, int vehicleType,
                       Manufacturer manufacturer, Color color);

    void createTrip(unsigned int rideId, unsigned int startX,
                    unsigned int startY, unsigned int endX,
                    unsigned int endY, unsigned int numOfPassengers,
                    unsigned int tariff);

    /*
     * Returns the taxi center.
     */
    TaxiCenter *getTaxiCenter() const;

    /*
     * Returns the map.
     */
    Grid *getMap() const;
};


#endif //EX2_MAINFLOW_H
