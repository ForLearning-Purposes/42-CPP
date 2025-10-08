#include <iostream>
#include "../inc/PmergeMe.hpp"

/*
INFO:
PmergeMe, the task is to implement a sorting algorithm that
merges and sorts sequences of numbers using different STL containers.

-   For this exercise I used both vector and deque from the STL library.
    I used templates so the same function works with both containers.
    This implementation is meant to challenge us to work with
    different container types and understand how to write flexible code 
    (or just to make us go crazy as always).
*/

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "ERROR\nUsage: ./prog num1 num2 num3 ..." << std::endl;
        return 1;
        }
        try {
            PmergeMe<std::vector<int> > Vector(ac, av);
            PmergeMe<std::deque<int> > Deque(ac, av);
        } catch (...) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
               
/*     {
        try {
            (void) av;
            std::cout << "Creating a\n";
            PmergeMe<std::vector<int> > Vector(ac, av);  // default constructor

            std::cout << "\nCreating b as a copy of a\n";
            PmergeMe<std::vector<int> > Vector1(Vector);  // copy constructor

            std::cout << "\nCreating c\n";
            PmergeMe<std::vector<int> > Vector2;

            std::cout << "\nAssigning a to c\n";
            Vector2 = Vector;  // copy assignment

            std::cout << "\nEnd of main\n";
        } catch (...) {
            std::cerr << "ERROR" << std::endl;
        }
        return 0;
    } */
    return 0;
}