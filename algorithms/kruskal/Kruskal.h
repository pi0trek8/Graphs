#ifndef GRAPH_ALGORITHMS_KRUSKAL_H
#define GRAPH_ALGORITHMS_KRUSKAL_H


#include "../../collections/Array.h"
#include "../../collections/BinaryHeap/node/PriorityQueueNode.h"
#include "../../sorter/Sorter.h"
#include "../../dto/edge/Edge.h"

class Kruskal {
private:
    Array<int> parents;
    Array<int> ranks;
    Array<Edge> edges;
    Array<Edge> mst_edges;
    Sorter<Array<Edge>> sorter;
    int find_set(int vertex);

    void _union(int first_vertex, int second_vertex);

    void sort_edges();

public:
    template<class G>
    int process(G *graph, int start_vertex);

    void display_mst();
};


#endif //GRAPH_ALGORITHMS_KRUSKAL_H
