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

        std::map<std::string, double> getData() const;
        const std::string getFilename() const;
        
        private:
        const std::string _filename;
        std::map<std::string, double> _data;
        std::map<std::string, double> _userInputData;

        void parseFile();
        bool validateFormat(const std::string &line);
        bool validateSeparatorAndReturnPosition(const std::string &line) const;
        bool validateDate(const std::string &date) const;
        int leapYear(int year) const;
        bool validateValue(const std::string &valueStr) const;
    
};

#endif