#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    cout << "ScavTrap name constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap){
    cout << "ScavTrap copy constructor called" << endl;
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    cout << "ScavTrap assignation operator called" << endl;
    ClapTrap::operator=(scavTrap);
    return *this;
}

ScavTrap::~ScavTrap() {
    cout << "ScavTrap destructor called" << endl;
}

void ScavTrap::attack(std::string const &target) {
    if (this->_energyPoints <= 0) {
        cout << "ScavTrap " << this->_name << " has no energy points left to attack!" << endl;
        return;
    }
    if (this->_hitPoints <= 0) {
        cout << "ScavTrap " << this->_name << " has no hit points left to attack!" << endl;
        return;
    }
    cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        cout << "ScavTrap " << this->_name << " has no hit points left to take damage!" << endl;
        return;
    }
    if (amount > this->_hitPoints)
        amount = this->_hitPoints;
    cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << endl;
    this->_hitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        cout << "ScavTrap " << this->_name << " has no hit points left to be repaired!" << endl;
        return;
    }
    if (this->_hitPoints + amount > 100)
        amount = 100 - this->_hitPoints;
    cout << "ScavTrap " << this->_name << " is repaired for " << amount << " hit points!" << endl;
    this->_hitPoints += amount;
}

void ScavTrap::guardGate() {
    cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode!" << endl;
}