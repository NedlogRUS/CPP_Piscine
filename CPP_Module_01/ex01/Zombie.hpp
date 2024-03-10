#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Zombie {
private:
    string _name;
public:
    Zombie();
    void setName(string name);
    string getName();
    void announce(void);
    ~Zombie();
};

#endif //ZOMBIE_HPP
