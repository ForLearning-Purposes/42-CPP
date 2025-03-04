#include "../include/Replace.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>



Replace::Replace() {}

Replace::~Replace() {}

/*
open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2
*/
void Replace::replace(std::string filename, std::string search, std::string replace, std::string content) {
    std::string newContent;
    std::size_t position = 0, found;

    while ((found = content.find(search, position)) != std::string::npos){
        newContent.append(content.begin() + position, content.begin() + found);
        newContent.append(replace);
        position = found + search.length();
    }
    newContent.append(content.begin() + position, content.end());
    
    std::string newFilename = filename + ".replace";
    std::ofstream outputFile(newFilename.c_str());
    if (!outputFile.is_open()){
        std::cout << "Error: Could not create file" << std::endl;
        exit(1);
    }
    outputFile << newContent;
    outputFile.close();

    std::cout << "File " << filename << " has been successfully replaced" << std::endl;
    return;
}