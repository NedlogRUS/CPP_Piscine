#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;
public:
    Span();
    Span(unsigned int N);
    Span(Span const &ref);
    Span &operator=(Span const &ref);
    ~Span();
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif //SPAN_HPP
