#ifndef PMERGEME
#define PMERGEME

// use deque and vector (template to use both)
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include "DataParsing.hpp"

class PmergeMe : public DataParsing {
    public:
        void sortVector();
        void sortDeque();
};

#endif