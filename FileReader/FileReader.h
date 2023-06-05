//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_FILEREADER_H
#define LIST_FILEREADER_H

#include <string>
#include <fstream>
#include <algorithm>
#include "iostream"
#include "../graph/matrix/MatrixGraph.h"
#include "../graph/list/ListGraph.h"
#include <sstream>

using namespace std;

class FileReader {
public:

    template<class T>
    T *read_unordered_graph_from_file(std::string file_path);

    template<class T>
    T *read_ordered_graph_from_file(std::string file_path);
};


#endif //LIST_FILEREADER_H
