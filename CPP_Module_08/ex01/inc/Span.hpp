#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

/*
Test your Span with at least 10,000 numbers.
More would be even better.
*/
class Span {
    public:
        Span(unsigned int N);

        void addNumber(int number);
        
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
    private:
        std::vector<int> _numbers;
};

#endif