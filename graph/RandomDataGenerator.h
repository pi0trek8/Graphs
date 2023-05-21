//
// Created by Piotr Szczypior on 18/05/2023.
//

#ifndef GRAPH_ALGORITHMS_RANDOMDATAGENERATOR_H
#define GRAPH_ALGORITHMS_RANDOMDATAGENERATOR_H

#include <random>

using namespace std;

template<class G>
class RandomDataGenerator {
public:
    G *create_random_undirected(int vertices_number, float density);

    G *create_random_directed(int vertices_number, float density);
};


#endif //GRAPH_ALGORITHMS_RANDOMDATAGENERATOR_H
