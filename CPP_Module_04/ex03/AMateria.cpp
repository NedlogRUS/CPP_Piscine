#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
    cout << "AMateria constructor called" << endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
    cout << "AMateria constructor called" << endl;
}

AMateria::AMateria(const AMateria &aMateria) {
    cout << "AMateria copy constructor called" << endl;
    *this = aMateria;
}

AMateria &AMateria::operator=(const AMateria &aMateria) {
    cout << "AMateria assignation operator called" << endl;
    if (this != &aMateria)
        this->_type = aMateria.getType();
    return *this;
}

AMateria::~AMateria() {
    cout << "AMateria destructor called" << endl;
}

std::string const &AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter &target){
    (void)target;
}



