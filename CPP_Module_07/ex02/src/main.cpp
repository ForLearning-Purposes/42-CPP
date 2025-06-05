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
        
        Array<int> array2(5);
        std::cout << "Array of 5 elements: " << array2 << std::endl;

        // So here we need to overload the [] operator in the Array class
        // to allow access to elements like array2[0], array2[1], etc.
        Array<int> array3(5);
        array3[3] = 1;
        std::cout << "Array of 5 elements: " << array3 << std::endl;
        //array3[100] = 42; // This should throw an exception
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

// https://github.com/BaBreton/42-CPP/blob/main/module07/ex02/src/main.cpp