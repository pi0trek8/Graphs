#include "ListGraph.h"

ListGraph::ListGraph(int vertices) : vertices(vertices) {
    this->vertices = vertices;
    nodes = new DoubleList<Node>[vertices];
}

void ListGraph::add_undirected_edge(int source_vertex, int destination_vertex, int weight) {
    if (source_vertex >= vertices || destination_vertex >= vertices) {
        return;
    }
    Node first_edge(destination_vertex, weight);
    nodes[source_vertex].push_back(first_edge);

    Node second_edge(source_vertex, weight);
    nodes[destination_vertex].push_back(second_edge);

}

void ListGraph::add_directed_edge(int source_vertex, int destination_vertex, int weight) {
    if (source_vertex >= vertices || destination_vertex >= vertices) {
        return;
    }
    Node node(destination_vertex, weight);
    nodes[source_vertex].push_back(node);
}

int ListGraph::find_edge(int start_vertex, int stop_vertex) {
    if(start_vertex == stop_vertex) {
        return 0;
    }

    auto adjacent_vertices = nodes[start_vertex];
    for(int i = 0; i < adjacent_vertices.get_size(); i++) {
        if(adjacent_vertices[i].vertex ==  stop_vertex){
            return adjacent_vertices[i].weight;
        }
    }

    return 0;
}

ListGraph::~ListGraph() {
    delete[] nodes;
}

void ListGraph::display_adjacency_matrix() {
    cout << "Adjacency Matrix:" << endl;

    cout << "   |";
    for (int i = 0; i < vertices; i++) {
        cout << " " << i << " |";
    }
    cout << endl;
    for (int i = 0; i < vertices; i++) {
        int j = 0;
        cout << " " << i << " |";
        for (auto node: nodes[i]) {
            j++;
            cout << " " << node.weight << "  ";
        }
        for (j; j < vertices; j++) {
            cout << " 0  ";
        }
        cout << endl;
    }
}


void ListGraph::display_adjacency_list() {

    cout << "Adjacency List: (vertex, weight)" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        for (auto node: nodes[i]) {
            if (node.weight != 0) {
                cout << "(" << node.vertex << ", " << node.weight << ") ";
            }
        }
        cout << endl;
    }
}

DoubleList<Node> &ListGraph::get_adjacent_vertices(int vertex) {
    return nodes[vertex];
}

int ListGraph::get_vertices() {
    return vertices;
}

bool ListGraph::has_edge(int start_vertex, int stop_vertex) {
    for (auto node: nodes[start_vertex]) {
        if (node.vertex == stop_vertex) {
            return true;
        }
    }
    return false;
}
