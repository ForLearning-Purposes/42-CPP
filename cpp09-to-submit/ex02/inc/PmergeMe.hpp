#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <ctime>
# include <cmath>
# include <algorithm>
# include <stdexcept>
# include <typeinfo>
#include <iomanip>
#include <set>
# include "DataParsing.hpp"

static int times = 1;

template <typename Container>
class PmergeMe : public DataParsing<Container> {    
    public:
        //Container container; //inspired my gh
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe<Container>& other);
        PmergeMe<Container>& operator=(const PmergeMe<Container>& other);
        ~PmergeMe();

        //_____________________________________________________________________

        typedef typename Container::iterator Iterator;

        //_____________________________________________________________________

        void printContainers();
        void printTime(clock_t start, clock_t end);
        void sort();

    private:
        void recursiveSort(Container &cont, int block_of_elements);
        int Jacobsthal(int n);
        void insertWithJacobsthal(Container &main, Container &pend, int odd, Container &leftover, Container &cont, bool is_odd, int block_of_elements);
        std::string container_type();

};

# include "../template/PmergeMe.tpp"

#endif