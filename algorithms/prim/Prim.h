#ifndef GRAPH_ALGORITHMS_PRIM_H
#define GRAPH_ALGORITHMS_PRIM_H


#include "../../collections/Array.h"
#include "../../collections/BinaryHeap/node/PriorityQueueNode.h"
#include "../../collections/BinaryHeap/BinaryHeap.h"
#include "../../collections/DoubleList.h"
#include "../../sorter/Sorter.h"
#include "../../collections/BinaryHeap/MinBinaryHeap.h"

class Prim {
private:
    Array<int> weights;
    Array<int> connections;
    MinBinaryHeap<PriorityQueueNode> priority_queue;

public:
    template<class G>
    void process(G *graph, int start_vertex);

    void display_mst();
};


#endif //GRAPH_ALGORITHMS_PRIM_H
