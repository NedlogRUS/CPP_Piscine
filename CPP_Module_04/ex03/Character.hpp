#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter{
private:
    std::string name;
    AMateria *materias[4];
public:
    Character();
    Character(std::string const &name);
    Character(const Character &character);
    Character &operator=(const Character &character);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif //CHARACTER_HPP
