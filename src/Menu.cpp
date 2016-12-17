
#include "Menu.h"
#include "Driver.h"

Menu::Menu() {

}

MainFlow *Menu::getMainFlow() {
    return this->mainFlow;
}

int Menu::initializeGame() {

    //Create Grid with obstacles.
    this->getMainFlow()->createMap(
            this->stringParser.parseGridInput());
    this->getMainFlow()->createTaxiCenter(new Point(0,0));
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
                this->getMainFlow()->createDriver(
                        this->stringParser.parseDriverInput());
                break;

                // Create trip
            case 2:
                this->getMainFlow()->createTrip(
                        this->stringParser.parseTripInput());
                break;

                // Create vehicle
            case 3:
                this->getMainFlow()->createVehicle(
                        this->stringParser.parseVehicleInput());
                break;

                // Request for driver location
            case 4:
                this->getMainFlow()->getTaxiCenter()->requestDriverLocation(//TODO this method should be in mainFlow like the rest above.
                        this->stringParser.parseDriverLocation());
                break;

                // Start Driving
            case 6:
                this->getMainFlow()->startDriving();
                break;

            case 7:
                this->getMainFlow()->exitSystem();

                // Invalid input
            default:
                exit(1);

        }

    }

}
