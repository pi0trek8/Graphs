#include "Dijkstra.h"

template<class G>
int Dijkstra::process(G *graph, int start_vertex, int stop_vertex) {
    distances.clear();
    predecessors.clear();
    priority_queue.clear();

    for (int i = 0; i < graph->get_vertices(); i++) {
        distances.push_back(INT_MAX);
        predecessors.push_back(-1);
    }
    distances[start_vertex] = 0;

    for (int i = 0; i < graph->get_vertices(); i++) {
        PriorityQueueNode node(i, distances[i]);
        priority_queue.push(node);
    }

    while (!priority_queue.isEmpty()) {
        auto examined_node = priority_queue.get_top();
        auto examined_vertex = examined_node.vertex;
        priority_queue.pop();

        for (int vertex = 0; vertex < graph->get_vertices(); ++vertex) {
            if (graph->find_edge(examined_vertex, vertex) != 0) {
                int weight = graph->find_edge(examined_vertex, vertex);
                if (distances[examined_vertex] + weight < distances[vertex]) {

                    distances[vertex] = distances[examined_vertex] + weight;
                    predecessors[vertex] = examined_vertex;

                    PriorityQueueNode updated_node(vertex, distances[vertex]);
                    priority_queue.set(examined_node, updated_node);
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

    for (const auto vertex: shortest_path) {
        cout << vertex << " ";
    }
    cout << endl;
}


template int Dijkstra::process<ListGraph>(ListGraph *graph, int start_vertex, int stop_vertex);

template int Dijkstra::process<MatrixGraph>(MatrixGraph *graph, int start_vertex, int stop_vertex);
