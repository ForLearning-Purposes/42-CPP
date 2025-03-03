#include "../include/Replace.hpp"
#include <iostream>
#include <string>

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
    Replace replace;
    std::string filename = "";
    std::string s1 = "";
    std::string s2 = "";    

    if (ac != 4){
        std::cout << "Error: Wrong number of arguments" << std::endl;
        std::cout << "Usage: ./Replace <filename> <string-to-replace> <replace-with>" << std::endl;
        return 1;
    }
    else {
        args_handling(av, filename, s1, s2);
        replace.replace(filename, s1, s2);
    }
    return 0;
}