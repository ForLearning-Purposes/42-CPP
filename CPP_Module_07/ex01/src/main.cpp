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
    std::string strArray[] = {"Hello", "what", "are", "you", "doing?"};

    std::cout << "\n**String array before iter:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n**String array after iter:" << std::endl;

    iter(strArray, 5, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}