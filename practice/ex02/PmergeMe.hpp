#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <typeinfo>

template <typename Container>
class PmergeMe {
    Container container;

    public:
        PmergeMe();
        PmergeMe(char **av);
        
        void sort_time();
        void sort();

        typedef typename Container::iterator Iterator;
        typedef typename Container::value_type ValueType;
        
        typename Container::iterator begin();
        typename Container::iterator end();

    private:
        time_t      start_, end_;

        int         Jacobsthal(int k);
        void        sort(Container &vec);
        void        insert(Container &main, Container &pend, ValueType odd, Container &left, Container &vec, bool is_odd, int order);
        float       time();
        size_t      count_word_and_check(std::string &str);    
        std::string container_type();
};

template <typename Container>
std::ostream& operator<<(std::ostream &os, const PmergeMe<Container> &obj);

#include "PmergeMe.tpp"

#endif