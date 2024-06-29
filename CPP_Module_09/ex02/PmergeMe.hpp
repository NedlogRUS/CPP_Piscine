#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void sortAndMeasure(const std::vector<int>& sequence);
    void sortAndMeasure(const std::list<int>& sequence);

private:
    template<typename Container>
    void mergeInsertSort(Container& container);

    template<typename Container>
    void printSequence(const std::string& message, const Container& container);

    template<typename Container>
    void measureTime(const std::string& containerName, Container container);

    template<typename Container>
    void merge(Container& left, Container& right, Container& result);
};

#endif // PMERGEME_HPP
