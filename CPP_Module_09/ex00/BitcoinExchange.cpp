#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {}
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream dataFile(filename.c_str());
    if (!dataFile.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(dataFile, line)) {
        std::istringstream iss(line);
        std::string date;
        double rate;
        if (std::getline(iss, date, ',') && (iss >> rate)) {
            exchangeRates[date] = rate;
        }
    }

    dataFile.close();
    return true;
}

bool BitcoinExchange::validateAndProcessFile(const std::string& inputFile) {
    std::ifstream infile(inputFile.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return false;
    }

    std::string line;
    if (std::getline(infile, line)) {
        if (line != "date | value") {
            std::cerr << "Error: first line must be 'date | value'." << std::endl;
            return false;
        }
    }

    while (std::getline(infile, line)) {
        processLine(line);
    }

    infile.close();
    return true;
}

void BitcoinExchange::processLine(const std::string& line) {
    std::istringstream iss(line);
    std::string date, valueStr;
    if (!(std::getline(iss, date, '|') && std::getline(iss, valueStr))) {
        std::cerr << "Error: bad input format => " << line << std::endl;
        return;
    }
    date = date.substr(0, date.find_last_not_of(" ") + 1);
    valueStr = valueStr.substr(valueStr.find_first_not_of(" "));
    if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    if (!isValidValue(valueStr)) {
        return;
    }
    double value = std::atof(valueStr.c_str());
    std::string closestDate = findClosestDate(date);
    double rate = exchangeRates[closestDate];
    double result = value * rate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) return false;

    switch (month) {
        case 2:
            if (day > 29) return false;
            if (day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) return false;
            break;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) {
    char* end;
    double val = std::strtod(value.c_str(), &end);
    if (*end != '\0' || val < 0 || val > 1000) {
        std::cerr << "Error: ";
        if (*end != '\0' || val < 0) {
            std::cerr << "not a positive number.";
        } else {
            std::cerr << "too large a number.";
        }
        std::cerr << std::endl;
        return false;
    }
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first != date) {
        if (it != exchangeRates.begin()) --it;
    }
    return it->first;
}