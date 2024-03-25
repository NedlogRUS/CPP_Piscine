#include "Brain.hpp"

Brain::Brain() {
    cout << "Brain constructor called" << endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "IKEA";
    }
}

Brain::Brain(const Brain &brain) {
    cout << "Brain copy constructor called" << endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = brain.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &brain) {
    cout << "Brain assignation operator called" << endl;
    if (this != &brain) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = brain.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    cout << "Brain destructor called" << endl;
}

