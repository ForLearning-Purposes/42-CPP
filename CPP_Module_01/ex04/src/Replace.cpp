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
void Replace::replace(std::string filename, std::string s1, std::string s2) {
    if (filename.empty() || s1.empty()) {
        std::cout << "Error: Invalid arguments" << std::endl;
        exit(1);
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cout << "Error: File does not exist" << std::endl;
        exit(1);
    }
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cout << "Error: Could not create output file" << std::endl;
        exit(1);
    }

    std::string line = "";
    while (!inputFile.eof()) {
        std::getline(inputFile, line);//was not working when I had it in the while loop
        printf("line: %s\n", line.c_str());
        std::string::size_type position = line.find(s1);
        while (position != std::string::npos) {
            line.erase(position, s1.length());
            line.insert(position, s2);
            position = line.find(s1);
        }
        if (!inputFile.eof()) {
            outputFile << line << std::endl;
        }
    }
    outputFile << line; //to avoid an extra newline at the end of the file
    inputFile.close();
    outputFile.close();
    return;
}
