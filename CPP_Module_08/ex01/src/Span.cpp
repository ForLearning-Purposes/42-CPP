#include "../inc/Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}
//_________________________________________________________

/*
addNumber(int)
Adds a single number to your Span.

Should throw an exception if more than N elements are added.
*/
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Cannot add more numbers, Span is full.");
    }

    _numbers.push_back(number);

    std::cout << "Added number: " << number << std::endl;
}
//_________________________________________________________

// *** GETTERS ***
unsigned int Span::getNumber(unsigned int index) const {
    if (index >= _numbers.size() || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return _numbers[index];
}

unsigned int Span::getMaxSize() const {
    return _maxSize;
}
//_________________________________________________________

/*
shortestSpan()
Returns the smallest difference between any two numbers in the container.

You must throw an exception if there are fewer than 2 elements.

Tip:

Sort the container, then check consecutive differences to get the shortest span.
*/
unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::runtime_error("Not enough elements to compute span.");
    }
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    std::cout << "_________________________________________" << std::endl;
    std::cout << "\n***shortestSpan(): " << std::endl;
    std::cout << "Sorted numbers: ";
    for (size_t i = 0; i < sortedNumbers.size(); ++i) {
        std::cout << sortedNumbers[i] << " ";
    }
    std::cout << std::endl;
    
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sortedNumbers.size() - 1; ++i) {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    std::cout << "Minimum span: " << minSpan << std::endl;
    std::cout << "_________________________________________\n" << std::endl;
    return minSpan;
}
//_________________________________________________________

/*
longestSpan()
Returns the largest difference between any two numbers in the container.

Again, throw an exception if there are fewer than 2 elements.

Tip:

Use *max_element() and *min_element() from <algorithm> to compute this quickly.
*/
unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements to compute span.");

    unsigned int minValue = *std::min_element(_numbers.begin(), _numbers.end());
    unsigned int maxValue = *std::max_element(_numbers.begin(), _numbers.end());
    
    std::cout << "_________________________________________" << std::endl;
    std::cout << "\n***longestSpan(): " << std::endl;
    std::cout << "Min: " << minValue << "\nMax: " << maxValue << std::endl;
    std::cout << "Difference: " << maxValue - minValue << std::endl;
    std::cout << "_________________________________________\n" << std::endl;
    
    return maxValue - minValue;
}
//_________________________________________________________

// print all numbers in the vector
std::ostream& operator<<(std::ostream& os, const Span& span) {

    std::cout << "_________________________________________" << std::endl;
    os << "\nSpan numbers: ";
    for (unsigned int i = 0; i < span.getMaxSize(); i++) {
        try {
            os << span.getNumber(i) << " ";
        } catch (const std::out_of_range& e) {
            os << "[Out of range] ";
        }
    }
    os << std::endl;
    return os;
}
//_________________________________________________________