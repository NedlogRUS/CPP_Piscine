#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed) {
    cout << "Copy constructor called" << endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    cout << "Assignation operator called" << endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const {
    cout << "getRawBits member function called" << endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    cout << "setRawBits member function called" << endl;
    this->_value = raw;
}
