#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria{
public:
    Ice();
    Ice(const Ice &ice);
    Ice &operator=(const Ice &ice);
    virtual ~Ice();
    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif //ICE_HPP
