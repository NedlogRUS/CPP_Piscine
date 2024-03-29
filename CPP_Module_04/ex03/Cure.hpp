#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria{
public:
    Cure();
    Cure(const Cure &cure);
    Cure &operator=(const Cure &cure);
    virtual ~Cure();
    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif //CURE_HPP
