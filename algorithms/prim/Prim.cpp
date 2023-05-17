#include "Prim.h"
#include "../../graph/list/ListGraph.h"
#include "../../graph/matrix/MatrixGraph.h"

template<class G>
int Prim::process(G *graph, int start_vertex) {
    weights.clear();
    connections.clear();

    int _mst_weight = 0;

    for (int i = 0; i < graph->get_vertices(); i++) {
        weights.push_back(INT_MAX);
        connections.push_back(-1);
    }
    weights[start_vertex] = 0;

    for (int i = 0; i < graph->get_vertices(); i++) {
        PriorityQueueNode node(i, weights[i]);
        priority_queue.push_back(node);
    }

    while (priority_queue.get_size() > 0) {
        auto _vertex = extract_min();

//        priority_queue.print();
        if constexpr (std::is_same_v<G, MatrixGraph>) {
            for (int j = 0; j < graph->get_vertices(); j++) {
                int weight = graph->find_edge(_vertex, j);
                if (weight != 0) {
                    PriorityQueueNode node(j, weights[j]);
                    if (priority_queue.find(node) && weight < weights[j]) {
                        weights[j] = weight;
                        _mst_weight += weight;
                        connections[j] = _vertex;

                        Edge edge(_vertex, j, weight);
                        mst_edges.push_back(edge);
                    }
                }
            }
        } else if constexpr (std::is_same_v<G, ListGraph>) {
            for (const auto &node: graph->get_adjacent_vertices(_vertex)) {
                PriorityQueueNode n(node.vertex, weights[node.vertex]);
                if (priority_queue.find(n) &&
                    node.weight < weights[node.vertex]) {
//                    PriorityQueueNode node_to_update(node.vertex, weights[node.vertex]);
//                    PriorityQueueNode new_node(node.vertex, node.weight);
//                    priority_queue.set(node_to_update, new_node);
                    weights[node.vertex] = node.weight;
                    _mst_weight += node.weight;
                    connections[node.vertex] = _vertex;

                    Edge edge(_vertex, node.vertex, node.weight);
                    mst_edges.push_back(edge);
                }
            }
        }
        priority_queue.pop_front();
    }

    return _mst_weight;
}

template int Prim::process<ListGraph>(ListGraph *graph, int start_vertex);
template int Prim::process<MatrixGraph>(MatrixGraph *graph, int start_vertex);

void Prim::display_mst() {
    cout << "Minimum Spanning Tree Edges:\n";
    for(const auto edge : mst_edges) {
        cout << edge.start << " - weight(" << edge.weight << ") - " << edge.end << endl;
    }
}

int Prim::extract_min() {
    for (int i = 0; i < priority_queue.get_size() - 1; i++) {
        for (int j = 0; j < priority_queue.get_size() - i - 1; j++) {
            if (priority_queue[j] > priority_queue[j + 1]) {
                priority_queue.swap(j, j + 1);
            }
        }
    }

    return priority_queue[0].vertex;
}
