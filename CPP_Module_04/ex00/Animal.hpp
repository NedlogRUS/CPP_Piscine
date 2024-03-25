#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual ~Animal();
    string getType() const;
    virtual void makeSound() const;
};

#endif //ANIMAL_HPP
