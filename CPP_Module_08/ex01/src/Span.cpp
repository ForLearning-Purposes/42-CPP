#include "../inc/Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

/*
addNumber(int)
Adds a single number to your Span.

Should throw an exception if more than N elements are added.
*/
void Span::addNumber(int number) {}

/*
shortestSpan()
Returns the smallest difference between any two numbers in the container.

You must throw an exception if there are fewer than 2 elements.

Tip:

Sort the container, then check consecutive differences to get the shortest span.
*/
unsigned int Span::shortestSpan() const {
    return 0;
}

/*
longestSpan()
Returns the largest difference between any two numbers in the container.

Again, throw an exception if there are fewer than 2 elements.

Tip:

Use *max_element() and *min_element() from <algorithm> to compute this quickly.
*/
unsigned int Span::longestSpan() const {
    return 0;
}