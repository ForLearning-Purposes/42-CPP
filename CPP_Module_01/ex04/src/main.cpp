#include "../include/Replace.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// Forbidden functions : std::string::replace

/*
- ifstream (Input File Stream) → Used for reading files.
- ofstream (Output File Stream) → Used for writing to files.
- fstream (File Stream) → Used for both reading and writing.
*/

/*
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2
*/
int main (int ac, char **av){
    Replace replaceClass;

    if (ac != 4){
        std::cout << "Error: Wrong number of arguments" << std::endl;
        std::cout << "Usage: ./Replace <filename> <string-to-replace> <replace-with>" << std::endl;
        return 1;
    }
    else {
        args_handling(av);
        const std::string filename = av[1];
        const std::string cont = content(filename);
        const std::string search = av[2];
        const std::string replace = av[3];
        //check first how std::string::replace works
        replaceClass.replace(filename, search, replace, cont);
    }
    return 0;
}