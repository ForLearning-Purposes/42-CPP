#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../inc/easyfind.hpp"

template <typename T>
void easyfind(T &container, const int value_to_find) {
    typename T::iterator is_found = std::find(container.begin(), container.end(), value_to_find);

    if (is_found == container.end()) {
        std::cout << "Value NOT found, but what is in *is_found iterator? -> | " << *is_found << " |"<< std::endl;
        throw std::runtime_error("Value not found in the container");
    } else {
        std::cout << "Value found: | " << *is_found << " |" << std::endl;
    }
    return;
}

#endif