#include <iostream>
#include "../inc/Base.hpp"
#include <cstdlib>
#include <ctime>

int main () {
    std::srand(std::time(0));

    Base base;
    Base *ptr = generate();
    std::cout << "Using pointer:" << std::endl;
    identify(ptr);
    std::cout << "Using reference:" << std::endl;
    // Base &ref = *ptr;
    // identify(ref);
    identify(&*ptr);
    delete ptr;
}