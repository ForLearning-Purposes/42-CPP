#include "../inc/DataParsing.hpp"

std::vector<int> DataParsing::getVecor() const {
    return this->vec;
}

bool DataParsing::isPoitive(const std::string& s) {
    if (s.empty()) return false;
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i])) return false;
    return true;
}

void DataParsing::parseArgs(int ac, char **av){
    for (int i = 1; i < ac; i++){
        std::string str = av[i];
        if (!isPoitive(av[i])){
            std::cout << "Error" << std::endl;
            exit(1);
        }
        int num = std::atoi(av[i]);
        if (num < 0){
            std::cout << "Error" << std::endl;
            exit(1);
        }
        vec.push_back(num);
        dq.push_back(num);
    }
    printContainers();
}

void DataParsing::printContainers() const {
    std::cout << "***BEFORE***" << std::endl;
    std::cout << "Vector:\t" << std::endl;
    std::cout << "Deque:\t" << std::endl;
}