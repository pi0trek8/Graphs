#include "RandomDataGenerator.h"
#include "list/ListGraph.h"
#include "matrix/MatrixGraph.h"

template<class G>
G *RandomDataGenerator<G>::create_random_undirected(int vertices_number, float density) {

    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> random_weight_distribution(1, 1000);
    uniform_int_distribution<int> random_vertex_distribution(0, vertices_number - 1);
    int edge_number = static_cast<int>(((vertices_number - 1) * vertices_number * density) / 2.0);


    G *graph = nullptr;
    if constexpr (std::is_same_v<G, ListGraph>) {
        graph = new ListGraph(vertices_number);
    } else if constexpr (std::is_same_v<G, MatrixGraph>) {
        graph = new MatrixGraph(vertices_number, edge_number);
    }

    int current_edge_number = 0;
    for (int vertex = 0; vertex < vertices_number; vertex++) {
        auto other_vertex = random_vertex_distribution(generator);
        while (other_vertex == vertex)
            other_vertex = random_vertex_distribution(generator);

        int weight = random_weight_distribution(generator);

        if constexpr (std::is_same_v<G, ListGraph>) {
            graph->add_undirected_edge(vertex, other_vertex, weight);
        } else if constexpr (std::is_same_v<G, MatrixGraph>) {
            graph->add_undirected_edge(current_edge_number, vertex, other_vertex, weight);
        }
        current_edge_number++;
    }

    while (current_edge_number < edge_number) {
        int first_vertex = random_vertex_distribution(generator);
        int second_vertex = random_vertex_distribution(generator);

        while (first_vertex == second_vertex) {
            first_vertex = random_vertex_distribution(generator);
            second_vertex = random_vertex_distribution(generator);
        }

        if (graph->has_edge(first_vertex, second_vertex)) {
            continue;
        }


        int weight = random_weight_distribution(generator);
        if constexpr (std::is_same_v<G, ListGraph>) {
            graph->add_undirected_edge(first_vertex, second_vertex, weight);
        } else if constexpr (std::is_same_v<G, MatrixGraph>) {
            graph->add_undirected_edge(current_edge_number, first_vertex, second_vertex, weight);
        }
        current_edge_number++;
    }

    return graph;
}

template<class G>
G *RandomDataGenerator<G>::create_random_directed(int vertices_number, float density) {
    auto map = new Array<int>[vertices_number];

    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> random_weight_distribution(0, 1000);
    uniform_int_distribution<int> random_vertex_distribution(0, vertices_number - 1);
    int edge_number = static_cast<int>(((vertices_number - 1) * vertices_number * density)/ 2.0);

    G *graph = nullptr;
    if constexpr (std::is_same_v<G, ListGraph>) {
        graph = new ListGraph(vertices_number);
    } else if constexpr (std::is_same_v<G, MatrixGraph>) {
        graph = new MatrixGraph(vertices_number, edge_number);
    }

    int current_edge_number = 0;
    for (int vertex = 0; vertex < vertices_number; vertex++) {
        auto other_vertex = random_vertex_distribution(generator);
        while (other_vertex == vertex)
            other_vertex = random_vertex_distribution(generator);
        int weight = random_weight_distribution(generator);


        if constexpr (std::is_same_v<G, ListGraph>) {
            graph->add_directed_edge(vertex, other_vertex, weight);
        } else if constexpr (std::is_same_v<G, MatrixGraph>) {
            graph->add_directed_edge(current_edge_number, vertex, other_vertex, weight);
        }
        map[vertex].push_back(other_vertex);
        current_edge_number++;
    }

    while (current_edge_number < edge_number) {
        int first_vertex = random_vertex_distribution(generator);
        int second_vertex = random_vertex_distribution(generator);
        while (first_vertex == second_vertex) {
            first_vertex = random_vertex_distribution(generator);
            second_vertex = random_vertex_distribution(generator);
        }

        if (!map[first_vertex].find(second_vertex)) {
            int weight = random_weight_distribution(generator);
            if constexpr (std::is_same_v<G, ListGraph>) {
                graph->add_directed_edge(first_vertex, second_vertex, weight);
            } else if constexpr (std::is_same_v<G, MatrixGraph>) {
                graph->add_directed_edge(current_edge_number, first_vertex, second_vertex, weight);
            }
            current_edge_number++;
        }
    }

    return graph;
}


template
ListGraph *RandomDataGenerator<ListGraph>::create_random_directed(int vertices_number, float density);

template
MatrixGraph *RandomDataGenerator<MatrixGraph>::create_random_directed(int vertices_number, float density);


template
ListGraph *RandomDataGenerator<ListGraph>::create_random_undirected(int vertices_number, float density);

template
MatrixGraph *RandomDataGenerator<MatrixGraph>::create_random_undirected(int vertices_number, float density);
