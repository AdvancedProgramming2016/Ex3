
#include <iostream>
#include <gtest/gtest.h>
#include "../src/Grid.h"

/**
 * Checks getters of the Grid object
 */
TEST(GridTest, basicTest) {

    // Check constructor creates a grid with all the relations
    std::vector<Point> obstacles;

    Grid grid(4, 5, obstacles);
    Point pt1(3, 2);
    Point cornerPt(3, 4);

    // Check validity of initialization of the grid
    Vertex *vtx1 = grid.get_vertex(pt1);
    EXPECT_TRUE(vtx1->getM_point() == pt1);

    // Check that corner point was created
    Vertex *vtx2 = grid.get_vertex(cornerPt);
    EXPECT_TRUE(vtx2->getM_point() == cornerPt);

}