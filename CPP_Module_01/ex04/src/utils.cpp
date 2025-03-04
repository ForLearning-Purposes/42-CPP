#include "../include/Replace.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

const std::string content(std::string filename){
    std::ifstream
    inputFile(filename.c_str());
    std::string content, line;
    while (std::getline(inputFile, line)){
        content += line + "\n";
    }
    inputFile.close();
    return content;
}