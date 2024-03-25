#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiasCount(0){
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    for (int i = 0; i < _materiasCount; i++)
        _materias[i] = materiaSource._materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this == &materiaSource)
        return *this;
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
            delete _materias[i];
        _materias[i] = materiaSource._materias[i];
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (_materiasCount < 4) {
        _materias[_materiasCount] = m;
        _materiasCount++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < _materiasCount; i++) {
        if (_materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}
