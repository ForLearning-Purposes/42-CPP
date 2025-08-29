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
        std::vector<int> getVec() const;
        std::deque<int> getDq() const;
        void setVec(std::vector<int>);
        void setDq(std::deque<int>);
};

#endif