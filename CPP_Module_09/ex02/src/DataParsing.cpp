#include "../inc/DataParsing.hpp"

/*
***** GETTERS & SETTERS
*/

std::vector<int> DataParsing::getVecor() const {
    return this->_vec;
}

std::deque<int> DataParsing::getDeque() const {
    return this->_dq;
}

void DataParsing::setVecor(int num) {
    _vec.push_back(num);
}

void DataParsing::setDeque(int num) {
    _dq.push_back(num);
}

/*
***************************************************
*/

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
        _vec.push_back(num);
        _dq.push_back(num);
    }
    std::cout << "***BEFORE***\n" << std::endl;
    printContainers();
}

void DataParsing::printContainers() {
    std::cout << "Vector:\t";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Deque:\t";
    for (std::deque<int>::iterator it = _dq.begin(); it != _dq.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n" << std::endl;
}