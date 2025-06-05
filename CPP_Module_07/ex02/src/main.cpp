#include "../inc/Array.hpp"
#include "Array.cpp"

int main() {
    try {
        Array<int> array1;
        std::cout << "Default constructed array: " << array1 << std::endl;
        
        //Suggested test case:
        // int * a = new int();
        // std::cout << "Value of a: " << *a << std::endl;
        // delete a;
        
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

// https://github.com/BaBreton/42-CPP/blob/main/module07/ex02/src/main.cpp