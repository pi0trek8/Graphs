#include <iostream>
#include "collections/Array.h"
#include "collections//DoubleList.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"
#include "algorithms/dijkstra/Dijkstra.h"
#include "algorithms/fordBellman/FordBellman.h"
#include "algorithms/prim/Prim.h"
#include "algorithms/kruskal/Kruskal.h"
#include "graph/RandomDataGenerator.h"
#include "timer/Timer.h"
#include "FileReader/FileReader.h"
#include <cstring>

void test(char *argv[]);

int main(int argc, char *argv[]) {
    string file = R"(C:\Users\Admin\Desktop\Graphs\dane_mst1.txt)";
    FileReader reader;
    auto graph = reader.read_unordered_graph_from_file<ListGraph>(file);

    graph->display_adjacency_list();

    Kruskal algorithm;

    auto start = 0;
    auto finish = 6;

    auto v = algorithm.process(graph, start);
    cout << "Value: " << v << endl;
//    algorithm.process(graph, start);
//    algorithm.get_path(start, finish);
    algorithm.display_mst();

//    if (argv != nullptr) {
//        test(argv);
//    }
}

void test(char *argv[]) {
    int number_vertices = std::stoi(argv[3]);
    float density = std::stof(argv[4]);
    if (strcmp("Matrix", argv[2]) == 0) {

        RandomDataGenerator<MatrixGraph> randomDataGenerator;
        if (strcmp("Prim", argv[1]) == 0) {

            Timer timer;
            Prim algorithm;
            long long whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << whole_time / 50;
        } else if (strcmp("Kruskal", argv[1]) == 0) {
            Timer timer;
            Kruskal algorithm;
            long long whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << (whole_time / 50);
        } else if (strcmp("Dijkstra", argv[1]) == 0) {
            Timer timer;
            Dijkstra algorithm;
            auto whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0, 9);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << whole_time / 50;
        } else if (strcmp("FordBellman", argv[1]) == 0) {
            Timer timer;
            FordBellman algorithm;
            auto whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0, 9);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << whole_time / 50;
        }

    } else {
        RandomDataGenerator<ListGraph> randomDataGenerator;

        if (strcmp("Prim", argv[1]) == 0) {

            Timer timer;
            Prim algorithm;
            long long whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << whole_time / 50;
        } else if (strcmp("Kruskal", argv[1]) == 0) {
            Timer timer;
            Kruskal algorithm;
            long long whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << ((whole_time / 50));
        } else if (strcmp("Dijkstra", argv[1]) == 0) {
            Timer timer;
            Dijkstra algorithm;
            auto whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0, 9);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << whole_time / 50;
        } else if (strcmp("FordBellman", argv[1]) == 0) {
            Timer timer;
            FordBellman algorithm;
            auto whole_time = 0;

            for (int i = 0; i < 50; i++) {
                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);

                timer.timeStart();
                algorithm.process(graph, 0, 9);
                timer.timeStop();
                whole_time += timer.elapsedTime();
            }

            cout << whole_time / 50;
        }
    }
}