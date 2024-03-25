#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    this->_type = "WrongCat";
    cout << "WrongCat constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
    cout << "WrongCat copy constructor called" << endl;
    *this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
    cout << "WrongCat assignation operator called" << endl;
    if (this != &wrongCat)
        this->_type = wrongCat.getType();
    return *this;
}

WrongCat::~WrongCat() {
    cout << "WrongCat destructor called" << endl;
}

void WrongCat::makeSound() const {
    cout << "Wrong-Meow" << endl;
}