#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

bool isNumber(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (!isNumber(arg)) {
            std::cerr << "Error: Invalid input. All inputs must be positive integers." << std::endl;
            return 1;
        }

        int num = std::atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: Invalid input. All numbers must be positive integers." << std::endl;
            return 1;
        }

        vec.push_back(num);
        lst.push_back(num);
    }

    std::chrono::steady_clock::time_point start_vector = std::chrono::steady_clock::now();
    PmergeMe::FordJonsonValidator(vec);
//    std::cout << "Vector:" << std::endl;
    std::cout << "Before:   ";
    PmergeMe::printContainer(vec);
    PmergeMe::FordJonsonMergeInsortionSort(vec);
    std::cout << "After:   ";
    PmergeMe::printContainer(vec);
    std::chrono::steady_clock::time_point end_vector = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed_seconds_vector = end_vector - start_vector;
    std::cout << "Time to process a range of  " << vec.size() << " elements with std::vector : "
              << elapsed_seconds_vector.count() << " us" << std::endl;

    std::chrono::steady_clock::time_point start_list = std::chrono::steady_clock::now();
    PmergeMe::FordJonsonValidator(lst);
//    std::cout << "List:" << std::endl;
//    std::cout << "Before:   ";
//    PmergeMe::printContainer(lst);
    PmergeMe::FordJonsonMergeInsortionSort(lst);
//    std::cout << "After:   ";
//    PmergeMe::printContainer(lst);
    std::chrono::steady_clock::time_point end_list = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed_seconds_list = end_list - start_list;
    std::cout << "Time to process a range of  " << lst.size() << " elements with std::list : "
              << elapsed_seconds_list.count() << " us" << std::endl;

    return 0;
}
