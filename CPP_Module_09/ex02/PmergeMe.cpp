#include "PmergeMe.hpp"

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

std::vector<int> PmergeMe::generateJacobsthalSequence(int count) {
    limited in(count);
    std::vector<int> sequence;
    for (int i = 0; i < count; ++i) {
        sequence.push_back(in.gen());
    }
    return sequence;
}