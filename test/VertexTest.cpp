

#include <gtest/gtest.h>
#include <iostream>
#include "../src/Vertex.h"

class VertexTest: public :: testing::Test {

protected:

    Vertex *vtx1;
    Vertex *vtx2;
    Vertex *vtx3;

public:

    virtual void SetUp() {

        Vertex *vtx1 = new Vertex(Point(5, 7));
        Vertex *vtx2 = new Vertex(Point(4, 7));
        Vertex *vtx3 = new Vertex(Point(6, 7));

    }

    virtual void TearDown() {

        delete vtx1;
        delete vtx2;
        delete vtx3;

    }

};

TEST_F(VertexTest, basicTest) {

    // Verify constructor inserts default params
    EXPECT_TRUE(vtx1->getNum_of_relations() == 0);
    EXPECT_TRUE(vtx1->getFather() == 0);

    // Check point getter
    EXPECT_TRUE(vtx1->getM_point() == Point(5,7));

    // Check add_relation and getNum_of_relations function

    vtx1->add_relation(*vtx2);
    EXPECT_TRUE(vtx1->getNum_of_relations() == 1);
    EXPECT_FALSE(vtx1->getNum_of_relations() == 2);

    // Check getM_relations_list returns vector in the anticipated size
    std::vector<Vertex *> vertex1;
    vertex1 = vtx1->getM_relations_list();
    EXPECT_TRUE(vertex1.size() == 2);

    // Checks that the node wasn't visited yet
    EXPECT_FALSE(vtx1->isM_is_visited());

    // Checks that set_visited function sets m_is_visited to true
    vtx1->set_visited();
    EXPECT_TRUE(vtx1->isM_is_visited());

}
