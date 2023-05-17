//
// Created by Piotr Szczypior on 13/05/2023.
//

#include <climits>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices) {
    this->vertices = vertices;
    max_weight = INT_MAX;

    // Adjacency Matrix initialization with 0
    adjacencyMatrix = new Array<int>[vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i].push_back(0);
        }
    }

    adjacencyM = new Array<Node>[vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            Node node;
            adjacencyM[i].push_back(node);
        }
    }
}

void MatrixGraph::add_edge(int source_vertex, int destination_vertex, int weight) {
    adjacencyMatrix[source_vertex][destination_vertex] = weight;
    adjacencyMatrix[destination_vertex][source_vertex] = weight;
    Node node_v1(destination_vertex, weight);
    Node node_v2(source_vertex, weight);
    adjacencyM[source_vertex][destination_vertex] = node_v1;
    adjacencyM[destination_vertex][source_vertex] = node_v2;
    if (weight > max_weight) {
        max_weight = weight;
    }
}

void MatrixGraph::display_adjacency_matrix() {
    cout << "Adjacency Matrix:" << endl;

    cout << "   |";
    for(int i = 0; i < vertices; i++) {
        cout<< " " << i << " |";
    }
    cout << endl;
    for (int i = 0; i < vertices; i++) {
        cout << " " << i << " |";
        for (int j = 0; j < vertices; j++) {
            cout << " " << adjacencyMatrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void MatrixGraph::display_adjacency_list() {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < vertices; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                cout << j << "(" << adjacencyMatrix[i][j] << ") ";
            }
        }
        cout << endl;
    }
}

MatrixGraph::~MatrixGraph() {
    delete[] adjacencyMatrix;
}

int MatrixGraph::get_vertices() {
    return vertices;
}

bool MatrixGraph::has_edge(int start_vertex, int stop_vertex) {
    return adjacencyMatrix[start_vertex][stop_vertex] != 0;
}

int MatrixGraph::find_edge(int start_vertex, int stop_vertex) {
    return adjacencyMatrix[start_vertex][stop_vertex];
}

Array<int> MatrixGraph::get_adjacent_vertices(int vertex) {
    return adjacencyMatrix[vertex];
}
