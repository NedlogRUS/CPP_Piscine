#include "Character.hpp"

AMateria *FLOOR[2];
int FLOOR_COUNT = 0;

void dropMateria(AMateria *m) {
    if (FLOOR_COUNT >= 2) {
        cout << "materias are dessapeared from floor" << endl;
        for (int i = 0; i < 2; i++) {
            FLOOR[i] = NULL;
        }
        FLOOR_COUNT = 0;
    }
    if (FLOOR_COUNT < 2) {
        cout << "materia is dropped on the floor" << endl;
        FLOOR[FLOOR_COUNT] = m;
        FLOOR_COUNT++;
    }
}

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
    if (idx >= 0 && idx < 4 && materias[idx]) {
        dropMateria(materias[idx]);
        materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && materias[idx])
        materias[idx]->use(target);
}
