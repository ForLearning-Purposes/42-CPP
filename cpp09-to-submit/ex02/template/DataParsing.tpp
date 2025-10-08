#ifndef DATAPARSING_TPP
#define DATAPARSING_TPP

#include "../inc/DataParsing.hpp"
#include <iterator>

template <typename Container>
DataParsing<Container>::DataParsing(){
}

template <typename Container>
DataParsing<Container>::DataParsing(int ac, char **av){
    parseArgs(ac, av);
    noDups();
}

template <typename Container>
DataParsing<Container>::DataParsing(const DataParsing &other) {
    *this = other;
}

template <typename Container>
DataParsing<Container> &DataParsing<Container>::operator=(const DataParsing &other) {
    if (this != &other) {
        _container = other._container;
        _vec = other._vec;
        _dq = other._dq;
    }
    return *this;
}

template <typename Container>
DataParsing<Container>::~DataParsing() {}

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
            throw std::invalid_argument("ERROR");
        }
        int num = std::atoi(av[i]);
        if (num < 0){
            throw std::invalid_argument("ERROR");
        }
        _vec.push_back(num);
        _dq.push_back(num);
        _container.push_back(num);
    }
}

template <typename Container>
void DataParsing<Container>::noDups(){

    std::set<int> seen;
    for (Iterator it = _container.begin(); it != _container.end(); it++){
        if (seen.find(*it) != seen.end()) {
            throw std::invalid_argument("ERROR: Duplicates."); // Duplicate found
        }
        seen.insert(*it);
    }
}


#endif