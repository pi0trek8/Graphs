//
// Created by Piotr Szczypior on 19/05/2023.
//

#include "FileReader.h"
#include "../graph/list/ListGraph.h"
#include "../graph/matrix/MatrixGraph.h"

//template<class T>
//T *FileReader::read_graph_from_file(std::string file_path) {
////    fstream file;
////    file.open(file_path, ios::in);
////
////    if (!file.is_open()) {
////        cout << "File " << file_path << " not found. Aborting operation - 'reading from file' ..." << endl;
////        return collection;
////    }
////
////    for (std::string line; getline(file, line);) {
////        try {
////            line.erase(std::remove_if(line.begin(), line.end(), ::isspace),
////                       line.end());
////            collection->add(std::stoi(line));
////        } catch (std::invalid_argument ex) {
////            cout << "Invalid argument: " << line << " in " << ex.what() << endl;
////        }
////    }
////    file.close();
////
////    return collection;
//    return
//}

//template ListGraph *FileReader::read_graph_from_file(string file_name);
//template MatrixGraph *FileReader::read_graph_from_file(string file_name);