#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _filename(""), _data() {}
BitcoinExchange::BitcoinExchange(const std::string &filename) : _filename(filename), _data() {
    parseFile();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _filename(other._filename), _data(other._data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) { (void)other; return *this; }
BitcoinExchange::~BitcoinExchange() {}
//_________________________________________________________________________________________________________________

// *** GETTERS ***
std::map<std::string, float> BitcoinExchange::getData() const {
    return _data;
}

const std::string BitcoinExchange::getFilename() const {
    return _filename;
}
//_________________________________________________________________________________________________________________

// *** PRIVATE METHODS ***
void BitcoinExchange::parseFile() {
    std::cout << "Parsing file: " << _filename << "\n\n" << std::endl;

    std::ifstream file(_filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + _filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        validateFormat(line);
    }
    std::cout << std::endl;
    file.close();
}

void BitcoinExchange::validateFormat(const std::string &line) const {
    std::stringstream ss(line);

    size_t pos = validateSeparatorAndReturnPosition(line);

    std::string date = line.substr(0, pos);
    std::string valueStr = line.substr(pos + 1);

    std::cout << "<" << date << ">" << "_|_" << "<" << valueStr << ">" << std::endl;

    validateDate(date);
}

size_t BitcoinExchange::validateSeparatorAndReturnPosition(const std::string &line) const {
    size_t pos = line.find('|');
    if (pos == std::string::npos || pos == 0 || pos == line.length() - 1) {
        throw std::runtime_error("Error: Invalid format, missing '|' or '|' first or last in line: " + line);
    }
    if (line.find('|', pos + 1) != std::string::npos) {
        throw std::runtime_error("Error: Invalid format, multiple '|' in line: " + line);
    }
    
    // Check that there is a space before and after the separator
    std::size_t sepSpace = line.find(" | ");
    if (sepSpace == std::string::npos) {
        throw std::runtime_error("Error: Invalid format, missing '[space]|[space]' in line: " + line);
    }
    return pos;
}

// FORMAT: "YYYY-MM-DD"
void BitcoinExchange::validateDate(const std::string &date) const {
    (void)date; // Placeholder for future implementation
}

// FORMAT: "float" (e.g., "123.45")
void BitcoinExchange::validateValue(const std::string &valueStr) const {
    (void)valueStr; // Placeholder for future implementation
}