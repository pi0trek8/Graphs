#include "Prim.h"
#include "../../graph/list/ListGraph.h"
#include "../../graph/matrix/MatrixGraph.h"
#include "../../dto/edge/Edge.h"
#include <climits>

template<class G>
void Prim::process(G *graph, int start_vertex) {
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
        priority_queue.push(node);
    }

    while (!priority_queue.isEmpty()) {
        auto lowest_weight_edge =  priority_queue.get_top();
        priority_queue.pop();

        if constexpr (std::is_same_v<G, MatrixGraph>) {
            for (int j = 0; j < graph->get_vertices(); j++) {
                int weight = graph->find_edge(lowest_weight_edge.vertex, j);
                if (weight != 0) {
                    PriorityQueueNode node(j, weights[j]);
                    if (priority_queue.find(node) && weight < weights[j]) {
                        weights[j] = weight;
                        connections[j] = lowest_weight_edge.vertex;
                        PriorityQueueNode n(j, weight);
                        priority_queue.set(node, n);
                    }
                }
            }
        } else if constexpr (std::is_same_v<G, ListGraph>) {
            for (const auto &node: graph->get_adjacent_vertices(lowest_weight_edge.vertex)) {
                PriorityQueueNode n(node.vertex, weights[node.vertex]);
                if (priority_queue.find(n) &&
                    node.weight < weights[node.vertex]) {
                    weights[node.vertex] = node.weight;
                    connections[node.vertex] = lowest_weight_edge.vertex;
                    PriorityQueueNode new_node(node.vertex, node.weight);
                    priority_queue.set(n, new_node);
                }
            }
        }
    }
}

template void Prim::process<ListGraph>(ListGraph *graph, int start_vertex);
template void Prim::process<MatrixGraph>(MatrixGraph *graph, int start_vertex);

void Prim::display_mst() {
    Array<Edge> mst_edges;
    int mst_weight = 0;
    for (int i = 1; i < connections.get_size(); i++) {
        if (connections[i] != -1) {
            int weight = weights[i];
            mst_weight += weights[i];
            int sourceVertex = connections[i];
            int destinationVertex = i;
            Edge edge(sourceVertex, destinationVertex, weight);
            mst_edges.push_back(edge);
        }
    }
    cout << "MST weight: " << mst_weight << endl;

    cout << "Minimum Spanning Tree Edges:\n";
    for(const auto edge : mst_edges) {
        cout << edge.start << " - weight(" << edge.weight << ") - " << edge.end << endl;
    }
}

