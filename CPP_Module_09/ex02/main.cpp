#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    try {
        for (int i = 1; i < argc; ++i) {
            int number = std::stoi(argv[i]);
            if (number < 0) {
                std::cerr << "Error: Negative numbers are not allowed." << std::endl;
                return 1;
            }
            sequence.push_back(number);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: Invalid input." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;
    pmergeMe.sortAndMeasure(sequence);

    std::list<int> listSequence(sequence.begin(), sequence.end());
    pmergeMe.sortAndMeasure(listSequence);

    return 0;
}
