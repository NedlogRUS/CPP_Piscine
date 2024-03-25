#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    cout << "WrongAnimal constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
    cout << "WrongAnimal copy constructor called" << endl;
    *this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
    cout << "WrongAnimal assignation operator called" << endl;
    if (this != &wrongAnimal)
        this->_type = wrongAnimal.getType();
    return *this;
}

WrongAnimal::~WrongAnimal() {
    cout << "WrongAnimal destructor called" << endl;
}

string WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const {
    cout << "WrongAnimal makes a sound" << endl;
}
