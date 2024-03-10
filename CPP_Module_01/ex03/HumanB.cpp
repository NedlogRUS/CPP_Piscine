#include "HumanB.hpp"

HumanB::HumanB(const string name) : _name(name) {}

void HumanB::attack() {
    cout << _name << " attacks with their " << _weapon->getType() << endl;
}

void	HumanB::setWeapon(Weapon &type) {
    _weapon = &type;
}

HumanB::~HumanB() {}