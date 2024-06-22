#ifndef CPP_PISCINE_BASE_HPP
#define CPP_PISCINE_BASE_HPP

#include <iostream>
#include <cstdlib>

class Base {
public:
    virtual ~Base() {};
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif //BASE_HPP
