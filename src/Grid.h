
#ifndef EX1_TASK2_GRID_H
#define EX1_TASK2_GRID_H

#include "Graph.h"

/**
 * The class represents a 2D grid.
 * It inherits from the Graph class.
 */
class Grid : public Graph {

private:
    int       m_length;
    int       m_width;

    /*
     * The method builds the relations between the cells of the grid.
     */
    void build_relations();

public:

    /*
     * Constructor which receives the size of the matrix.
     */
    Grid(int length, int width);

};


#endif //EX1_TASK2_GRID_H
