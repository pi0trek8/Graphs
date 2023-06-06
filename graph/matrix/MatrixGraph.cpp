#include <climits>
#include "MatrixGraph.h"
#include <iomanip>

MatrixGraph::MatrixGraph(int vertices, int edges) {
    this->vertices = vertices;
    this->edges = edges;

    // Adjacency Matrix initialization with 0
    incidenceMatrix = new Array<int>[vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            incidenceMatrix[i].push_back(0);
        }
    }
}

void MatrixGraph::add_undirected_edge(int edge, int source_vertex, int destination_vertex, int weight) {
    incidenceMatrix[source_vertex][edge] = weight;
    incidenceMatrix[destination_vertex][edge] = weight;
}


void MatrixGraph::add_directed_edge(int edge, int source_vertex, int destination_vertex, int weight) {
    incidenceMatrix[source_vertex][edge] = weight;
    incidenceMatrix[destination_vertex][edge] = -weight;
}

void MatrixGraph::display_adjacency_matrix() {
    cout << "Incidence Matrix:" << endl;

    cout << "   |";
    for (int i = 0; i < edges; i++) {
        cout << setw(3) << i << " |";
    }
    cout << endl;

    cout << "----";
    for (int i = 0; i < edges; i++) {
        cout << "-----";
    }
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        cout << setw(2) << i << " |";
        for (int j = 0; j < edges; j++) {
            cout << setw(4) << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


int MatrixGraph::get_vertices() {
    return vertices;
}

bool MatrixGraph::has_edge(int start_vertex, int stop_vertex) {
    return incidenceMatrix[start_vertex][stop_vertex] != 0;
}

int MatrixGraph::find_edge(int start_vertex, int stop_vertex) {
    if (start_vertex == stop_vertex) {
        return 0;
    }

    for (int i = 0; i < edges; i++) {
        if (incidenceMatrix[stop_vertex][i] == 0 && incidenceMatrix[start_vertex][i] == 0 ||
            incidenceMatrix[start_vertex][i] < 0) {
            continue;
        }
        if (abs(incidenceMatrix[start_vertex][i]) == abs(incidenceMatrix[stop_vertex][i]))
            return incidenceMatrix[start_vertex][i];
    }
    return 0;
}

Array<int> MatrixGraph::get_adjacent_vertices(int vertex) {
    return incidenceMatrix[vertex];
}

MatrixGraph::~MatrixGraph() {
    delete[] incidenceMatrix;
}

//void MatrixGraph::display_adjacency_list() {
//    cout << "Adjacency List: (vertex, weight)" << endl;
//    for (int i = 0; i < vertices; i++) {
//        cout << "Vertex " << i << ": ";
//        for (int j = 0; j < vertices; j++) {
//            if (adjacencyMatrix[i][j] != 0) {
//                cout << j << "(" << adjacencyMatrix[i][j] << ") ";
//            }
//        }
//        cout << endl;
//    }
//}
