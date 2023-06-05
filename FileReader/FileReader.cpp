#include "FileReader.h"


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
    T *graph = nullptr;

    if constexpr (std::is_same_v<T, ListGraph>) {
        graph = new ListGraph(vertex_count);
    } else if constexpr (std::is_same_v<T, MatrixGraph>) {
        graph = new MatrixGraph(vertex_count, edge_count);
    }
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
        if constexpr (std::is_same_v<T, ListGraph>) {
            graph->add_directed_edge(start_vertex, stop_vertex, weight);
        } else if constexpr (std::is_same_v<T, MatrixGraph>) {
            graph->add_directed_edge(i, start_vertex, stop_vertex, weight);
        }
    }

    return graph;
}

template<class T>
T *FileReader::read_unordered_graph_from_file(const std::string file_path) {
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
    T *graph = nullptr;
    if constexpr (std::is_same_v<T, ListGraph>) {
        graph = new ListGraph(vertex_count);
    } else if constexpr (std::is_same_v<T, MatrixGraph>) {
        graph = new MatrixGraph(vertex_count, edge_count);
    }
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
        if constexpr (std::is_same_v<T, ListGraph>) {
            graph->add_undirected_edge(start_vertex, stop_vertex, weight);
        } else if constexpr (std::is_same_v<T, MatrixGraph>) {
            graph->add_undirected_edge(i, start_vertex, stop_vertex, weight);
        }
    }

    return graph;
}


template ListGraph* FileReader::read_unordered_graph_from_file<ListGraph>(std::string file_name);

template ListGraph* FileReader::read_ordered_graph_from_file<ListGraph>(std::string file_name);

template MatrixGraph* FileReader::read_ordered_graph_from_file<MatrixGraph>(std::string file_name);

template MatrixGraph* FileReader::read_unordered_graph_from_file<MatrixGraph>(std::string file_name);
