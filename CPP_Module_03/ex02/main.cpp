#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap defaultFragTrap;
    FragTrap Bear("Bear");
    ScavTrap Wolf("Wolf");
    Bear.attack("Wolf");
    Wolf.takeDamage(20);
    Wolf.beRepaired(10);
    Wolf.guardGate();
    Bear.attack("FragTrap");
    defaultFragTrap.takeDamage(20);
    Bear.highFivesGuys();
    FragTrap Temp = Bear;
    return 0;
}