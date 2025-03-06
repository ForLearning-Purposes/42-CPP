#include <iostream>
#include <string>
#include <cstdlib>
#include "Harl.hpp"

int complainLevel(std::string level) {
    if (level == "DEBUG")
        return 0;
    else if (level == "INFO")
        return 1;
    else if (level == "WARNING")
        return 2;
    else if (level == "ERROR")
        return 3;
    else {
        std::cout << "\n\nHMMM... Invalid level -_-" << std::endl;
        exit(1);
    }
}

int main(int ac, char **av) {
    Harl harl;
    (void)av;

    if (ac != 1)
    {
        std::cout << "Usage: ./Harl" << std::endl;
        return 1;
    }
    else{
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        std::cout << std::endl;
        harl.complain("INVALID");
    }
    return 0;
}