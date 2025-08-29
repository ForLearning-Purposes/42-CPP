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
        void printContainers();

        //GETTERS & SETTERS
        std::vector<int> getVecor() const;
        std::deque<int> getDeque() const;
        void setVecor(int num);
        void setDeque(int num);
    protected:
        std::vector<int> _vec;
        std::deque<int> _dq;
};

#endif