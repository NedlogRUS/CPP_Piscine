#include "PmergeMe.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &obj) {
    *this = obj;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &obj) {
    if (this != &obj) {
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

//template <typename T>
//void PmergeMe::checkDuplicates(T &container) {
//    typedef typename T::value_type ValueType;
//    std::set<ValueType> uniqueElements;
//    typename T::iterator it;
//    for (it = container.begin(); it != container.end(); ++it) {
//        if (!uniqueElements.insert(*it).second) {
//            std::cout << "Duplicate found: " << *it << std::endl;
//            return;
//        }
//    }
//    std::cout << "No duplicates found" << std::endl;
//}
//
//template <typename T>
//bool PmergeMe::checkSorted(const T &container) {
//    typename T::const_iterator it = container.begin();
//    if (it == container.end()) return true;
//    typename T::const_iterator next = it;
//    ++next;
//    for (; next != container.end(); ++it, ++next) {
//        if (*it > *next) {
//            return false;
//        }
//    }
//    return true;
//}

//template <typename T>
//void PmergeMe::FordJonsonMergeInsortionSort(T &container) {
//    PmergeMe::checkDuplicates(container);
//    std::cout << "Container is sorted: " << (heckSorted(container) ? "true" : "false") << std::endl;
////    PmergeMe::checkSorted(T &container);
////    PmergeMe::FordJonsonAlgorithm();
//}