#ifndef GRAPH_ALGORITHMS_MATRIXGRAPH_H
#define GRAPH_ALGORITHMS_MATRIXGRAPH_H

#include <iostream>
#include "../../collections/Array.h"
#include "../list/node/Node.h"

using namespace std;

class MatrixGraph {
private:
    int edges;
    int vertices;
    Array<int> *incidenceMatrix;

public:
    explicit MatrixGraph(int vertices, int edges);

    void add_undirected_edge(int edge, int source_vertex, int destination_vertex, int weight);

    void add_directed_edge(int edge, int source_vertex, int destination_vertex, int weight);

    void display_adjacency_matrix();

    bool has_edge(int start_vertex, int stop_vertex);

    int find_edge(int start_vertex, int stop_vertex);

    int get_vertices();

    Array<int> get_adjacent_vertices(int vertex);

    void display_adjacency_list();

    ~MatrixGraph();
};

#endif //GRAPH_ALGORITHMS_MATRIXGRAPH_H
