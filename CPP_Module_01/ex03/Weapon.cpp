#include "Weapon.hpp"

Weapon::Weapon(string type){
    Weapon::_type = type;
}

void Weapon::setType(string type){
    _type = type;
}

const string Weapon::getType(){
    return _type;
}

Weapon::~Weapon(){}