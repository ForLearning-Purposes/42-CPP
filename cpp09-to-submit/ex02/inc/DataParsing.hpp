#ifndef DATAPARSING_HPP
#define DATAPARSING_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

template <typename Container>
class DataParsing {
    // ADD: No duplicates - but don't have to
    public:
        DataParsing();
        DataParsing(int ac, char **av);
        DataParsing(const DataParsing<Container>& other);
        DataParsing<Container>& operator=(const DataParsing<Container>& other);
        ~DataParsing();

        //_____________________________________________________________________

        typedef typename Container::iterator Iterator;

        //_____________________________________________________________________

        void parseArgs(int ac, char **av);
        bool isPoitive(const std::string& s);
        void noDups();

        //_____________________________________________________________________

        //GETTERS & SETTERS
        std::vector<int> getVecor() const;
        std::deque<int> getDeque() const;
        Container getContainer() const;
        void setVecor(int num);
        void setDeque(int num);
        void setContainer(int num);

    protected:
        Container _container;
        std::vector<int> _vec;
        std::deque<int> _dq;
};

#include "../template/DataParsing.tpp"

#endif