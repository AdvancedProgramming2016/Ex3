
#include <gtest/gtest.h>
#include <vector>
#include "../src/Grid.h"


TEST(VertexTest, basicVertexTest) {

    // Init params
    std::vector<Point> obstacles;
    Graph *graph = new Grid(6, 5, obstacles);

    Vertex *vtx1 = graph->get_vertex(Point(2,3));
    Vertex *vtx2 = graph->get_vertex(Point(0,0));

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
