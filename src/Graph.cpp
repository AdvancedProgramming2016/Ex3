
#include "Graph.h"

Graph::Graph() {

}

std::vector<Vertex> Graph::get_edges() {
    return m_edges;
}

Vertex *Graph::get_vertex(Point point) {

    for (int i = 0; i < m_edges.size(); ++i) {

        if (m_edges.at(i).getM_point() == point) {
            return &m_edges.at(i);
        }
    }

    return 0;
}



