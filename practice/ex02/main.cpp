#include "PmergeMe.hpp"
int main(int ac , char **av){
    try{
        if(ac > 2){
            PmergeMe<std::vector<int > > Vector(av);
            Vector.sort();
            Vector.sort_time();
            
            // PmergeMe<std::deque<int > > Deque(av);
            // std::cout << "Before: " << Deque << std::endl;
            // Deque.sort();
            // std::cout << "After: " << Deque << std::endl;
            // Deque.sort_time();

        }else 
            throw "bad trip";
    }catch(...){
        std::cerr << "bad trip " << std::endl;
    }
    return 0;
}