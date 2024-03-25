#include "Dog.hpp"

Dog::Dog() : Animal(){
    this->type = "Dog";
    this->_brain = new Brain();
    cout << "Dog constructor called" << endl;
}

Dog::Dog(const Dog &dog) : Animal(dog){
    cout << "Dog copy constructor called" << endl;
    _brain = new Brain();
    *_brain = *dog._brain;
}

Dog &Dog::operator=(const Dog &dog) {
    cout << "Dog assignation operator called" << endl;
    Animal::operator=(dog);
    delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *dog._brain;
    return *this;
}

Dog::~Dog() {
    cout << "Dog destructor called" << endl;
    delete this->_brain;
}

void Dog::makeSound() const {
    cout << "Woof-Woof-Woof" << endl;
}
