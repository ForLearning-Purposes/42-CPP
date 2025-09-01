#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "../inc/PmergeMe.hpp"

//_________________________________________________________________________________________
// CONSTRUCTOR, COPYCONSTRUCTOR & DESTRUCTOR

template <typename Container>
PmergeMe<Container>::PmergeMe() : DataParsing<Container>() {
    std::cout << "**PmergeMe (child) Constructor - no args**" << std::endl;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(int ac, char **av) : DataParsing<Container>(ac, av) {
    std::cout << "**PmergeMe (child) Constructor - with args**" << std::endl;
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) {
    *this = other;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other) {
    if (this != &other) {
        // Copy the underlying container from the other stack
    }
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(){}

template <typename Container>
std::ostream& operator<<(std::ostream& os, const PmergeMe<Container>& PmergeMe) {
    (void) os;
    (void) PmergeMe;
}

//_________________________________________________________________________________________


#endif