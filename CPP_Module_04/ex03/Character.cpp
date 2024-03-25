#include "Character.hpp"

Character::Character() : name("default"){
    cout << "Character default constructor called" << endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::Character(string const &name) : name(name){
    cout << "Character name constructor called" << endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::Character(const Character &character) : name(character.name){
    cout << "Character copy constructor called" << endl;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
    *this = character;
}

Character &Character::operator=(const Character &character) {
    cout << "Character assignation operator called" << endl;
    if (this != &character) {
        this->name = character.name;
        for (int i = 0; i < 4; i++) {
            if (materias[i])
                delete materias[i];
            materias[i] = character.materias[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    cout << "Character destructor called" << endl;
    for (int i = 0; i < 4; i++) {
        if (materias[i])
            delete materias[i];
    }
}

string const &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!materias[i]) {
            materias[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && materias[idx])
        materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && materias[idx])
        materias[idx]->use(target);
}
