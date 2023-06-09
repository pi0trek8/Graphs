#ifndef GRAPH_ALGORITHMS_DIJKSTRA_H
#define GRAPH_ALGORITHMS_DIJKSTRA_H
#pragma once

#include "../../collections/Array.h"
#include "../../collections/BinaryHeap/MinBinaryHeap.h"
#include "../../graph/matrix/MatrixGraph.h"
#include "../../graph/list/ListGraph.h"
#include "../../collections/BinaryHeap/node/PriorityQueueNode.h"

class Dijkstra {
private:
    Array<int> distances;
    Array<int> predecessors;
    Array<bool> visited;

    int findMinDistanceVertex();

public:

    template<class G>
    int process(G *graph, int start_vertex, int stop_vertex);

    void get_path(int start_vertex, int stop_vertex);
};



#endif //GRAPH_ALGORITHMS_DIJKSTRA_H
