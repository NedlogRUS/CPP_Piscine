#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Jagermeister"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    cout << "ClapTrap default constructor called" << endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    cout << "ClapTrap name constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    cout << "ClapTrap copy constructor called" << endl;
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &clapTrap) {
        this->_name = clapTrap._name;
        this->_hitPoints = clapTrap._hitPoints;
        this->_energyPoints = clapTrap._energyPoints;
        this->_attackDamage = clapTrap._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
    if (this->_energyPoints <= 0) {
        cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << endl;
        return;
    }
    if (this->_hitPoints <= 0) {
        cout << "ClapTrap " << this->_name << " has no hit points left to attack!" << endl;
        return;
    }
    cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        cout << "ClapTrap " << this->_name << " has no hit points left to take damage!" << endl;
        return;
    }
    if (amount > this->_hitPoints)
        amount = this->_hitPoints;
    cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << endl;
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        cout << "ClapTrap " << this->_name << " has no hit points left to be repaired!" << endl;
        return;
    }
    if (this->_hitPoints + amount > 10)
        amount = 10 - this->_hitPoints;
    cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << endl;
    this->_hitPoints += amount;
}

