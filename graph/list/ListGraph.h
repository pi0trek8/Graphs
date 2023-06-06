//
// Created by Piotr Szczypior on 13/05/2023.
//

#ifndef GRAPH_ALGORITHMS_LISTGRAPH_H
#define GRAPH_ALGORITHMS_LISTGRAPH_H


#include <list>
#include "node/Node.h"
#include "../../collections/DoubleList.h"

class ListGraph {
private:
    int vertices;
    list<Node> *nodes;
public:

    explicit ListGraph(int vertices);

    void add_undirected_edge(int source_vertex, int destination_vertex, int weight);

    void add_directed_edge(int source_vertex, int destination_vertex, int weight);

    int find_edge(int start_vertex, int stop_vertex);

    bool has_edge(int start_vertex, int stop_vertex);

    void display_adjacency_matrix();

    void display_adjacency_list();

    int get_vertices();

    list<Node> get_adjacent_vertices(int vertex);

    virtual ~ListGraph();

};


#endif //GRAPH_ALGORITHMS_LISTGRAPH_H
