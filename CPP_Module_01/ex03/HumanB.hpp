#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    string	_name;
    Weapon	*_weapon;

public:
    HumanB(const string name);
    void	attack(void);
    void	setWeapon(Weapon &type);
    ~HumanB();
};

#endif //HUMANB_HPP
