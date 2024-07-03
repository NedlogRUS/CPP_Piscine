#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <set>

class PmergeMe {
private:
    template <typename T>
    static void checkDuplicates(T &container);
    template <typename T>
    static bool checkSorted(const T &container);

//    static void
//    static void FordJonsonAlgorithm();
//    int* generateJacobsthalSequence(int n);
public:
    PmergeMe();
    PmergeMe(PmergeMe const &obj);
    PmergeMe &operator=(PmergeMe const &obj);
    ~PmergeMe();

    template <typename T>
    static void FordJonsonMergeInsortionSort(T &container);

};

template <typename T>
void PmergeMe::checkDuplicates(T &container) {
    typedef typename T::value_type ValueType;
    std::set<ValueType> uniqueElements;
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (!uniqueElements.insert(*it).second) {
            std::cout << "Duplicate found: " << *it << std::endl;
            return;
        }
    }
    std::cout << "No duplicates found" << std::endl;
}

template <typename T>
bool PmergeMe::checkSorted(const T &container) {
    typename T::const_iterator it = container.begin();
    if (it == container.end()) return true;
    typename T::const_iterator next = it;
    ++next;
    for (; next != container.end(); ++it, ++next) {
        if (*it > *next) {
            return false;
        }
    }
    return true;
}

template <typename T>
void PmergeMe::FordJonsonMergeInsortionSort(T &container) {
    checkDuplicates(container);
    std::cout << "Container is sorted: " << (checkSorted(container) ? "true" : "false") << std::endl;
//    PmergeMe::checkSorted(T &container);
//    PmergeMe::FordJonsonAlgorithm();
}

#endif // PMERGEME_HPP
