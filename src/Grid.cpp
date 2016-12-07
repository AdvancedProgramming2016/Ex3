
#include "Grid.h"

Grid::Grid(int length, int width) : m_length(length), m_width(width) {

    m_edges.reserve(length * width);

    for (int i = length - 1; i >= 0; i--) {

        for (int j = 0; j < width; ++j) {

            Vertex v = Vertex(Point(i, j));
            v.set_relations_num(4);
            m_edges.push_back(v);
        }
    }

    build_relations();

}

void Grid::build_relations() {

    int counter = 0;

    for (int i = m_length - 1; i >= 0; i--) {

        for (int j = 0; j < m_width; ++j) {

            if (j < m_width - 1) {

                m_edges.at(counter).add_relation(*get_vertex(Point(i, j + 1))); //right relationship
            }

            if (i > 0) {

                m_edges.at(counter).add_relation(*get_vertex(Point(i - 1, j))); //upper relationship
            }

            if (j > 0) {

                m_edges.at(counter).add_relation(*get_vertex(Point(i, j - 1))); //left relationship
            }


            if (i < m_length - 1) {


                m_edges.at(counter).add_relation(*get_vertex(Point(i + 1, j))); //lower relationship
            }

            counter++;
        }
    }

}
