#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
    Brain *_brain;
public:
    Cat();
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
    virtual ~Cat();
    void makeSound() const;
};

#endif //CAT_HPP
