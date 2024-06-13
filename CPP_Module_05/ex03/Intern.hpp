#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    AForm	*form[3];
public:
    Intern();
    Intern(const Intern &obj);
    Intern &operator = (const Intern &obj);
    virtual ~Intern();

    AForm *makeForm(const string &formName, const string &target);
    class FormNotFoundException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif //INTERN_HPP
