#include "HumanA.hpp"

HumanA::HumanA(const string &name, Weapon &type) : _weapon(type) {
    _name = name;
}

void HumanA::attack() {
    cout << _name << " attacks with their " << _weapon.getType() << endl;
}

HumanA::~HumanA() {}