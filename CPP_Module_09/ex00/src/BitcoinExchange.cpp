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

    std::string date = line.substr(0, pos - 1);
    std::string valueStr = line.substr(pos + 2);
    
    validateDate(date);

    std::cout << "<" << date << ">" << "_|_" << "<" << valueStr << ">" << std::endl;

    validateValue(valueStr);
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
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::runtime_error("Error: Invalid date format, expected 'YYYY-MM-DD': " + date);
    }

    int yearPosition = 0;
    int monthPosition = 5;
    int dayPosition = 8;

    for (; yearPosition < 4; ++yearPosition) {
        if (!isdigit(date[yearPosition])) {
            throw std::runtime_error("Error: Invalid year in date: " + date);
        }
    }
    for (; monthPosition < 7; ++monthPosition) {
        if (!isdigit(date[monthPosition])) {
            throw std::runtime_error("Error: Invalid month in date: " + date);
        }
    }
    for (; dayPosition < 10; ++dayPosition) {
        if (!isdigit(date[dayPosition])) {
            throw std::runtime_error("Error: Invalid day in date: " + date);
        }
    }

    std::string savedYear = date.substr(0, 4);
    std::string savedMonth = date.substr(5, 2);
    std::string savedDay = date.substr(8, 2);

    if (savedYear < "2009" || savedYear > "2022") {
        throw std::runtime_error("Error: Year out of range, expected between 2009 and 2022: " + savedYear);
    }
    if (savedMonth < "01" || savedMonth > "12") {
        throw std::runtime_error("Error: Month out of range, expected between 01 and 12: " + savedMonth);
    }

    // Check if the day is valid for the given month and year
    std::stringstream ssYear(savedYear);
    int year;
    ssYear >> year;

    switch (leapYear(year)) {
        case true:
            if (savedMonth == "02" && (savedDay < "01" || savedDay > "29")) {
                throw std::runtime_error("Error: Invalid day for February in leap year: " + savedDay);
            }
            break;
        case false:
            if (savedMonth == "02" && (savedDay < "01" || savedDay > "28")) {
                throw std::runtime_error("Error: Invalid day for February in non-leap year: " + savedDay);
            }
            break;
        default:
            break;
    }
    if ((savedMonth == "04" || savedMonth == "06" || savedMonth == "09" || savedMonth == "11") && (savedDay < "01" || savedDay > "30")) {
        throw std::runtime_error("Error: Invalid day for month with 30 days: " + savedDay);
    }
    if ((savedMonth == "01" || savedMonth == "03" || savedMonth == "05" || savedMonth == "07" || savedMonth == "08" || savedDay == "10" || savedMonth == "12") && (savedDay < "01" || savedDay > "31")) {
        throw std::runtime_error("Error: Invalid day for month with 31 days: " + savedDay);
    }
}

int BitcoinExchange::leapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? true : false;
}

// FORMAT: "float" (e.g., "123.45")
void BitcoinExchange::validateValue(const std::string &valueStr) const {
    //shoudl not have space
    if (valueStr.find(' ') != std::string::npos) {
        throw std::runtime_error("Error: Invalid value format, spaces are not allowed: " + valueStr);
    }
    std::stringstream ss(valueStr);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        throw std::runtime_error("Error: Invalid value format, expected a float: " + valueStr);
    }
    if (value < 0 || value > 1000) {
        throw std::runtime_error("Error: Value out of range, expected between 0 and 1000: " + valueStr);
    }
}