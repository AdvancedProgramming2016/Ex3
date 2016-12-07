
#ifndef EX2_VEHICLE_H
#define EX2_VEHICLE_H


enum Color {
    RED,
    BLUE,
    GREEN,
    PINK,
    WHITE
};

/**
 * This enum represents the car manufacurer.
 */
enum Manufacturer {
    HONDA,
    SUBARU,
    TESLA,
    FIAT
};

/**
 * The class represents an abstract vehicle.
 */
//TODO decide how to make it an abstract class
class Vehicle {

private:
    unsigned     vehicleId;
    unsigned     kmPassed;
    Manufacturer carManufacturer;
    Color        color;

protected:
    unsigned maxCapacity; //TODO decide how to use those
    double   tariff;      // TODO that too

public:

    /*
     * Constructor
     */
    Vehicle(unsigned int vehicleId, Manufacturer carManufacturer, Color color);

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
    Manufacturer getCarManufacturer() const;

    /*
     * Returns the color(enum) of the vehicle
     */
    Color getColor() const;

    /*
     * Returns the number of the maximum passenger capacity a vehicle can hold.
     */
    unsigned int getMaxCapacity() const;

    /*
     * Returns the vehicle tariff
     */
    double getTariff() const;

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
