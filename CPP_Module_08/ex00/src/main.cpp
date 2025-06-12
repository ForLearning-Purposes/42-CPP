#include "../inc/easyfind.hpp"

/*
However, using them is precisely the goal of this Module. You are allowed to
use the STL. Yes, you can use the Containers (vector/list/map/and so forth) and the
Algorithms (defined in header <algorithm>). Moreover, you should use them as much
as you can. Thus, do your best to apply them wherever it’s appropriate

n any case, the header files are mandatory while the .tpp files are optional.
*/

int main() {
    {
        try {
            std::vector<int> int_array;

            for (int i = 0; i < 10; ++i) {
                int_array.push_back(i * 2);
            }
            for (int i = 0; i < (int)int_array.size(); ++i) {
                std::cout << "int_array[" << i << "] = " << int_array[i] << std::endl;
            }
            std::cout << "\n**** Searching for value 16 in int_array..." << std::endl;
            easyfind(int_array, 16);
            std::cout << "________________________________________" << std::endl;

            std::cout << "\n**** Searching for value 5 in int_array..." << std::endl;
            easyfind(int_array, 5);
            std::cout << "________________________________________" << std::endl;


        } catch (const std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    std::cout << "\n\n***Still alive!***\n\n" << std::endl;
    {
        std::vector<int> int_array;

        for (int i = 0; i < 10; ++i) {
            int_array.push_back(i * 2);
        }
        for (int i = 0; i < (int)int_array.size(); ++i) {
            std::cout << "int_array[" << i << "] = " << int_array[i] << std::endl;
        }

        std::cout << "\n**** Searching for value 16 in int_array..." << std::endl;
        easyfind(int_array, 16);
        std::cout << "________________________________________" << std::endl;
        
        // std::cout << "\n**** Searching for value -9 in int_array..." << std::endl;
        // easyfind(int_array, -9);
        // std::cout << "________________________________________" << std::endl;

        std::cout << "\n**** Searching for value 0 in int_array..." << std::endl;
        easyfind(int_array, 0);
        std::cout << "________________________________________" << std::endl;

    }
    // {
    //     try {
    //         std::vector<std::string> string_array;

    //         for (int i = 0; i < 10; ++i) {
    //             string_array.push_back("String_" + std::to_string(i));
    //         }
    //         for (int i = 0; i < (int)string_array.size(); ++i) {
    //             std::cout << "string_array[" << i << "] = " << string_array[i] << std::endl;
    //         }

    //         // NOT REQUIRED BY THE SUBJECT
    //         // std::cout << "\n**** Searching for value 'String_5' in string_array..." << std::endl;
    //         // easyfind(string_array, 5);

    //     } catch (const std::exception &e) {
    //         std::cout << "Exception: " << e.what() << std::endl;
    //     }
    // }
    return 0;
}