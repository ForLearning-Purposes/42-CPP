#include "../inc/BitcoinExchange.hpp"
#include <ostream>

BitcoinExchange::BitcoinExchange() : _filename(""), _data() {}
BitcoinExchange::BitcoinExchange(const std::string &filename) : _filename(filename), _data() {
    //before parsing user input data, we need to parse the database of bitcoin values
    databaseParsing();
    parseFile();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _filename(other._filename), _data(other._data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) { (void)other; return *this; }
BitcoinExchange::~BitcoinExchange() {}
//_________________________________________________________________________________________________________________

// *** GETTERS ***
std::map<std::string, double> BitcoinExchange::getData() const {
    return _data;
}

const std::string BitcoinExchange::getFilename() const {
    return _filename;
}
//_________________________________________________________________________________________________________________

// *** PRIVATE METHODS ***
// *** FILE PARSING ***
void BitcoinExchange::parseFile() {

    std::ifstream file(_filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + _filename);
    }

    std::string line;

    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Error: Invalid header line, expected 'date | value'");

//HERE
    while (std::getline(file, line)) {
        if (validateFormat(line)) {
            std::string date = line.substr(0, 11 - 1);
            std::string valueStr = line.substr(11 + 2);

            std::stringstream ssValue(valueStr);
            float value;
            ssValue >> value;
            if (ssValue.fail() || !ssValue.eof()) {
                std::cerr << "Error: Invalid value format, expected a float: " << valueStr << std::endl;
                continue;
            }

            std::map<std::string, double>::iterator it = _data.begin();
            std::string closestDate;
            float exchangeRate = 0.0;
            for (; it != _data.end(); ++it) {
                if (date == it->first) {
                    std::cout << "Same date found! UserDate: |" << date << "| Database: |" << it->first << "|" << std::endl;
                } else {
                    std::map<std::string, double>::iterator lowerBound = _data.lower_bound(date);
                    closestDate = (lowerBound == _data.begin()) ? lowerBound->first : (--lowerBound)->first;
                    exchangeRate = _data[closestDate];
                    break;
                }
            }
            std::cout << (line.substr(0, 11 - 1)) << " => " << (line.substr(11 + 2)) << " = " <<
            (value * exchangeRate) << std::endl;
        }
    }
    file.close();
}

bool BitcoinExchange::validateFormat(const std::string &line) {
    std::stringstream ss(line);
    if (!validateSeparatorAndReturnPosition(line)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    size_t pos = line.find('|');
    std::string date = line.substr(0, pos - 1);
    std::string valueStr = line.substr(pos + 2);

    if (!validateDate(date) || !validateValue(valueStr)) {
        return false;
    }
    //std::cout << "<" << date << ">" << "_|_" << "<" << valueStr << ">" << std::endl;
    return true;
}

bool BitcoinExchange::validateSeparatorAndReturnPosition(const std::string &line) const {
    size_t pos = line.find('|');
    if (pos == std::string::npos || pos == 0 || pos == line.length() - 1)
        return false;
    if (line.find('|', pos + 1) != std::string::npos)
        return false;
    std::size_t sepSpace = line.find(" | ");
    if (sepSpace == std::string::npos)
        return false;
    return true;
}

// FORMAT: "YYYY-MM-DD"
bool BitcoinExchange::validateDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: bad input 35 => " << date << std::endl;
        return false;
    }

    int yearPosition = 0;
    int monthPosition = 5;
    int dayPosition = 8;

    for (; yearPosition < 4; ++yearPosition) {
        if (!isdigit(date[yearPosition])) {
            std::cerr << "Error: bad input 52 => " << date << std::endl;
            return false;
        }
    }
    for (; monthPosition < 7; ++monthPosition) {
        if (!isdigit(date[monthPosition])) {
            std::cerr << "Error: Invalid month in date: " << date << std::endl;
            return false;
        }
    }
    for (; dayPosition < 10; ++dayPosition) {
        if (!isdigit(date[dayPosition])) {
            std::cerr << "Error: Invalid day in date: " << date << std::endl;
            return false;
        }
    }

    std::string savedYear = date.substr(0, 4);
    std::string savedMonth = date.substr(5, 2);
    std::string savedDay = date.substr(8, 2);

    if (savedYear < "2009" || savedYear > "2022") {
        std::cerr << "Error: Year out of range, expected between 2009 and 2022: " << savedYear << std::endl;
        return false;
    }
    if (savedMonth < "01" || savedMonth > "12") {
        std::cerr << "Error: Invalid month, expected between 01 and 12: " << savedMonth << std::endl;
        return false;
    }

    std::stringstream ssYear(savedYear);
    int year;
    ssYear >> year;

    switch (leapYear(year)) {
        case true:
            if (savedMonth == "02" && (savedDay < "01" || savedDay > "29")) {
                std::cerr << "Error: Invalid day for February in leap year: " << savedDay << std::endl;
                return false;
            }
            break;
        case false:
            if (savedMonth == "02" && (savedDay < "01" || savedDay > "28")) {
                std::cerr << "Error: Invalid day for February in non-leap year: " << savedDay << std::endl;
                return false;
            }
            break;
        default:
            break;
    }
    if ((savedMonth == "04" || savedMonth == "06" || savedMonth == "09" || savedMonth == "11") && (savedDay < "01" || savedDay > "30")) {
        std::cerr << "Error: Invalid day for month with 30 days: " << savedDay << std::endl;
        return false;
    }
    if ((savedMonth == "01" || savedMonth == "03" || savedMonth == "05" || savedMonth == "07" || savedMonth == "08" || savedDay == "10" || savedMonth == "12") && (savedDay < "01" || savedDay > "31")) {
        std::cerr << "Error: Invalid day for month with 31 days: " << savedDay << std::endl;
        return false;
    }
    return true;
}

int BitcoinExchange::leapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? true : false;
}

// FORMAT: "float" (e.g., "123.45")
bool BitcoinExchange::validateValue(const std::string &valueStr) const {
    //shoudl not have space
    if (valueStr.find(' ') != std::string::npos) {
        std::cerr << "Error: Invalid value format, spaces are not allowed: " << valueStr << std::endl;
        return false;
    }
    std::stringstream ss(valueStr);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        std::cerr << "Error: Invalid value format, expected a float: " << valueStr << std::endl;
        return false;
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

// *** DATABASE PARSING ***
void BitcoinExchange::databaseParsing() {
    std::ifstream databaseFile("database/data.csv");
    if (!databaseFile.is_open()) {
        throw std::runtime_error("Error: Could not open database file.");
    }
    std::string line;
    std::getline(databaseFile, line);
    if (line != "date,exchange_rate") {
        throw std::runtime_error("Error: Invalid header line in database file, expected 'date, value'");
    }
    while (std::getline(databaseFile, line)){
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            std::cerr << "Error: Invalid line format in database file: " << line << std::endl;
            continue;
        } else {
            std::string data = line.substr(0, pos);
            std::string valueStr = line.substr(pos + 1);
            std::stringstream ssValue(valueStr);
            float value;
            ssValue >> value;
            if (ssValue.fail() || !ssValue.eof()) {
                throw std::runtime_error("Error: Invalid value format in database file, expected a double: " + valueStr);
            }
            _data.insert(std::make_pair(data, value));
        }
    }
    databaseFile.clear();
}
