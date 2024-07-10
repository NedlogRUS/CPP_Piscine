#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    BitcoinExchange btcExchange;
    if (!btcExchange.loadData("data.csv")) {
        std::cerr << "Error: could not open data file 'data.csv'." << std::endl;
        return 1;
    }

    if (!btcExchange.validateAndProcessFile(inputFile)) {
        std::cerr << "Error: processing input file failed." << std::endl;
        return 1;
    }

    return 0;
}