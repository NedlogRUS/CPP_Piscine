#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <chrono>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: Invalid input. All numbers must be positive integers." << std::endl;
            return 1;
        }
        vec.push_back(num);
    }

    std::list<int> lst;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: Invalid input. All numbers must be positive integers." << std::endl;
            return 1;
        }
        lst.push_back(num);
    }

    std::cout << "Vector:" << std::endl;
    PmergeMe::FordJonsonMergeInsortionSort(vec);

    std::cout << "List:" << std::endl;
    PmergeMe::FordJonsonMergeInsortionSort(lst);

//    template<class T>
//    int sort_helper(T container) {
//        return 0;
//    }
//
//    template<class T>
//    int sort(T container) {
//        T less;
//
//        T more;
//
//        for (int i = 0; i < container.size(); i++) {
//            if (container[i] < container[0]) {
//                less.push_back(container[i]);
//            } else {
//                more.push_back(container[i]);
//            }
//        }
//
//        sort_helper(more);
//
//        return container[0];
//    }

//    std::cout << "Before:";
//    printContainer(vec);
//
//    // Измерение времени до выполнения сортировки для std::vector
//    std::chrono::steady_clock::time_point start_vector = std::chrono::steady_clock::now();
//
//    // Вызов сортировки для std::vector
//    PmergeMe sorter_vector;
//    sorter_vector.sort(vec);
//
//    // Измерение времени после выполнения сортировки для std::vector
//    std::chrono::steady_clock::time_point end_vector = std::chrono::steady_clock::now();
//
//    std::cout << "After:";
//    printContainer(vec);
//
//    // Вычисление времени выполнения в микросекундах для std::vector
//    std::chrono::duration<double, std::micro> elapsed_seconds_vector = end_vector - start_vector;
//
//    // Вывод времени выполнения сортировки в микросекундах для std::vector
//    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
//              << elapsed_seconds_vector.count() << " us" << std::endl;
//
//    // Для std::list
//    std::list<int> lst(vec.begin(), vec.end());
//
//    std::cout << "Before:";
//    printContainer(lst);
//
//    // Измерение времени до выполнения сортировки для std::list
//    std::chrono::steady_clock::time_point start_list = std::chrono::steady_clock::now();
//
//    // Вызов сортировки для std::list
//    PmergeMe sorter_list;
//    sorter_list.sort(lst);
//
//    // Измерение времени после выполнения сортировки для std::list
//    std::chrono::steady_clock::time_point end_list = std::chrono::steady_clock::now();
//
//    std::cout << "After:";
//    printContainer(lst);
//
//    // Вычисление времени выполнения в микросекундах для std::list
//    std::chrono::duration<double, std::micro> elapsed_seconds_list = end_list - start_list;
//
//    // Вывод времени выполнения сортировки в микросекундах для std::list
//    std::cout << "Time to process a range of " << lst.size() << " elements with std::list : "
//              << elapsed_seconds_list.count() << " us" << std::endl;

    return 0;
}
