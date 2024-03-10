#include "Zombie.hpp"

Zombie::Zombie(){
    _name = "Ned";
}

void Zombie::setName(string name){
    _name = name;
}

string Zombie::getName(){
    return _name;
}

void Zombie::announce(void){
    cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie(){
    cout << "*shotgun sound* zombie " << _name << " was destroyed" << endl;
}
