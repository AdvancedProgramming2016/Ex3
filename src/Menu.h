//
// Created by commanderx on 07/12/16.
//

#ifndef EX2_CHECK_MENU_H
#define EX2_CHECK_MENU_H


#include "Driver.h"

class Menu {

public:

    int checkUserInput(std::string userSelection);
    int runMenu();
    void createDriver(unsigned int id, unsigned int age, MaritalStatus status, unsigned int experience, int vehicleId);

};


#endif //EX2_CHECK_MENU_H
