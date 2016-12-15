//
// Created by commanderx on 07/12/16.
//

#include "Menu.h"
#include "Menu.h"
#include "Driver.h"

Menu::Menu(TaxiCenter *taxiCenter) {
    this->taxiCenter = taxiCenter;
}

MainFlow Menu::getMainFlow() {
    return this->mainFlow;
}

TaxiCenter *Menu::getTaxiCenter() {
    return this->taxiCenter;
}

int Menu::initializeGame() {

    //Create Grid with obstacles.
    this->stringParser.parseGridInput();
}

int checkUserInput(int userSelection) {

    if (userSelection > 7) {
        return 1;
    }
    return 0;
}

int Menu::runMenu() {

    int userOption = 0;

    do {

        std::cin >> userOption;

        switch (userOption) {

            // Create driver
            case 1:
                this->getTaxiCenter()->addDriver(
                        this->stringParser.parseDriverInput());
                break;

                // Create trip
            case 2:
                this->getTaxiCenter()->addTrip(
                        this->stringParser.parseTripInput());
                break;

                // Create vehicle
            case 3:
                this->getTaxiCenter()->addVehicle(
                        this->stringParser.parseVehicleInput());
                break;

                // Request for driver location
            case 4:
                break;

                // Start Driving
            case 6:
                this->getMainFlow().startDriving();
                break;

            case 7:
                delete this->getMainFlow();
                exit(1);

                // Invalid input
            default:
                exit(1);

        }

    } while (userOption < 7);

}

