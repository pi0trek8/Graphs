#include "Kruskal.h"
#include "../../graph/list/ListGraph.h"
#include "../../graph/matrix/MatrixGraph.h"


template<class G>
int Kruskal::process(G *graph, int start_vertex) {
    for (int i = 0; i < graph->get_vertices(); i++) {
        parents.push_back(i);
        ranks.push_back(-1);
    }
    int mst_value = 0;
    int num_edges_in_mst = 0;

    if constexpr (std::is_same_v<G, MatrixGraph>) {
        int diagonal = 1;
        for (int i = 0; i < graph->get_vertices(); i++) {
            for (int j = 0; j < diagonal; j++) {
                int weight = graph->find_edge(i, j);
                if (weight != 0) {
                    Edge edge(i, j, weight);
                    edges.push_back(edge);
                }
            }
            diagonal++;
        }

    } else if constexpr (std::is_same_v<G, ListGraph>) {
        for (int i = 0; i < graph->get_vertices(); i++) {
            for (auto node: graph->get_adjacent_vertices(i)) {
                Edge edge(i, node.vertex, node.weight);
                edges.push_back(edge);
            }
        }
    }
    this->sort_edges();
    for (const auto &edge: edges) {
        int start = edge.start;
        int stop = edge.end;

        int start_root = find_set(start);
        int stop_root = find_set(stop);

        if (start_root != stop_root) {
            _union(start_root, stop_root);
            mst_value += edge.weight;
            num_edges_in_mst++;

            mst_edges.push_back(edge);
        }

        if (num_edges_in_mst == graph->get_vertices() - 1)
            break;
    }
    return mst_value;
}


void Kruskal::_union(int first_vertex, int second_vertex) {
    auto first_parent = find_set(first_vertex);
    auto second_parent = find_set(second_vertex);

    if (ranks[first_parent] < ranks[second_parent]) {
        parents[first_parent] = second_parent;
    } else if (ranks[first_vertex] == ranks[second_parent]) {
        ranks[first_parent] += 1;
    } else {
        parents[second_parent] = first_parent;
    }
}

int Kruskal::find_set(int vertex) {
    if (parents[vertex] != vertex)
        parents[vertex] = find_set(parents[vertex]);
    return parents[vertex];
}

void Kruskal::sort_edges() {
    sorter.sort(edges);
}

void Kruskal::display_mst() {
    cout << "Minimum Spanning Tree Edges:\n";
    for(const auto edge : mst_edges) {
        cout << edge.start << " - weight(" << edge.weight << ") - " << edge.end << endl;
    }
}


template int Kruskal::process<ListGraph>(ListGraph *graph, int start_vertex);

template int Kruskal::process<MatrixGraph>(MatrixGraph *graph, int start_vertex);
