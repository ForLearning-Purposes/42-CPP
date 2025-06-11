#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

/*
Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be called on every element of the array.
Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.
Think carefully about how to support both const and non-const
elements in your iter function.
*/

template <typename T>
void iter(T *array, size_t length, void (*func)(T &anyElem));

template <typename T>
void printElement(T &elem);

#endif