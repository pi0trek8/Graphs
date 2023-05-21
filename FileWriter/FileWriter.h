//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_FILEWRITER_H
#define LIST_FILEWRITER_H

#include <string>
#include <fstream>
#include <iostream>

class FileWriter {

public:
    void write_to_file(std::string file_name, int elements_number, float argument);
};



#endif //LIST_FILEWRITER_H
