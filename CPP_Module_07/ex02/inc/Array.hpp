#ifndef ARRAY_HPP
#define ARRAY_HPP

/*
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (allocating
memory in advance) is forbidden. Your program must never access nonallocated
memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameters and must not modify the current instance.
As usual, ensure everything works as expected and turn in a main.cpp file that contains
your tests.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &rhs);
        ~Array();

        unsigned int getSize() const;
        T *getElements() const;

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        T *_elements;
        unsigned int _size;

};

#include "../template/Array.tpp"

#endif