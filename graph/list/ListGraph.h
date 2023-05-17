//
// Created by Piotr Szczypior on 13/05/2023.
//

#ifndef GRAPH_ALGORITHMS_LISTGRAPH_H
#define GRAPH_ALGORITHMS_LISTGRAPH_H


#include "node/Node.h"
#include "../../collections/DoubleList.h"

class ListGraph {
    int vertices;
    //TODO: może lista list zamiast tablicy list
    DoubleList<Node> *nodes;
public:

    explicit ListGraph(int vertices);

    void add_edge(int source_vertex, int destination_vertex, int weight);

    int find_edge(int start_vertex, int stop_vertex);

    bool has_edge(int start_vertex, int stop_vertex);

    void display_adjacency_matrix();

    void display_adjacency_list();

    int get_vertices();

    DoubleList<Node>& get_adjacent_vertices(int vertex);

    void read_from_file();

    void create_random(int density, int vertices);

    virtual ~ListGraph();

};


#endif //GRAPH_ALGORITHMS_LISTGRAPH_H
