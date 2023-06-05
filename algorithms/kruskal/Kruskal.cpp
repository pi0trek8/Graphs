#include "Kruskal.h"
#include "../../graph/list/ListGraph.h"
#include "../../graph/matrix/MatrixGraph.h"


template<class G>
int Kruskal::process(G *graph, int start_vertex) {
    for (int i = 0; i < graph->get_vertices(); i++) {
        parents.push_back(i); // Initialize parents vector with default values
        ranks.push_back(1); // Initialize ranks vector with default values
    }
    int mst_value = 0; // Initialize the minimum spanning tree value to 0
    int num_edges_in_mst = 0; // Initialize the number of edges in the minimum spanning tree to 0

    if constexpr (std::is_same_v<G, MatrixGraph>) {
        int diagonal = 1;
        for (int i = 0; i < graph->get_vertices(); i++) {
            for (int j = 0; j < diagonal; j++) {
                int weight = graph->find_edge(i, j);
                if (weight != 0) {
                    Edge edge(i, j, weight); // Create an edge object
                    edges.push_back(edge); // Add the edge to the edges vector
                }
            }
            diagonal++;
        }

    } else if constexpr (std::is_same_v<G, ListGraph>) {
        for (int i = 0; i < graph->get_vertices(); i++) {
            for (auto node: graph->get_adjacent_vertices(i)) {
                Edge edge(i, node.vertex, node.weight); // Create an edge object
                edges.push_back(edge); // Add the edge to the edges vector
            }
        }
    }
    this->sort_edges(); // Sort the edges in non-decreasing order of weights

    for (const auto &edge: edges) {
        int start = edge.start;
        int stop = edge.end;

        int start_root = find_set(start); // Find the root of the start vertex
        int stop_root = find_set(stop); // Find the root of the stop vertex

        if (start_root != stop_root) {
            _union(start_root, stop_root); // Merge the sets containing the start and stop vertices
            mst_value += edge.weight; // Add the weight of the current edge to the minimum spanning tree value
            num_edges_in_mst++; // Increment the number of edges in the minimum spanning tree

            mst_edges.push_back(edge); // Add the current edge to the minimum spanning tree edges
        }

        if (num_edges_in_mst == graph->get_vertices() - 1)
            break; // If the number of edges in the minimum spanning tree equals V-1, where V is the number of vertices, break the loop
    }
    return mst_value; // Return the minimum spanning tree value
}


void Kruskal::_union(int first_vertex, int second_vertex) {
    auto first_parent = find_set(first_vertex);
    auto second_parent = find_set(second_vertex);

    if (ranks[first_parent] < ranks[second_parent]) {
        parents[first_parent] = second_parent;
    } else if (ranks[first_parent] > ranks[second_parent]) {
        parents[second_parent] = first_parent;
    } else {
        parents[second_parent] = first_parent;
        ranks[first_parent]++;
    }
}

int Kruskal::find_set(int vertex) {
    if (parents[vertex] != vertex) {
        parents[vertex] = find_set(parents[vertex]);
    }
    return parents[vertex] = parents[vertex] == vertex ? vertex : find_set(parents[vertex]);
}

void Kruskal::sort_edges() {
    sorter.sort(edges);
}

void Kruskal::display_mst() {
    cout << "Minimum Spanning Tree Edges:\n";
    for (const auto edge: mst_edges) {
        cout << edge.start << " - weight(" << edge.weight << ") - " << edge.end << endl;
    }
}


template int Kruskal::process<ListGraph>(ListGraph *graph, int start_vertex);

template int Kruskal::process<MatrixGraph>(MatrixGraph *graph, int start_vertex);
