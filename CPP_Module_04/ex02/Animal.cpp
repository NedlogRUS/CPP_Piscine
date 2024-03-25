#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    cout << "Animal constructor called" << endl;
}

Animal::Animal(const Animal &animal) {
    cout << "Animal copy constructor called" << endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    cout << "Animal assignation operator called" << endl;
    if (this != &animal)
        this->type = animal.getType();
    return *this;
}

Animal::~Animal() {
    cout << "Animal destructor called" << endl;
}

string Animal::getType() const {
    return this->type;
}
