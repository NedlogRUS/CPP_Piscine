#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    this->_name = "FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    cout << "FragTrap default constructor" << endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    cout << "FragTrap name constructor" << endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap){
    cout << "FragTrap copy constructor" << endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    cout << "FragTrap assignation operator" << endl;
    ClapTrap::operator=(fragTrap);
    return *this;
}

FragTrap::~FragTrap() {
    cout << "FragTrap destructor" << endl;
}

void FragTrap::attack(std::string const &target) {
    if (this->_energyPoints <= 0) {
        cout << "FragTrap " << this->_name << " has no energy points left to attack!" << endl;
        return;
    }
    if (this->_hitPoints <= 0) {
        cout << "FragTrap " << this->_name << " has no hit points left to attack!" << endl;
        return;
    }
    cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        cout << "FragTrap " << this->_name << " has no hit points left to take damage!" << endl;
        return;
    }
    if (amount > this->_hitPoints)
        amount = this->_hitPoints;
    cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << endl;
    this->_hitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        cout << "FragTrap " << this->_name << " has no hit points left to be repaired!" << endl;
        return;
    }
    if (this->_hitPoints + amount > 100)
        amount = 100 - this->_hitPoints;
    cout << "FragTrap " << this->_name << " is repaired for " << amount << " hit points!" << endl;
    this->_hitPoints += amount;
}

void FragTrap::highFivesGuys(void) {
    cout << "FragTrap " << this->_name << " requests a high five!" << endl;
}