#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::map;

class BitcoinExchange {
private:
    map<std::string, double> exchangeRates;
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    string findClosestDate(const std::string& date);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    bool loadData(const std::string& filename);
    bool validateAndProcessFile(const std::string& inputFile);
    void processLine(const std::string& line);
};

#endif //BITCOINEXCHANGE_HPP
