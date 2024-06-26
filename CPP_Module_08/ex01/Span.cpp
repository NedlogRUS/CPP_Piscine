#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(Span const &ref) {
    *this = ref;
}

Span &Span::operator=(Span const &ref) {
    N = ref.N;
    numbers = ref.numbers;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() == N)
        throw std::runtime_error("Span is full");
    numbers.push_back(number);
}

int Span::shortestSpan() {
    if (numbers.size() < 2)
        throw std::runtime_error("Span is too short");
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() {
    if (numbers.size() < 2)
        throw std::runtime_error("Span is too short");
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (numbers.size() + std::distance(begin, end) > N)
        throw std::runtime_error("Span is full");
    numbers.insert(numbers.end(), begin, end);
}

