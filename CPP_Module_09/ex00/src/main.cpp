#include "../inc/BitcoinExchange.hpp"

// void parsingInput(const std::string input) {
//     std::cout << "\n*** 1. \nInput received: " << input << std::endl;

//     std::ifstream file(input.c_str());
//     if (!file.is_open()) {
//         std::cerr << "Error: Could not open file " << input << std::endl;
//         exit(1);
//     }
//     std::cout << "\n*** 2. \nFile opened successfully.\n" << std::endl;

//     std::cout << "*** 3. \nProcessing file contents..." << std::endl;
//     std::string line;
//     while (std::getline(file, line)) {
//         std::cout << "Processing line: " << line << std::endl;
//     }
//     std::cout << "\n*** 4. \nFile processing completed.\n" << std::endl;
//     file.close();
// }

int main(int ac, char **av) {

    //test copy constructor and assignment operator
    // {
    //     BitcoinExchange exchange("something.txt");
    //     BitcoinExchange copyExchange = exchange;
    //     BitcoinExchange assignedExchange;
    //     assignedExchange = exchange;
    // }

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
    return 0;
}





/*
    std::map<std::string, int> testMap;
    std::string key = "Monika";
    testMap.insert(std::make_pair(key, 0));
    testMap.insert(std::make_pair(key, 1));
    testMap.insert(std::make_pair(key, 2));
    testMap.insert(std::make_pair(key, 3));
    testMap.insert(std::make_pair(key, 4));
    testMap.insert(std::make_pair(key, 5));
    //if the key already exists is it going to fail to insert or overwrite the value?
    if (testMap.insert(std::make_pair(key, 6)).second) {
        std::cout << "Inserted new value for 'Monika'." << std::endl;
    } else {
        std::cout << "Failed to insert new value for 'Monika', key already exists." << std::endl;
    }
    std::map<std::string, int>::iterator it = testMap.begin();
    for (; it != testMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
*/