#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

void args_handling(char **av){
    if (av[1] == NULL || av[1][0] == '\0'){
        std::cout << "Error: Invalid filename" << std::endl;
        exit(1);
    }
    if (strlen(av[1]) > 20){
        std::cout << "Error: Filename too long" << std::endl;
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
    if (av[2] == NULL || av[2][0] == '\0'){
        std::cout << "Error: Invalid s1" << std::endl;
        exit(1);
    }
    if (strlen(av[2]) > 20){
        std::cout << "Error: s1 too long" << std::endl;
        exit(1);
    }
    if (av[3] == NULL){
        std::cout << "Error: Invalid s2" << std::endl;
        exit(1);
    }
    if (strlen(av[3]) > 20){
        std::cout << "Error: s2 too long" << std::endl;
        exit(1);
    }
    return;
}