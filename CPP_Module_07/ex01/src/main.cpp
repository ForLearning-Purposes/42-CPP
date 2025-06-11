#include "../inc/iter.hpp"

template <typename T>
void iter(T *array, size_t length, void (*func)(T &anyElem)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void printElement(T &elem) {
    std::cout << elem << std::endl;
}

int main() {

//  Test with a string array
    std::string strArray[] = {"Hello", "what", "are", "you", "doing?"};

    std::cout << "\n**String array before iter:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n**String array after iter:" << std::endl;

    int num_of_lines = 5;
    iter(strArray, num_of_lines, printElement<std::string>);
    std::cout << std::endl;

//  Test with a int array
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "\n**Integer array before iter:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n**Integer array after iter:" << std::endl;
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

//  Test with const int array
    const int constIntArray[] = {10, 20, 30, 40, 50};
    std::cout << "\n**Const Integer array before iter:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << constIntArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\n**Const Integer array after iter:" << std::endl;
    iter(constIntArray, 5, printElement<const int>);
    std::cout << std::endl;

    return 0;
}