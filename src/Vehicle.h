
#ifndef EX2_VEHICLE_H
#define EX2_VEHICLE_H

/**
 * The class represents an abstract vehicle.
 */
//TODO decide how to make it an abstract class
class Vehicle {

private:
    unsigned vehicleId;
    unsigned kmPassed;
    char     carManufacturer;
    char     color;

protected:
    unsigned maxCapacity; //TODO decide how to use those
    double   coefficient;      // TODO that too

public:

    /*
     * Constructor
     */
    Vehicle(unsigned int vehicleId, char carManufacturer, char color);

    /*
     * Returns the vehicle id.
     */
    unsigned int getVehicleId() const;

    /*
     * Returns the number of kilometers a vehicle has passed
     */
    unsigned int getKmPassed() const;

    /*
     * Returns the type(enum) of the car manufacturer
     */
    char getCarManufacturer() const;

    /*
     * Returns the color(enum) of the vehicle
     */
    char getColor() const;

    /*
     * Returns the number of the maximum passenger capacity a vehicle can hold.
     */
    unsigned int getMaxCapacity() const;

    /*
     * Returns the vehicle coefficient
     */
    double getCoefficient() const;

    /*
     * Returns the vehicle's speed limit.
     */
    unsigned int getSpeedLimit() const;

    /*
     * Increases the number of kilometers passed by the vehicle by one.
     */
    void increaseKmPassed();

};

#endif //EX2_VEHICLE_H
