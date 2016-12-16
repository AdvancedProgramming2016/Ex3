
#include "Menu.h"
#include "Driver.h"

Menu::Menu() {

}

MainFlow Menu::getMainFlow() {
    return this->mainFlow;
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

    while (userOption < 7) {

        std::cin >> userOption;

        switch (userOption) {

            // Create driver
            case 1:
                this->getMainFlow().getTaxiCenter()->addDriver(
                        this->stringParser.parseDriverInput());
                break;

                // Create trip
            case 2:
                this->getMainFlow().getTaxiCenter()->addTrip(
                        this->stringParser.parseTripInput());
                break;

                // Create vehicle
            case 3:
                this->getMainFlow().getTaxiCenter()->addVehicle(
                        this->stringParser.parseVehicleInput());
                break;

                // Request for driver location
            case 4:
                this->getMainFlow().getTaxiCenter()->requestDriverLocation(
                        this->stringParser.parseDriverLocation());
                break;

                // Start Driving
            case 6:
                this->getMainFlow().startDriving();
                break;

            case 7:
                this->getMainFlow().exitSystem();

                // Invalid input
            default:
                exit(1);

        }

    }

}
