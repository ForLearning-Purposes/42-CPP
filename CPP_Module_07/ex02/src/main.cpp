#include "../inc/Array.hpp"

#define MAX_VAL 750


int main(int, char**)
{
    // Test with default constructor and basic functionality
    {
        try {
            Array<int> array1;
            std::cout << "Default constructed array: " << array1 << std::endl;
            
            //Suggested test case:
            int * a = new int();
            std::cout << "Value of a: " << *a << std::endl;
            delete a;
            
            Array<int> array2(5);
            std::cout << "Array of 5 elements: " << array2 << std::endl;

            // So here we need to overload the [] operator in the Array class
            // to allow access to elements like array2[0], array2[1], etc.
            Array<int> array3(5);
            array3[3] = 1;
            std::cout << "Array of 5 elements: " << array3 << std::endl;
            array3[100] = 42; // This should throw an exception
        }
        catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    // Test with a large number of elements
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }
    
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << numbers[i] << " ";
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        std::cout << std::endl;
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }
    {
        std::cout << "__________________________________________________\n" << std::endl;
        //Test: Construction by copy and assignment operator. In both cases, modifying either the
        //original array or its copy after copying musn’t affect the other array.
        std::cout << "\n*****Test Default constructor\n" << std::endl;
        Array<int> array1(10);
        std::cout << "Original array1: " << array1 << std::endl;
        for (int i = 0; i < 10; ++i) {
            array1[i] = i * 2; // Initialize with some values
        }
        std::cout << "Initialized array1: " << array1 << std::endl;
        std::cout << "__________________________________________________\n" << std::endl;
        std::cout << "\n*****Test Copy constructor\n" << std::endl;
        Array<int> array2(array1); // Copy constructor
        std::cout << "Copied array2 from array1: " << array2 << std::endl;
        array2[0] = 100; // Modify array2
        std::cout << "Modified array2: " << array2 << std::endl;
        std::cout << "Original array1 after modifying array2: " << array1 << std::endl;
        std::cout << "__________________________________________________\n" << std::endl;
    }
    return 0;
}