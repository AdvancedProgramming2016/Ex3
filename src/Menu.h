

#ifndef EX2_CHECK_MENU_H
#define EX2_CHECK_MENU_H

#include "StringParser.h"
#include "MainFlow.h"

class Menu {

private:
    StringParser stringParser;
    MainFlow mainFlow;

public:

    int initializeGame();
    int checkUserInput(int userSelection);
    int runMenu();
    //TaxiCenter *getTaxiCenter();
    MainFlow getMainFlow();

};


#endif //EX2_CHECK_MENU_H
