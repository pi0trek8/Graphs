//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "FileWriter.h"

void FileWriter::write_to_file(std::string file_name, int elements_number, float argument) {
    file_name += + ".csv";

    std::cout<<"writing to: " << file_name << std::endl;

    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);

    if(file.is_open()) {
        std::string line = std::to_string(argument) + "\n";
        file << line;
    }

    file.close();
}
