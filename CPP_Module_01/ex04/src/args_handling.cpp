#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void args_handling(char **av, std::string &filename, std::string &s1, std::string &s2){
    if (av[1] == NULL || av[1][0] == '\0'){
        std::cout << "Error: Invalid filename" << std::endl;
        exit(1);
    }
    for (int i = 0; av[1][i] != '\0'; i++){
        if (!isalnum(av[1][i])) { // isalnum checks if the character is alphanumeric (letter or digit)
            std::cout << "Error: Invalid filename" << std::endl;
            exit(1);
        }
    }
    std::ifstream file(av[1]);
    if (!file.is_open()){
        std::cout << "Error: File does not exist" << std::endl;
        exit(1);
    }
    file.close();
    filename = av[1];
    if (av[2] == NULL || av[2][0] == '\0'){
        std::cout << "Error: Invalid s1" << std::endl;
        exit(1);
    }
    s1 = av[2];
    if (av[3] == NULL){
        std::cout << "Error: Invalid s2" << std::endl;
        exit(1);
    }
    s2 = av[3];    
    return;
}