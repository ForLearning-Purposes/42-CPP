#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>


template <typename T>
std::vector<std::pair<T, T>> recursivePairing(std::vector<T> &vec) {
    std::vector<std::pair<T, T>> ptrPairs;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (i + 1 < vec.size())
            std::cout << "i + 1 < vec.size()" << std::endl;
        ptrPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }
    if (ptrPairs.size() > 1)
        recursivePairing(ptrPairs);

    return ptrPairs;
}

int main(int ac, char **av) {
    std::vector<int> vec = {1, 5, 2, 7, 3};

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    recursivePairing(vec);

    /*
    for (int i = 0; i < vec.size(); i++) {
        int first = vec[i];
        int second = vec[i + 1];
        std::cout << first << " " << second << std::endl;
        }
        std::cout << std::endl;
    */
       
    /*
    std::vector<std::pair<int*, int*>> ptrPairs;
    
    for (int i = 0; i + 1 < vec.size(); i += 2) {
        if (i + 1 < vec.size())
        std::cout << "i + 1 < vec.size()" << std::endl;
        ptrPairs.push_back(std::make_pair(&vec[i], &vec[i + 1]));
    }
    */


    /* 
    int i = 0;
    for (std::vector<std::pair<int*, int*>>::iterator it = ptrPairs.begin(); it != ptrPairs.end(); it++) {
        std::cout << "Poiter: " << *ptrPairs[i].first << ", " << *ptrPairs[i].second << std::endl;
        i++;
    }
    int *a = ptrPairs[0].first;
    int *b = ptrPairs[0].second;

    std::swap(*a, *b);
    std::cout << vec[0] << " " << vec[1] << std::endl;
    */
}