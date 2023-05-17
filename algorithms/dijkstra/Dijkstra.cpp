#include "Dijkstra.h"

template<class G>
int Dijkstra::process(G *graph, int start_vertex, int stop_vertex) {
    distances.clear();
    predecessors.clear();
    priority_queue.clear();

    for(int i = 0 ; i < graph->get_vertices(); i++) {
        distances.push_back(INT_MAX);
        predecessors.push_back(INT_MAX);
    }
    distances[start_vertex] = 0;
    PriorityQueueNode node(start_vertex, 0);
    priority_queue.push(node);

    while(!priority_queue.isEmpty()) {
        auto v  = priority_queue.get_top().vertex;
        priority_queue.pop();

        for (int vertex = 0; vertex < graph->get_vertices(); ++vertex) {
            if (graph->has_edge(v, vertex)) {
                int weight = graph->find_edge(v, vertex);
                if (distances[v] + weight < distances[vertex]) {
                    distances[vertex] = distances[v] + weight;
                    predecessors[vertex] = v;
                    PriorityQueueNode pr_node(vertex, distances[vertex]);
                    priority_queue.push(pr_node);
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
