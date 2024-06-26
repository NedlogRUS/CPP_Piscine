#include "Span.hpp"

#include <ctime>
#include <cstdlib>

int main()
{
    Span bigSpan(100000);
    for (int i = 0; i < 100000; ++i) {
        bigSpan.addNumber(rand() % 100000);
    }

    std::cout << "Big Span shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big Span longest span: " << bigSpan.longestSpan() << std::endl;

    try {
        bigSpan.addNumber(1);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    Span smallSpan(1);
    smallSpan.addNumber(1);
    try {
        std::cout << "Small Span shortest span: " << smallSpan.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}