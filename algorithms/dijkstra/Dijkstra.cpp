#include "Dijkstra.h"
#include <climits>

template<class G>
int Dijkstra::process(G *graph, int start_vertex, int stop_vertex) {
    distances.clear(); // Clear the distances vector
    predecessors.clear(); // Clear the predecessors vector
    priority_queue.clear(); // Clear the priority queue

    // Initialize distances and predecessors vectors with default values
    for (int i = 0; i < graph->get_vertices(); i++) {
        distances.push_back(INT_MAX);
        predecessors.push_back(-1);
    }
    distances[start_vertex] = 0; // Set the distance of the start vertex to 0

    // Push all vertices into the priority queue with their corresponding distances
    for (int i = 0; i < graph->get_vertices(); i++) {
        PriorityQueueNode node(i, distances[i]);
        priority_queue.push(node);
    }

    while (!priority_queue.isEmpty()) {
        auto examined_node = priority_queue.get_top(); // Get the top node from the priority queue
        auto examined_vertex = examined_node.vertex;
        priority_queue.pop(); // Remove the top node from the priority queue

        if constexpr (std::is_same_v<G, MatrixGraph>) {
            // Process edges for MatrixGraph
            for (int vertex = 0; vertex < graph->get_vertices(); ++vertex) {
                int weight = graph->find_edge(examined_vertex, vertex);

                if (weight != 0) {
                    if (distances[examined_vertex] + weight < distances[vertex] &&
                        distances[examined_vertex] != INT_MAX) {
                        int old_distance = distances[vertex];

                        distances[vertex] = distances[examined_vertex] + weight;
                        predecessors[vertex] = examined_vertex;

                        PriorityQueueNode old_node(vertex, old_distance);
                        PriorityQueueNode updated_node(vertex, distances[vertex]);
                        priority_queue.set(examined_node, updated_node);
                    }
                }
            }
        } else if constexpr (std::is_same_v<G, ListGraph>) {
            // Process edges for ListGraph
            for (const auto &node: graph->get_adjacent_vertices(examined_vertex)) {
                int weight = node.weight;
                int vertex = node.vertex;
                if (distances[examined_vertex] + weight < distances[vertex] && distances[examined_vertex] != INT_MAX) {
                    int old_distance = distances[vertex];
                    distances[vertex] = distances[examined_vertex] + weight;
                    predecessors[vertex] = examined_vertex;

                    PriorityQueueNode old_node(vertex, old_distance);
                    PriorityQueueNode updated_node(vertex, distances[vertex]);
                    priority_queue.set(old_node, updated_node);
                }
            }
        }
    }

    return distances[stop_vertex]; // Return the distance to the stop vertex
}

void Dijkstra::get_path(int start_vertex, int stop_vertex) {
    if (distances.get_size() == 0) {
        return;
    }
    Array<int> shortest_path;
    int current_vertex = stop_vertex;
    while (current_vertex != start_vertex) {
        if (current_vertex == -1) {
            cout << "Path has not been found!" << endl;
            return;
        }
        shortest_path.push_front(current_vertex);
        current_vertex = predecessors[current_vertex];
    }
    shortest_path.push_front(start_vertex);

    cout << "Path: " << endl;
    for (const auto vertex: shortest_path) {
        if (vertex != stop_vertex)
            cout << vertex << " -> ";
        else
            cout << vertex;
    }
    cout << endl;
}

int Dijkstra::get_weight(DoubleList<Node> adjacent_nodes, int stop_vertex) {
    adjacent_nodes.print();
    for (const auto &node: adjacent_nodes) {
        if (node.vertex == stop_vertex) {
            return node.weight;
        }
    }
    return 0;
}


template int Dijkstra::process<ListGraph>(ListGraph *graph, int start_vertex, int stop_vertex);

template int Dijkstra::process<MatrixGraph>(MatrixGraph *graph, int start_vertex, int stop_vertex);

