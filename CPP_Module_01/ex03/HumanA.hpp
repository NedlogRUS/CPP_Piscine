#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
    string	_name;
    Weapon	&_weapon;

public:
    HumanA(const string &name, Weapon &type);
    void	attack(void);
    ~HumanA();
};

#endif //HUMANA_HPP
