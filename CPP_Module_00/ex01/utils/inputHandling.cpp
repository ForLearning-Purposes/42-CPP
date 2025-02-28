#include "../include/inputHandling.hpp"
#include <algorithm>
#include <iostream>

inputHandling::inputHandling() {}

inputHandling::~inputHandling() {}

bool inputHandling::ifInputEmptyAndNoCharacter(std::string input, std::string message){
    if (input.empty()){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " can't be empty.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input.find_first_not_of(' ') == std::string::npos){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must have at least one character.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input.length() >= 20) //longer then 20 characters
    {
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must have less than 20 characters.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    return true;
}

bool inputHandling::isPhoneNumberDigit(std::string input, std::string message){
    if (input.empty()){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " can't be empty.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input.find_first_not_of("0123456789") != std::string::npos){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must have only digits.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input.length() < 10 || input.length() > 15){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must have between 10 and 15 digits.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    return true;
}

bool inputHandling::isIndexDigit(std::string input, std::string message){
    if (input.empty()){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " can't be empty.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input.find_first_not_of("0123456789") != std::string::npos){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must have only digits.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input.length() > 1){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must have only one digit.\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    else if (input[0] < '0' || input[0] > '7'){
        std::cout << "\033[1;91m";
        std::cout << "\nERROR:\n" << message << " must be between 0 and 7\n" << std::endl;
        std::cout << "\033[0m";
        return false;
    }
    return true;
}