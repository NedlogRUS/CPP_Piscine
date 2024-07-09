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
    static bool checkSize(const T &container);
    template <typename T>
    static bool checkDuplicates(const T &container);
    template <typename T>
    static bool checkSorted(const T &container);
    template <typename T>
    static int checkIsOdd(T &container);
    template <typename T>
    static void splitIntoPairs(const T &container, T &less, T &more);
    template <typename T>
    static int BinarySearch(const T &container, int size, int pand);
    template <typename T>
    static void InsertByBinarySearch(int pand, T &container);

    static std::vector<int> generateJacobsthalSequence(int count);

public:
    PmergeMe();
    PmergeMe(PmergeMe const &obj);
    PmergeMe &operator=(PmergeMe const &obj);
    ~PmergeMe();

    template <typename T>
    static void FordJonsonMergeInsortionSort(T &container);
    template <typename T>
    static void FordJonsonValidator(T &container);
    template <typename T>
    static void printContainer(const T& container);
};

struct jacobs {
    int prevprev;
    int prev;
    jacobs() : prevprev(1), prev(1) {}
    int gen() {
        int curr = prev + 2 * prevprev;

        prevprev = prev;
        prev = curr;

        return curr;
    }
};

struct indicies {
    int max_included;
    int min_excluded;
    int current;
    jacobs j;
    indicies() : max_included(1), min_excluded(0), current(1) {
    }
    int gen() {
        int result = current;
        current--;
        if (current == min_excluded) {
            min_excluded = max_included;
            max_included = j.gen();
            current = max_included;
        }
        return result - 1;
    }
};

struct limited {
    indicies in;
    int n;
    limited(int n) : n(n) {}
    int gen() {
        while (true) {
            int i = in.gen();
            if (i < n) return i;
        }
    }
};

template <typename T>
void PmergeMe::printContainer(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool PmergeMe::checkSize(const T &container) {
    return container.size() > 3000;
}

template <typename T>
bool PmergeMe::checkDuplicates(const T &container) {
    typedef typename T::value_type ValueType;
    std::set<ValueType> uniqueElements;
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (!uniqueElements.insert(*it).second) {
            return true;
        }
    }
    return false;
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
int PmergeMe::checkIsOdd(T &container) {
    if (container.size() % 2 != 0) {
        int lastElement = container.back();
        if (lastElement != 0) {
            container.pop_back();
            return lastElement;
        } else {
            int firstElement = container.front();
            container.erase(container.begin());
            return firstElement;
        }
    }
    return 0;
}

template <typename T>
void PmergeMe::splitIntoPairs(const T &container, T &less, T &more) {
    typename T::const_iterator it = container.begin();
    int half = container.size() / 2;

    for (int i = 0; i < half; ++i) {
        int a = *it++;
        int b = *it++;

        if (a < b) {
            less.push_back(a);
            more.push_back(b);
        } else {
            less.push_back(b);
            more.push_back(a);
        }
    }
}

//splitIntoPairs vol.2
//void PmergeMe::splitIntoPairs(const T &container, T &less, T &more) {
//    if (container.size() % 2 != 0) {
//        std::cerr << "Container size is not even." << std::endl;
//        return;
//    }
//    typename T::const_iterator it = container.begin();
//    typename T::const_reverse_iterator rit = container.rbegin();
//    int half = container.size() / 2;
//    for (int i = 0; i < half; ++i) {
//        int front = *it++;
//        int back = *rit++;
//        int minElement = std::min(front, back);
//        int maxElement = std::max(front, back);
//        less.push_back(minElement);
//        more.push_back(maxElement);
//    }
//}

template <typename T>
void PmergeMe::InsertByBinarySearch(int pair, T &container) {
    typename T::iterator pos = container.begin();
    std::advance(pos, BinarySearch(container, container.size(), pair));
    container.insert(pos, pair);
}

template <typename T>
int PmergeMe::BinarySearch(const T &container, int size, int pair) {
    int left = 0;
    int right = size - 1;
    int middle = 0;
    typename T::const_iterator it_middle;

    while (left <= right) {
        middle = (left + right) / 2;
        it_middle = container.begin();
        std::advance(it_middle, middle);

        if (pair < *it_middle) {
            right = middle - 1;
        } else if (pair > *it_middle) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return left;
}

template <typename T>
void PmergeMe::FordJonsonMergeInsortionSort(T &container) {
    if (container.size() == 0 || container.size() == 1) return;
    int odd = checkIsOdd(container);
    T less;
    T more;
    splitIntoPairs(container, less, more);
    FordJonsonMergeInsortionSort(more);
    std::vector<int> sequence;
    sequence = generateJacobsthalSequence(less.size());
    for (size_t i = 0; i < sequence.size(); ++i) {
        int index = sequence[i];
        if (index < static_cast<int>(less.size())) {
            typename T::iterator it = less.begin();
            std::advance(it, index);
            InsertByBinarySearch(*it, more);
        }
    }
    if (odd != 0) {
        InsertByBinarySearch(odd, more);
    }
    container.clear();
    container = more;
}

template <typename T>
void PmergeMe::FordJonsonValidator(T &container) {
    if(container.size() < 2) {
        std::cerr << "Data is has only one element" << std::endl;
        exit(1);
    }
    if(checkDuplicates(container)) {
        std::cerr << "Data has duplicates" << std::endl;
        exit(1);
    }
    if(checkSorted(container)) {
        std::cerr << "Data is already sorted" << std::endl;
        exit(1);
    }
    if(checkSize(container)) {
        std::cerr << "Size is greater than 3000" << std::endl;
        exit(1);
    }
}

#endif // PMERGEME_HPP
