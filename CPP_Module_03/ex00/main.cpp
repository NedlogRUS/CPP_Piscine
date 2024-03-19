#include "ClapTrap.hpp"

int main() {
    ClapTrap Bear("Bear");
    ClapTrap Wolf("Wolf");
    ClapTrap Default;
    Bear.attack("Wolf");
    Wolf.takeDamage(5);
    Wolf.beRepaired(2);
    Wolf.attack("Bear");
    Bear.takeDamage(5);
    Bear.beRepaired(2);
    Default.beRepaired(10);
//    for (int i = 0; i < 5; i++) {
//        Bear.attack("Wolf");
//        Wolf.takeDamage(2);
//    }
    return 0;
}