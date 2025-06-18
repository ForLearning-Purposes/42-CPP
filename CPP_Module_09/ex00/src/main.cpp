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
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <input_string>" << std::endl;
        // maybe add some information about the expected input format and constraints
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