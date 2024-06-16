#include "Intern.hpp"

Intern::Intern() {
    form[0] = new ShrubberyCreationForm("default");
    form[1] = new RobotomyRequestForm("default");
    form[2] = new PresidentialPardonForm("default");
}

Intern::Intern(const Intern &obj) {
    *this = obj;
}

Intern &Intern::operator = (const Intern &obj) {
    if (this == &obj) {
        return *this;
    }
    for (int i = 0; i < 3; i++) {
        delete form[i];
        form[i] = obj.form[i]->clone(obj.form[i]->getTarget());
    }
    return *this;
}

Intern::~Intern() {
    for (int i = 0; i < 3; i++) {
        delete form[i];
    }
}

AForm	*Intern::makeForm(const string &formName, const string &target) {
    string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            cout << "Intern creates " << formName << endl;
            AForm *newForm = form[i]->clone(target);
            return newForm;
        }
    }
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}