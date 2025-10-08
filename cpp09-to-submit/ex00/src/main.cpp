#include "../inc/BitcoinExchange.hpp"

/*
INFO:
Bitcoin Exchange, the task is to create a program that reads
a file containing historical Bitcoin prices and another file
with user input (dates and values), then calculates how much
a given amount of Bitcoin was worth on those dates.

-   For this exercise I used a map from the STL library.
    I chose map because it made sense to use a container
    with key-value pairs — in this case, the key is the date
    and the value is the price.
*/

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange exchange(av[1]);
    } catch (const std::exception &e) {
        std::cerr << "Exeption:\n\t" << e.what() << std::endl;
        return 1;
    }

    /* {
        try {
            (void) av;
            std::cout << "Creating a\n";
            BitcoinExchange a(av[1]);  // default constructor

            std::cout << "\nCreating b as a copy of a\n";
            BitcoinExchange b(a);  // copy constructor

            std::cout << "\nCreating c\n";
            BitcoinExchange c;

            std::cout << "\nAssigning a to c\n";
            c = a;  // copy assignment

            std::cout << "\nEnd of main\n";
        } catch (...) {
            std::cerr << "ERROR" << std::endl;
        }
        return 0;
    } */
    return 0;
}
