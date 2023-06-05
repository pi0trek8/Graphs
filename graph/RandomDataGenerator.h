//
// Created by Piotr Szczypior on 18/05/2023.
//

#ifndef GRAPH_ALGORITHMS_RANDOMDATAGENERATOR_H
#define GRAPH_ALGORITHMS_RANDOMDATAGENERATOR_H

#include <random>
#include "matrix/MatrixGraph.h"

using namespace std;

template<class G>
class RandomDataGenerator {
public:
    G *create_random_undirected(int vertices_number, float density);

    G *create_random_directed(int vertices_number, float density);

    MatrixGraph *create_matrix_directed(int vertices_number, float density);

    MatrixGraph *create_matrix_undirected(int vertices_number, float density);
};

template<class G>
MatrixGraph *RandomDataGenerator<G>::create_matrix_undirected(int vertices_number, float density) {

    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> random_weight_distribution(0, 1000);
    uniform_int_distribution<int> random_vertex_distribution(0, vertices_number - 1);
    int edge_number = static_cast<int>(((vertices_number - 1) * vertices_number * density));
    auto *graph = new MatrixGraph(vertices_number, edge_number);

    return graph;
}

template<class G>
MatrixGraph *RandomDataGenerator<G>::create_matrix_directed(int vertices_number, float density) {
    return nullptr;
}


#endif //GRAPH_ALGORITHMS_RANDOMDATAGENERATOR_H
