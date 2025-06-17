#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "../inc/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) {
    *this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
    if (this != &other) {
        // Copy the underlying container from the other stack
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

//_________________________________________________________________________________________

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::c_begin() const {
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::c_end() const {
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
    return this->c.end();
}

//_________________________________________________________________________________________

/*
Test function to demonstrate the stack functionality
and iteration over its elements.
This function pushes three integers onto the stack,
then iterates through the stack's underlying container
and prints each element.
Because MutantStack inherits from std::stack,
we can access the underlying container directly.
But if we try to use std::stack directly, we cannot
iterate over its elements like this.
Becasue container is protected and only accessible
from derived classes.
*/
template <typename T>
void MutantStack<T>::testStack() const {
    MutantStack<T> s;
	s.push(10);
	s.push(20);
	s.push(30);
    
    /*
    // Cannot access elements directly like this
    for (int i = 0; i < 3; ++i) {
        std::cout << "Element at index " << i << ": " << s.top() << std::endl;
    } */

    std::cout << "\n***Stack elements iterate:\n" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    or the whole c
    typename std::stack<T>::container_type::iterator it = s.begin();
    typename std::stack<T>::container_type::iterator end = s.end();
    for (; it != end; ++it) {
        std::cout << *it << std::endl;
    }

    std::stack<int>::container_type& cont = s.c; // Accessing the underlying container of the stack
    
    for (typename std::stack<T>::container_type::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << std::endl;
    }
//______________________________________________________________________

    std::cout << "\n***Stack elements iterate:\n" << std::endl;

    std::stack<int>::container_type::iterator ite = s.c.begin();

    while (ite != cont.end()) {
        std::cout << *ite << std::endl;
        ++ite;
    }
}

/*

std::vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
std::vector<int>::iterator it = v.begin();

*/

#endif