#include <iostream>
//#include <gtest/gtest.h>
//#include <gmock/gmock.h>
#include "src/BaseParser.h"
#include "src/Menu.h"

int main(int argc, char *argv[]) {

    Menu menu;
    menu.initializeGame();
    menu.runMenu();


    /*
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    */

    return 0;
}