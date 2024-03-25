#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    cout << "Cure constructor called" << endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure){
    cout << "Cure copy constructor called" << endl;
}

Cure &Cure::operator=(const Cure &cure) {
    cout << "Cure assignation operator called" << endl;
    if (this != &cure)
        this->_type = cure.getType();
    return *this;
}

Cure::~Cure() {
    cout << "Cure destructor called" << endl;
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
