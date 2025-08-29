#ifndef DATAPARSING
#define DATAPARSING

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

class DataParsing {
    // ADD: No duplicates
    public:
        void parseArgs(int ac, char **av);
        bool isPoitive(const std::string& s);
        void printContainers() const;
        std::vector<int> getVecor() const;
        std::deque<int> getDeque() const;
    protected:
        std::vector<int> vec;
        std::deque<int> dq;
};

#endif