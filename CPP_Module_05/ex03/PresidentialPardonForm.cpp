#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const string target) : AForm("PresidentialPardonForm", 25, 5) {
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &obj) {
    if (this == &obj) {
        return *this;
    }
    AForm::operator=(obj);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!getSigned()) {
        throw FormNotSignedException();
    } else if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
    cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << endl;
}

AForm *PresidentialPardonForm::clone(const string &target) const {
    return new PresidentialPardonForm(target);
}