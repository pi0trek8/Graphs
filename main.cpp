#include <iostream>
#include <list>
#include <climits>
#include <cstdlib>
#include <ctime>
#include "graph/list/node/Node.h"
#include "collections/Array.h"
#include "collections//DoubleList.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"
#include "algorithms/dijkstra/Dijkstra.h"
#include "algorithms/fordBellman/FordBellman.h"
#include "algorithms/prim/Prim.h"
#include "algorithms/kruskal/Kruskal.h"
#include "collections/BinaryHeap/MinBinaryHeap.h"
#include "sorter/Sorter.h"
#include "graph/RandomDataGenerator.h"

using namespace std;


int main(int argc, char *argv[]) {

    RandomDataGenerator<ListGraph> randomDataGenerator;


    auto *graph = randomDataGenerator.create_random_directed(5,1);

//    auto *graph = new ListGraph(5);
//    graph->add_undirected_edge(0, 1, 2);
//    graph->add_undirected_edge(0, 3, 6);
//    graph->add_undirected_edge(1, 2, 3);
//    graph->add_undirected_edge(1, 3, 8);
//    graph->add_undirected_edge(1, 4, 5);
//    graph->add_undirected_edge(2, 4, 7);
//    graph->add_undirected_edge(3, 4, 9);

    Dijkstra algorithm;
    graph->display_adjacency_list();

    auto path = algorithm.process(graph, 0,4);
    cout << path << endl;
    algorithm.get_path(0,4);

}
