
#include <gtest/gtest.h>
#include <iostream>
#include "../src/Vertex.h"
#include "../src/Graph.h"
#include "../src/Grid.h"

class VertexTest: public :: testing::Test {

};

TEST_F(VertexTest, basicTest) {

    std::vector<Point> obstacles;
    Graph *graph = new Grid(5, 6, obstacles);

    Vertex *vtx1 = graph->get_vertex(Point(2,3));
    Vertex *vtx2 = graph->get_vertex(Point(4,5));

    // Check point getter
    EXPECT_TRUE(vtx1->getM_point() == Point(2,3));

    // Check get Num relations
    EXPECT_TRUE(vtx1->getNum_of_relations() == 4);

    // Checks that the node wasn't visited yet
    EXPECT_FALSE(vtx1->isM_is_visited());

    // Expect only 2 relations
    EXPECT_TRUE(vtx2->getNum_of_relations() == 2);

    delete graph;
    
}
