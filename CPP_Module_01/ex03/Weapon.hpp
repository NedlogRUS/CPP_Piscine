#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Weapon {
    private:
    string _type;
    public:
    Weapon();
    Weapon(string type);
    void setType(string name);
    const string getType();
    ~Weapon();
};

#endif //WEAPON_HPP
