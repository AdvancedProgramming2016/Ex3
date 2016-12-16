

#ifndef EX2_CHECK_MENU_H
#define EX2_CHECK_MENU_H


#include "Driver.h"
#include "StringParser.h"
#include "MainFlow.h"

class Menu {

private:
    StringParser stringParser;
    MainFlow mainFlow;
    TaxiCenter *taxiCenter;

public:

    Menu(TaxiCenter *taxiCenter);
    int initializeGame();
    int checkUserInput(int userSelection);
    int runMenu();
    MainFlow getMainFlow();

};


#endif //EX2_CHECK_MENU_H
