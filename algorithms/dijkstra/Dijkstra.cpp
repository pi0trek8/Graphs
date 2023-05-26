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
        if constexpr (std::is_same_v<G, MatrixGraph>) {
            for (int vertex = 0; vertex < graph->get_vertices(); ++vertex) {
                int weight = graph->find_edge(examined_vertex, vertex);

                if (weight != 0) {
                    if (distances[examined_vertex] + weight < distances[vertex] && distances[examined_vertex] != INT_MAX) {
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
            for(const auto& node : graph->get_adjacent_vertices(examined_vertex)) {
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



//
//template<class G>
//int Dijkstra::process(G *graph, int start_vertex, int stop_vertex) {
//    distances.clear();
//    predecessors.clear();
//    priority_queue.clear();
//
//    for (int i = 0; i < graph->get_vertices(); i++) {
//        distances.push_back(INT_MAX);
//        predecessors.push_back(-1);
//    }
//    distances[start_vertex] = 0;
//
//    for (int i = 0; i < graph->get_vertices(); i++) {
//        PriorityQueueNode node(i, distances[i]);
//        priority_queue.push(node);
//    }
//
//    while (!priority_queue.isEmpty()) {
//        auto examined_node = priority_queue.get_top();
//        auto examined_vertex = examined_node.vertex;
//        priority_queue.pop();
//        if constexpr (std::is_same_v<G, MatrixGraph>) {
//            for (int vertex = 0; vertex < graph->get_vertices(); ++vertex) {
//                int weight = graph->find_edge(examined_vertex, vertex);
//
//
//                if (weight != 0) {
//                    if (distances[examined_vertex] + weight < distances[vertex]) {
//
//                        distances[vertex] = distances[examined_vertex] + weight;
//                        predecessors[vertex] = examined_vertex;
//
//                        PriorityQueueNode updated_node(vertex, distances[vertex]);
//                        priority_queue.set(examined_node, updated_node);
//                    }
//                }
//            }
//        } else if constexpr (std::is_same_v<G, ListGraph>) {
//            for(const auto& node : graph->get_adjacent_vertices(examined_vertex)) {
//                int weight = node.weight;
//                int vertex = node.vertex;
//                if (distances[examined_vertex] + weight < distances[vertex]) {
//
//                    distances[vertex] = distances[examined_vertex] + weight;
//                    predecessors[vertex] = examined_vertex;
//
//                    PriorityQueueNode updated_node(vertex, distances[vertex]);
//                    priority_queue.set(examined_node, updated_node);
//                }
//            }
//        }
//    }
//
//    return distances[stop_vertex];
//}

