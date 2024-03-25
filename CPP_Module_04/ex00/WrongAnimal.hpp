#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
protected:
    string _type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &wrongAnimal);
    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
    virtual ~WrongAnimal();
    string getType() const;
    void makeSound() const;
};

#endif //WRONGANIMAL_HPP
