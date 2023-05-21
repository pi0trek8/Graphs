//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_FILEREADER_H
#define LIST_FILEREADER_H

#include <string>
#include <fstream>
#include <algorithm>
#include "iostream"

using namespace std;

class FileReader {
public:

    template<class T>
    T* read_graph_from_file(std::string file_path);
};



#endif //LIST_FILEREADER_H
