#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T const & element) {
    std::cout << element << std::endl;
}

template <typename T>
void iter(T* array, size_t length, void (*f)(const T &)) {
    for (size_t i = 0; i < length; ++i) {
        f(array[i]);
    }
}

template <typename T, typename F>
void iter(T* array, size_t length, void (*f)(const F &)) {
    for (size_t i = 0; i < length; ++i) {
        f(array[i]);
    }
}

#endif //ITER_HPP
