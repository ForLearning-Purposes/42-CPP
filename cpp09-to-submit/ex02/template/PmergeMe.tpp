#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "../inc/PmergeMe.hpp"

//_________________________________________________________________________________________
// CONSTRUCTOR, COPYCONSTRUCTOR & DESTRUCTOR

template <typename Container>
PmergeMe<Container>::PmergeMe() : DataParsing<Container>() {
    if (container_type() == "unknown") {
        throw std::invalid_argument("Error: Unsupported container type.");
    }
}

template <typename Container>
PmergeMe<Container>::PmergeMe(int ac, char **av) : DataParsing<Container>(ac, av) {
    if (container_type() == "unknown") {
        throw std::invalid_argument("Error: Unsupported container type.");
    }
    sort();
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) {
    *this = other;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other) {
    if (this != &other) {
        // nothing to copy
    }
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(){}

template <typename Container>
std::ostream& operator<<(std::ostream& os, const PmergeMe<Container>& PmergeMe) {
    (void) os;
    (void) PmergeMe;
    return os;
}

//_________________________________________________________________________________________
// SORTING ALGORITHM

template <typename Container>
void PmergeMe<Container>::sort() {

    if (times <= 1) {
        std::cout << "Before:\t";
        this->printContainers();
    }

    clock_t start = clock();
    recursiveSort(this->_container, 1);
    clock_t end = clock();

    if (times <= 1) {
        std::cout << "After:\t";
        this->printContainers();
    }
    printTime(start, end);
    times++;
}

template <typename Container>
void PmergeMe<Container>::recursiveSort(Container &cont, int block_of_elements) {
    int unit_size = cont.size() / block_of_elements;
    if (unit_size <= 1) {return;}

    bool is_odd = (unit_size % 2 == 1);
    Iterator start = cont.begin();
    Iterator end = cont.begin() + ((block_of_elements * unit_size) - (is_odd * block_of_elements));
    
    for (Iterator it = start; it < end; it += (block_of_elements * 2)) {
        if ( *(it + (block_of_elements - 1)) > *(it + ((block_of_elements * 2) - 1)) ) {
            for (int i = 0; i < block_of_elements; i++) {
                std::swap(*(it + i), *(it + block_of_elements + i));
            }
        }
    }

    recursiveSort(cont, block_of_elements * 2);

    Container main;
    Container pend;
    Container leftover;
    int odd = 0;

    main.push_back(*(start + block_of_elements - 1));
    main.push_back(*(start + block_of_elements * 2 - 1));

    for (Iterator it = start + block_of_elements * 2; it < end; it += block_of_elements) {
        pend.push_back(*(it + block_of_elements - 1));
        it += block_of_elements;
        if (it < end)
            main.push_back(*(it + block_of_elements - 1));
    }

    if (is_odd)
        odd = *(end + block_of_elements - 1);

    leftover.insert(leftover.end(), end + (is_odd * block_of_elements), cont.end());

    insertWithJacobsthal(main, pend, odd, leftover, cont, is_odd, block_of_elements);
}

template <typename Container>
int PmergeMe<Container>::Jacobsthal(int n) {
    return static_cast<int>(round((pow(2, n + 1) + pow(-1, n)) / 3));
}

template <typename Container>
void PmergeMe<Container>::insertWithJacobsthal(Container &main, Container &pend, int odd, Container &leftover, Container &cont, bool is_odd, int block_of_elements) {
    Iterator pos;

    if (pend.size() == 1) {
        pos = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(pos, *pend.begin());
    } else {
        size_t jc = 3;
        size_t count = 0;
        while (!pend.empty()) {
            size_t idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if (idx > pend.size()) idx = pend.size();

            size_t decrease = 0;
            while (idx) {
                size_t limit = Jacobsthal(jc + count) - decrease;
                if (limit > main.size()) limit = main.size();

                pos = std::upper_bound(main.begin(), main.begin() + limit, *(pend.begin() + idx - 1));
                main.insert(pos, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);

                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    if (is_odd) {
        pos = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(pos, odd);
    }

    Container rebuilt;
    for (typename Container::iterator it = main.begin(); it != main.end(); ++it) {
        typename Container::iterator found = std::find(cont.begin(), cont.end(), *it);
        rebuilt.insert(rebuilt.end(), found - (block_of_elements - 1), found + 1);
    }
    rebuilt.insert(rebuilt.end(), leftover.begin(), leftover.end());
    cont = rebuilt;
}

//_________________________________________________________________________________________
// OTHER

template <typename Container>
std::string PmergeMe<Container>::container_type() {
    if (typeid(this->_container) == typeid(std::vector<int>))
        return "std::vector";
    if (typeid(this->_container) == typeid(std::deque<int>))
        return "std::deque";
    return "unknown";
}

template <typename Container>
void PmergeMe<Container>::printContainers() {
    if (container_type() == "std::vector") {
        for (typename Container::iterator it = this->_container.begin(); it != this->_container.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

template <typename Container>
void PmergeMe<Container>::printTime(clock_t start, clock_t end) {
    double seconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5); 
    std::cout << "Time to process a range of " << this->_container.size() << " elements with " << container_type() << " : " << seconds << std::endl;
}

#endif