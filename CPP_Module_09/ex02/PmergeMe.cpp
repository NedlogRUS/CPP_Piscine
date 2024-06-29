#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

template<typename Container>
void PmergeMe::mergeInsertSort(Container& container) {
    if (container.size() <= 1) return;

    typename Container::iterator middle = container.begin();
    std::advance(middle, container.size() / 2);
    Container left(container.begin(), middle);
    Container right(middle, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    container.clear();
    merge(left, right, container);
}

template<typename Container>
void PmergeMe::merge(Container& left, Container& right, Container& result) {
    typename Container::iterator it1 = left.begin();
    typename Container::iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }

    result.insert(result.end(), it1, left.end());
    result.insert(result.end(), it2, right.end());
}

template<typename Container>
void PmergeMe::printSequence(const std::string& message, const Container& container) {
    std::cout << message;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe::measureTime(const std::string& containerName, Container container) {
    std::clock_t start = std::clock();
    mergeInsertSort(container);
    std::clock_t end = std::clock();
    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    printSequence("After: ", container);
    std::cout << "Time to process with " << containerName << ": " << duration << " us" << std::endl;
}

void PmergeMe::sortAndMeasure(const std::vector<int>& sequence) {
    std::vector<int> vectorSequence = sequence;
    printSequence("Before: ", vectorSequence);
    measureTime("std::vector", vectorSequence);
}

void PmergeMe::sortAndMeasure(const std::list<int>& sequence) {
    std::list<int> listSequence = sequence;
    printSequence("Before: ", listSequence);
    measureTime("std::list", listSequence);
}
