
#include <iostream>
#include <gtest/gtest.h>
#include "../src/Grid.h"
#include "../src/Bfs.h"

TEST(BfsTest, basicTests){

    // Init params
    std::vector<Point> obstacles;
    Graph *graph = new Grid(5, 5, obstacles);
    Point startPt(0, 0);
    Point endPt(1, 1);
    Bfs bfs(graph, startPt, endPt);

    // Builds the shortest path
    bfs.get_route();

    testing::internal::CaptureStdout();
    std::cout << "(0,0)\n(0,1)\n(1,1)";
    std::string validOutput = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    bfs.print_points();
    std::string output = testing::internal::GetCapturedStdout();

    //Check that the outputs are equal.
    EXPECT_TRUE(strcmp(validOutput.c_str(), output.c_str()));
    delete graph;
}