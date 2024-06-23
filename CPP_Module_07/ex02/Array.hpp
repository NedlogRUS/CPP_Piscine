#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array &operator=(const Array &ref);
    ~Array();
    T &operator[](unsigned int i);
    const T &operator[]( unsigned int i ) const;
    unsigned int size() const;

};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
}

template <typename T>
Array<T>::Array(const Array &copy) : _array(new T[copy._size]), _size(copy._size) {
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &ref) {
    if (this != &ref){
        if (_array)
            delete [] _array;
        _array = new T[ref._size];
        for (unsigned int i = 0; i < ref._size; i++)
            _array[i] = ref._array[i];
        _size = ref._size;
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    if (_array)
        delete [] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_array[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const {
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const {
    return (_size);
}


#endif //ARRAY_HPP
