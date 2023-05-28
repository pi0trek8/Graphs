//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_FILEREADER_H
#define LIST_FILEREADER_H

#include <string>
#include <fstream>
#include <algorithm>
#include "iostream"
#include <sstream>

using namespace std;

class FileReader {
public:

    template<class T>
    T *read_unordered_graph_from_file(std::string file_path);

    template<class T>
    T *read_ordered_graph_from_file(std::string file_path);

};

template<class T>
T *FileReader::read_ordered_graph_from_file(std::string file_path) {
    std::ifstream file;
    file.open(file_path);
    int edge_count;
    int vertex_count;

    if (!file.is_open()) {
        return nullptr;
    }
    std::string line;
    std::getline(file, line);

    std::istringstream iss(line);
    if (!(iss >> vertex_count >> edge_count)) {
        std::cout << "Invalid file format. The first line should contain two numbers." << std::endl;
        return nullptr;
    }
    T *graph = new T(vertex_count);
    for (int i = 0; i < edge_count; i++) {
        int start_vertex;
        int stop_vertex;
        int weight;
        std::getline(file, line);
        std::istringstream edgeIss(line);

        if (!(edgeIss >> start_vertex >> stop_vertex >> weight)) {
            std::cout << "Invalid file format. Expecting three numbers per line." << std::endl;
            return nullptr;
        }
        graph->add_directed_edge(start_vertex, stop_vertex, weight);
    }

    return graph;
}

template<class T>
T *FileReader::read_unordered_graph_from_file(std::string file_path) {
    std::ifstream file;
    file.open(file_path);
    int edge_count;
    int vertex_count;

    if (!file.is_open()) {
        return nullptr;
    }
    std::string line;
    std::getline(file, line);

    std::istringstream iss(line);
    if (!(iss >> vertex_count >> edge_count)) {
        std::cout << "Invalid file format. The first line should contain two numbers." << std::endl;
        return nullptr;
    }
    T *graph = new T(vertex_count);
    for (int i = 0; i < edge_count; i++) {
        int start_vertex;
        int stop_vertex;
        int weight;
        std::getline(file, line);
        std::istringstream edgeIss(line);

        if (!(edgeIss >> start_vertex >> stop_vertex >> weight)) {
            std::cout << "Invalid file format. Expecting three numbers per line." << std::endl;
            return nullptr;
        }
        graph->add_undirected_edge(start_vertex, stop_vertex, weight);
    }

    return graph;
}


#endif //LIST_FILEREADER_H
