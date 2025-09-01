#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// use deque and vector (template to use both)
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include "DataParsing.hpp"

template <typename Container>
class PmergeMe : public DataParsing<Container> {

    
    public:
        Container container; //inspired my gh
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe<Container>& other);
        PmergeMe<Container>& operator=(const PmergeMe<Container>& other);
        ~PmergeMe();

        //_____________________________________________________________________

        //typedef typename T::iterator iterator; //check how to use module 08

        //_____________________________________________________________________


};

template <typename Container>
std::ostream& operator<<(std::ostream& os, const PmergeMe<Container>& PmergeMe);

#include "../template/PmergeMe.tpp"

#endif