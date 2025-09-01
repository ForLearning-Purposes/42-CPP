#ifndef DATAPARSING_TPP
#define DATAPARSING_TPP


#include "../inc/DataParsing.hpp"

template <typename Container>
DataParsing<Container>::DataParsing(){
    std::cout << "**DataParsing (perent) Constructor - no args**" << std::endl;
    //need to handle parsing
}

template <typename Container>
DataParsing<Container>::DataParsing(int ac, char **av){
    std::cout << "**DataParsing (perent) Constructor - with args**" << std::endl;
    parseArgs(ac, av);
}

/*
***** GETTERS & SETTERS
*/

template <typename Container>
std::vector<int> DataParsing<Container>::getVecor() const {
    return this->_vec;
}

template <typename Container>
std::deque<int> DataParsing<Container>::getDeque() const {
    return this->_dq;
}

template <typename Container>
Container DataParsing<Container>::getContainer() const {
    return this->_container;
}

template <typename Container>
void DataParsing<Container>::setVecor(int num) {
    _vec.push_back(num);
}

template <typename Container>
void DataParsing<Container>::setDeque(int num) {
    _dq.push_back(num);
}

template <typename Container>
void DataParsing<Container>::setContainer(int num) {
    _container.push_back(num);
}

/*
***************************************************
*/

template <typename Container>
bool DataParsing<Container>::isPoitive(const std::string& s) {
    if (s.empty()) return false;
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i])) return false;
    return true;
}

template <typename Container>
void DataParsing<Container>::parseArgs(int ac, char **av){
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
        _container.push_back(num);
    }
    std::cout << "***BEFORE***\n" << std::endl;
    printContainers();
}

template <typename Container>
void DataParsing<Container>::printContainers() {
    std::cout << "Container:\t";
    for (typename Container::iterator it = _container.begin(); it != _container.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n" << std::endl;
}

#endif