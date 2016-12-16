
#include <iostream>
#include <gtest/gtest.h>
#include "../src/Grid.h"
#include "../src/Bfs.h"

class BfsTest : public :: testing::Test {

protected:

    Graph *graph;
    std::vector<Point> obstacles;

public:

    virtual void SetUp(){


            Graph *graph = new Grid(3, 2, obstacles);
    };

    virtual void TearDown(){

            delete graph;

    };

};

TEST_F(BfsTest, basicTests){

    // Init params
    Point startPt(0, 0);
    Point endPt(1, 1);
    Bfs bfs(graph, startPt, endPt);

    // Builds the shortest path
    bfs.get_route();

    // TODO: Check if necessary to check
    testing::internal::CaptureStdout();
    std::cout << "(0, 0)\n (0, 1)\n (1, 1)";
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(bfs.print_points() == output.compare());

}