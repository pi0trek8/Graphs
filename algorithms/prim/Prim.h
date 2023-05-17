#ifndef GRAPH_ALGORITHMS_PRIM_H
#define GRAPH_ALGORITHMS_PRIM_H


#include "../../collections/Array.h"
#include "../../collections/BinaryHeap/node/PriorityQueueNode.h"
#include "../../collections/BinaryHeap/BinaryHeap.h"
#include "../edge/Edge.h"
#include "../../collections/DoubleList.h"

class Prim {
private:
    Array<int> weights;
    Array<int> connections;
    DoubleList<PriorityQueueNode> priority_queue;
    Array<Edge> mst_edges;

    int extract_min();

public:
    template<class G>
    int process(G *graph, int start_vertex);

    void display_mst();
};



#endif //GRAPH_ALGORITHMS_PRIM_H
