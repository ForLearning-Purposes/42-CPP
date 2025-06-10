#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "../inc/Array.hpp"

template <typename T>
Array<T>::Array() : _elements(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n > 0) {
        _elements = new T[n]();
    } else {
        _elements = 0;
    }
}

template <typename T>
Array<T>::Array(const Array &src) : _size(src._size) {
    if (_size > 0) {
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _elements[i] = src._elements[i];
        }
    } else {
        _elements = 0;
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
    if (this != &rhs) {
        delete[] _elements; // Free existing memory
        _size = rhs._size;
        if (_size > 0) {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _elements[i] = rhs._elements[i];
            }
        } else {
            _elements = 0;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (_elements == 0) {
        return; // No memory to free
    }
    delete[] _elements; // Free allocated memory
}

/*
GETTERS *****************************************
*/

template <typename T>
unsigned int Array<T>::getSize() const {
    return _size;
}

template <typename T>
T *Array<T>::getElements() const {
    return _elements;
}

/*
*************************************************
*/

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
    os << "Array size: " << array.getSize() << "\nElements: ";
    for (unsigned int i = 0; i < array.getSize(); ++i) {
        os << array.getElements()[i] << " ";
    }
    return os;
}

/*
*************************************************
*/

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _elements[index];
}

/*
*************************************************
*/

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return ("Index out of bounds");
}

#endif // ARRAY_TPP