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

Fixed::Fixed(const int value) {
    cout << "Int constructor called" << endl;
    this->_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    cout << "Float constructor called" << endl;
    this->_value = roundf(value * (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
