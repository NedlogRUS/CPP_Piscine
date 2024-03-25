#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
    AMateria *_materias[4];
    int _materiasCount;
public:
    MateriaSource();
    MateriaSource(const MateriaSource &materiaSource);
    MateriaSource &operator=(const MateriaSource &materiaSource);
    ~MateriaSource();
    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif //MATERIASOURCE_HPP
