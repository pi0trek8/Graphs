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
#include "timer/Timer.h"
#include "FileReader/FileReader.h"
#include "Gui/MainMenu.h"

#include <string.h>

using namespace std;


int main(int argc, char *argv[]) {
    FileReader fileReader;
    string file = R"(C:\Users\Admin\Desktop\Graphs\dane_mst1.txt)";
    auto graph = fileReader.read_unordered_graph_from_file<MatrixGraph>(file);

    graph->display_adjacency_matrix();

    Prim dijkstra;
//
//    auto value = dijkstra.process(graph, 0);
//    cout << "Val: " << value << endl;
//    dijkstra.get_path(0, 6);
    dijkstra.process(graph, 0);
    dijkstra.display_mst();
//    MainMenu::menu();

//    FileReader fileReader;
//
//    auto *graph = fileReader.read_unordered_graph_from_file<MatrixGraph>(R"(C:\Users\Admin\Desktop\Graphs\test.txt)");
//
//    graph->display_adjacency_list();
//    int number_vertices = std::stoi(argv[2]);
//    float density = std::stof(argv[3]);
//
//    if(strcmp("Matrix", argv[4]) == 0) {
//
//        RandomDataGenerator<MatrixGraph> randomDataGenerator;
//
//
////    auto *graph = new ListGraph(5);
////    graph->add_directed_edge(0, 1, 2);
////    graph->add_directed_edge(0, 3, 6);
////    graph->add_directed_edge(1, 2, 3);
////    graph->add_directed_edge(1, 3, 8);
////    graph->add_directed_edge(1, 4, 5);
////    graph->add_directed_edge(2, 4, 7);
////    graph->add_directed_edge(3, 4, 9);
//
//        if (strcmp("Prim", argv[1]) == 0) {
//
//            Timer timer;
//            Prim algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << whole_time / 50;
//        } else if(strcmp("Kruskal", argv[1]) == 0) {
//            Timer timer;
//            Kruskal algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << (whole_time / 50) / 8;
//        } else if(strcmp("Dijkstra", argv[1]) == 0) {
//            Timer timer;
//            Dijkstra algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0, 9);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << whole_time / 50;
//        } else if(strcmp("FordBellman", argv[1]) == 0) {
//            Timer timer;
//            FordBellman algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0, 9);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << whole_time / 50;
//        }
//
//    } else {
//        RandomDataGenerator<MatrixGraph> randomDataGenerator;
//
//        if (strcmp("Prim", argv[1]) == 0) {
//
//            Timer timer;
//            Prim algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << whole_time / 50;
//        } else if(strcmp("Kruskal", argv[1]) == 0) {
//            Timer timer;
//            Kruskal algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_undirected(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << (whole_time / 50) / 8;
//        } else if(strcmp("Dijkstra", argv[1]) == 0) {
//            Timer timer;
//            Dijkstra algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0, 9);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << whole_time / 50;
//        } else if(strcmp("FordBellman", argv[1]) == 0) {
//            Timer timer;
//            FordBellman algorithm;
//            auto whole_time = 0;
//
//            for (int i = 0; i < 50; i++) {
//                auto *graph = randomDataGenerator.create_random_directed(number_vertices, density);
//
//                timer.timeStart();
//                auto path = algorithm.process(graph, 0, 9);
//                timer.timeStop();
//                whole_time += timer.elapsedTime();
//            }
//
//            cout << whole_time / 50;
//        }
//    }
} 
