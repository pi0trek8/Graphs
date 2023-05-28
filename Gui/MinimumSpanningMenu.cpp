//
// Created by Piotr Szczypior on 28/05/2023.
//

#include "MinimumSpanningMenu.h"
#include "Utils/Utils.h"
#include "../graph/matrix/MatrixGraph.h"
#include "../graph/list/ListGraph.h"
#include "../FileReader/FileReader.h"
#include "../graph/RandomDataGenerator.h"
#include "../algorithms/prim/Prim.h"
#include "../algorithms/kruskal/Kruskal.h"

void MinimumSpanningMenu::menu() {
    ListGraph* listGraph;
    MatrixGraph* matrixGraph;

    while (true) {
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

                switch(graph_choice) {
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
                        delete listGraph;
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
                        delete matrixGraph;
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
                        delete listGraph;
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
                        cout << "Matrix implementation" << endl << endl;
                        matrixGraph->display_adjacency_matrix();
                        cout << endl;
                        matrixGraph->display_adjacency_list();
                        Utils::press_any_to_continue();
                        Utils::clear_console();
                        break;
                    }
                    case 2: {
                        cout << "List implementation" << endl << endl;
                        listGraph->display_adjacency_matrix();
                        cout << endl;
                        listGraph->display_adjacency_list();
                        Utils::press_any_to_continue();
                        Utils::clear_console();
                        break;
                    }
                    default: {
                        cout << "Wrong input" << endl;
                        Utils::press_any_to_continue();
                        Utils::clear_console();
                        break;
                    }
                }
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
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        Prim prim;
                        if(matrixGraph != nullptr) {
                            cout << "MST weight: " << prim.process(matrixGraph, start_v) << endl;
                            cout << endl;
                            prim.display_mst();
                        } else {
                            cout << "graph have no data" << endl;
                        }
                        Utils::press_any_to_continue();
                        break;
                    }
                    case 2: {
                        int start_v;
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        Prim prim;
                        if(matrixGraph != nullptr) {
                            cout << "MST weight: " << prim.process(listGraph, start_v) << endl;
                            cout << endl;
                            prim.display_mst();
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
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        Kruskal kruskal;
                        if(matrixGraph != nullptr) {
                            cout << "MST weight: " << kruskal.process(matrixGraph, start_v) << endl;
                            cout << endl;
                            kruskal.display_mst();
                        } else {
                            cout << "graph have no data" << endl;
                        }
                        Utils::press_any_to_continue();
                        break;
                    }
                    case 2: {
                        int start_v;
                        cout << "Start vertex: ";
                        start_v = Utils::get_input();
                        Kruskal kruskal;
                        if(matrixGraph != nullptr) {
                            cout << "MST weight: " << kruskal.process(listGraph, start_v) << endl;
                            cout << endl;
                            kruskal.display_mst();
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

void MinimumSpanningMenu::print_options() {
    cout << endl;
    cout << "Menu for minimal spinning tree" << std::endl;
    cout << "1. Read from file" << std::endl;
    cout << "2. Generate random file" << std::endl;
    cout << "3. Display" << std::endl;
    cout << "4. Algorithm - Prima" << std::endl;
    cout << "5. Algorithm - Kruskal" << std::endl;
    cout << "6. Go back" << std::endl;
    cout << "Choose: ";
}
