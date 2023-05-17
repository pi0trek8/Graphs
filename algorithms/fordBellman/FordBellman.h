#ifndef GRAPH_ALGORITHMS_FORDBELLMAN_H
#define GRAPH_ALGORITHMS_FORDBELLMAN_H


#include "../../collections/Array.h"

class FordBellman {
private:
    Array<int> distances;
    Array<int> predecessors;

public:
    template<class G>
    int process(G *graph, int start_vertex, int stop_vertex);

    void get_path(int start_vertex, int stop_vertex);
};



#endif //GRAPH_ALGORITHMS_FORDBELLMAN_H
