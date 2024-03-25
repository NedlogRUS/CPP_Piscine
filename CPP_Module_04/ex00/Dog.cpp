#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    cout << "Dog constructor called" << endl;
}

Dog::Dog(const Dog &dog) {
    cout << "Dog copy constructor called" << endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    cout << "Dog assignation operator called" << endl;
    if (this != &dog)
        this->type = dog.getType();
    return *this;
}

Dog::~Dog() {
    cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const {
    cout << "Woof-Woof-Woof" << endl;
}
