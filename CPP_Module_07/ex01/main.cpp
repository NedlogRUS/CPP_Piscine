#include "iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Testing int array:" << std::endl;
    iter(intArray, 5, print<int>);

    std::cout << "Testing char array:" << std::endl;
    iter(charArray, 5, print<char>);

    std::cout << "Testing double array:" << std::endl;
    iter(doubleArray, 5, print<double>);

    return 0;
}