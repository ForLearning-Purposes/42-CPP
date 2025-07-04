#include "../inc/Span.hpp"

int main() {
    {
        Span span(5);
        try {
            span.addNumber(6);
            span.addNumber(3);
            span.addNumber(17);
            span.addNumber(9);
            span.addNumber(11);
            std::cout << "Added 5 numbers successfully." << std::endl;
            std::cout << span;
            span.longestSpan(); // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        Span span(5);
        try {
            span.addNumber(6);
            span.addNumber(3);
            span.addNumber(17);
            span.addNumber(9);
            span.addNumber(11);
            std::cout << "Added 5 numbers successfully." << std::endl;
            span.shortestSpan();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        //From the subject:
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.shortestSpan();
        sp.longestSpan();
    }
    {
        //deep copy test
        /* Span span1(5);
        span1.addNumber(6);
        span1.addNumber(3);
        span1.addNumber(17);
        span1.addNumber(9);
        span1.addNumber(11);
        Span span2(span1); // Copy constructor
        std::cout << "Span 2 (copied from Span 1): " << span2 << std::endl; */
    }
}