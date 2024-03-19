#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap defaultScavTrap;
    ScavTrap Bear("Bear");
    ScavTrap Wolf("Wolf");
    Bear.attack("Wolf");
    Wolf.takeDamage(20);
    Wolf.beRepaired(10);
    Wolf.guardGate();
    Bear.attack("ScavTrap");
    defaultScavTrap.takeDamage(20);
    ScavTrap Temp = Bear;
    return 0;
}