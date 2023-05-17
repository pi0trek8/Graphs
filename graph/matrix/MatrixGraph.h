#ifndef GRAPH_ALGORITHMS_MATRIXGRAPH_H
#define GRAPH_ALGORITHMS_MATRIXGRAPH_H

#include <iostream>
#include "../../collections/Array.h"
#include "../list/node/Node.h"

using namespace std;

class MatrixGraph {
private:
    int vertices;
    Array<int> *adjacencyMatrix;
    Array<Node> *adjacencyM;

    int max_weight;

public:
    explicit MatrixGraph(int vertices);

    void add_edge(int source_vertex, int destination_vertex, int weight);

    void display_adjacency_matrix();

    bool has_edge(int start_vertex, int stop_vertex);

    int find_edge(int start_vertex, int stop_vertex);

    int get_vertices();

    Array<int> get_adjacent_vertices(int vertex);

    void display_adjacency_list();

    void read_from_file();

    void create_random(int density, int vertices);

    ~MatrixGraph();
};

#endif //GRAPH_ALGORITHMS_MATRIXGRAPH_H
