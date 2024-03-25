#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    cout << "Ice constructor called" << endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice){
    cout << "Ice copy constructor called" << endl;
}

Ice &Ice::operator=(const Ice &ice) {
    cout << "Ice assignation operator called" << endl;
    if (this != &ice)
        this->_type = ice.getType();
    return *this;
}

Ice::~Ice() {
    cout << "Ice destructor called" << endl;
}

AMateria *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
