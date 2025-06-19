#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <sstream>
#include <stdexcept>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &filename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        std::map<std::string, float> getData() const;
        const std::string getFilename() const;

    private:
        const std::string _filename;
        std::map<std::string, float> _data;

        void parseFile();
        void validateFormat(const std::string &line) const;
        size_t validateSeparatorAndReturnPosition(const std::string &line) const;
        void validateDate(const std::string &date) const;
        int leapYear(int year) const;
        void validateValue(const std::string &valueStr) const;
    
};

#endif