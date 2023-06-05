#include "Dijkstra.h"
#include <climits>

int Dijkstra::findMinDistanceVertex() {
    int minimum_distance = INT_MAX;
    int min_vertex_index = -1;

    for (int vertex = 0; vertex < distances.get_size(); ++vertex) {
        if (!visited[vertex] && distances[vertex] < minimum_distance) {
            minimum_distance = distances[vertex];
            min_vertex_index = vertex;
        }
    }

    return min_vertex_index;
}


template<class G>
int Dijkstra::process(G *graph, int start_vertex, int stop_vertex) {
    // Initialize distances and predecessors vectors with default values
    for (int i = 0; i < graph->get_vertices(); i++) {
        distances.push_back(INT_MAX);
        predecessors.push_back(-1);
        visited.push_back(false);
    }
    distances[start_vertex] = 0; // Set the distance of the start vertex to 0

    for (int i = 0; i < graph->get_vertices() - 1; i++) {
        int examined_vertex = findMinDistanceVertex();
        if (examined_vertex == -1)
            break;

        visited[examined_vertex] = true;

        if constexpr (std::is_same_v<G, MatrixGraph>) {
            for (int vertex = 0; vertex < graph->get_vertices(); vertex++) {
                int weight = graph->find_edge(examined_vertex, vertex);

                if (weight != 0) {
                    if (distances[examined_vertex] + weight < distances[vertex] &&
                        distances[examined_vertex] != INT_MAX) {
                        distances[vertex] = distances[examined_vertex] + weight;
                        predecessors[vertex] = examined_vertex;
                    }
                }
            }
        } else if constexpr (std::is_same_v<G, ListGraph>) {
            for (auto const &node: graph->get_adjacent_vertices(examined_vertex)) {
                int weight = node.weight;
                int vertex = node.vertex;
                if (distances[examined_vertex] + weight < distances[vertex] && distances[examined_vertex] != INT_MAX) {
                    distances[vertex] = distances[examined_vertex] + weight;
                    predecessors[vertex] = examined_vertex;

                }
            }
        }
    }
    return distances[stop_vertex];
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


template int Dijkstra::process<ListGraph>(ListGraph *graph, int start_vertex, int stop_vertex);

template int Dijkstra::process<MatrixGraph>(MatrixGraph *graph, int start_vertex, int stop_vertex);