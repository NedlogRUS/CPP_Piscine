#include "Cat.hpp"

Cat::Cat() : Animal(){
    this->type = "Cat";
    this->_brain = new Brain();
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat &cat) : Animal(cat){
    cout << "Cat copy constructor called" << endl;
    _brain = new Brain();
    *_brain = *cat._brain;
}

Cat &Cat::operator=(const Cat &cat) {
    cout << "Cat assignation operator called" << endl;
    Animal::operator=(cat);
    delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *cat._brain;
    return *this;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
    delete this->_brain;
}

void Cat::makeSound() const {
    cout << "Meow-Meow-Meow" << endl;
}
