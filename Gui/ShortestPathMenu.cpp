#include "ShortestPathMenu.h"
#include "Utils/Utils.h"
#include "../graph/list/ListGraph.h"
#include "../graph/matrix/MatrixGraph.h"
#include "../graph/RandomDataGenerator.h"
#include "../FileReader/FileReader.h"
#include "../algorithms/fordBellman/FordBellman.h"
#include "../algorithms/dijkstra/Dijkstra.h"

void ShortestPathMenu::menu() {
    ListGraph *listGraph = nullptr;
    MatrixGraph *matrixGraph = nullptr;

    while (true) {
        Utils::clear_console();
        print_options();
        int choice = Utils::get_input();
        Utils::clear_console();

        switch (choice) {
            case 1: {
                FileReader fileReader;
                cout << "Choose graph implementation: " << endl;
                cout << "1. Matrix" << endl;
                cout << "2. List" << endl;
                int graph_choice = Utils::get_input();
                Utils::clear_console();

                switch (graph_choice) {
                    case 1: {
                        string file_name;
                        delete matrixGraph;
                        cout << "Enter file path: ";
                        cin >> file_name;

                        matrixGraph = fileReader.read_unordered_graph_from_file<MatrixGraph>(file_name);
                        Utils::clear_console();
                        break;
                    }
                    case 2: {
                        string file_name;
                        if (listGraph != nullptr) {
                            delete listGraph;
                        }
                        cout << "Enter file path: ";
                        cin >> file_name;

                        listGraph = fileReader.read_unordered_graph_from_file<ListGraph>(file_name);
                        Utils::clear_console();
                        break;
                    }
                    default: {
                        cout << "Wrong input" << endl;
                        Utils::press_any_to_continue();
                        break;
                    }
                }
                break;
            }
            case 2: {
                cout << "Choose graph implementation: " << endl;
                cout << "1. Matrix" << endl;
                cout << "2. List" << endl;
                int graph_choice = Utils::get_input();
                Utils::clear_console();
                switch (graph_choice) {
                    case 1: {
                        int vertex_number;
                        float density;
                        cout << "Enter vertex number: ";
                        vertex_number = Utils::get_input();
                        cout << "\nEnter graph density: ";
                        cin >> density;
                        RandomDataGenerator<MatrixGraph> randomDataGenerator;
                        matrixGraph = randomDataGenerator.create_random_undirected(vertex_number, density);
                        Utils::clear_console();
                        break;
                    }
                    case 2: {
                        int vertex_number;
                        float density;
                        cout << "Enter vertex number: ";
                        vertex_number = Utils::get_input();
                        cout << "\nEnter graph density: ";
                        cin >> density;
                        RandomDataGenerator<ListGraph> randomDataGenerator;
                        listGraph = randomDataGenerator.create_random_undirected(vertex_number, density);
                        Utils::clear_console();
                        break;
                    }
                    default: {
                        cout << "Wrong input" << endl;
                        Utils::press_any_to_continue();
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "Choose graph implementation: " << endl;
                cout << "1. Matrix" << endl;
                cout << "2. List" << endl;
                int graph_choice = Utils::get_input();
                Utils::clear_console();
                switch (graph_choice) {
                    case 1: {
                        if (matrixGraph == nullptr) {
                            cout << "No data in graph!" << endl;
                            break;
                        }
                        cout << "Matrix implementation" << endl << endl;
                        matrixGraph->display_adjacency_matrix();
                        cout << endl;
                        matrixGraph->display_adjacency_list();
                        break;
                    }
                    case 2: {
                        if (listGraph == nullptr) {
                            cout << "No data in graph!" << endl;
                            break;
                        }
                        cout << "List implementation" << endl << endl;
                        listGraph->display_adjacency_matrix();
                        cout << endl;
                        listGraph->display_adjacency_list();
                        break;
                    }
                    default: {
                        cout << "Wrong input" << endl;
                        break;
                    }
                }
                Utils::press_any_to_continue();
                Utils::clear_console();
                break;
            }
            case 4: {
                cout << "Choose graph implementation: " << endl;
                cout << "1. Matrix" << endl;
                cout << "2. List" << endl;
                int graph_choice = Utils::get_input();
                Utils::clear_console();

                switch (graph_choice) {
                    case 1: {
                        int start_v;
                        int stop_v;
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        cout << "Stop vertex: ";
                        stop_v = Utils::get_input();
                        Dijkstra algorithm;
                        cout << endl;
                        if (matrixGraph != nullptr) {
                            cout << "Path weight: " << algorithm.process(matrixGraph, start_v, stop_v) << endl;
                            algorithm.get_path(start_v, stop_v);
                        } else {
                            cout << "graph have no data" << endl;
                        }
                        Utils::press_any_to_continue();
                        break;
                    }
                    case 2: {
                        int start_v;
                        int stop_v;
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        cout << "Stop vertex: ";
                        stop_v = Utils::get_input();
                        Dijkstra algorithm;
                        cout << endl;
                        if (listGraph != nullptr) {
                            cout << "Path weight: " << algorithm.process(listGraph, start_v, stop_v) << endl;
                            algorithm.get_path(start_v, stop_v);
                        } else {
                            cout << "graph have no data" << endl;
                        }
                        Utils::press_any_to_continue();
                        break;
                    }
                }
                break;
            }
            case 5: {
                cout << "Choose graph implementation: " << endl;
                cout << "1. Matrix" << endl;
                cout << "2. List" << endl;
                int graph_choice = Utils::get_input();
                Utils::clear_console();

                switch (graph_choice) {
                    case 1: {
                        int start_v;
                        int stop_v;
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        cout << "Stop vertex: ";
                        stop_v = Utils::get_input();
                        cout << endl;

                        FordBellman algorithm;
                        if (matrixGraph != nullptr) {
                            cout << "Path weight: " << algorithm.process(matrixGraph, start_v, stop_v) << endl;
                            algorithm.get_path(start_v, stop_v);
                        } else {
                            cout << "graph have no data" << endl;
                        }
                        Utils::press_any_to_continue();
                        break;
                    }
                    case 2: {
                        int start_v;
                        int stop_v;
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        cout << "Stop vertex: ";
                        stop_v = Utils::get_input();
                        cout << endl;

                        FordBellman algorithm;
                        if (listGraph != nullptr) {
                            cout << "Path weight: " << algorithm.process(listGraph, start_v, stop_v) << endl;
                            algorithm.get_path(start_v, stop_v);
                        } else {
                            cout << "graph have no data" << endl;
                        }
                        Utils::press_any_to_continue();
                        break;
                    }
                }
                break;
            }
            case 6: {
                delete listGraph;
                delete matrixGraph;
                return;
            }
        }
    }
}

void ShortestPathMenu::print_options() {
    cout << endl;
    cout << "Menu for shortest path problem" << std::endl;
    cout << "1. Read from file" << std::endl;
    cout << "2. Generate random graph" << std::endl;
    cout << "3. Display" << std::endl;
    cout << "4. Algorithm - Dijkstra" << std::endl;
    cout << "5. Algorithm - Ford-Bellman" << std::endl;
    cout << "6. Go back" << std::endl;
    cout << "Choose: ";
}
