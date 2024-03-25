#include "Cat.hpp"

Cat::Cat() : Animal(){
    this->type = "Cat";
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat &cat) {
    cout << "Cat copy constructor called" << endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    cout << "Cat assignation operator called" << endl;
    if (this != &cat)
        this->type = cat.getType();
    return *this;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const {
    cout << "Meow-Meow-Meow" << endl;
}
