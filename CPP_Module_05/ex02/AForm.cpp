#include "AForm.hpp"

AForm::AForm() : _name("default"), _target("default"), _issigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const string name, int const signGrade, int const execGrade) : _name(name), _target("default"), _issigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw AForm::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &obj) : _name(obj._name), _target(obj._target), _issigned(obj._issigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {}

AForm &AForm::operator = (const AForm &obj) {
    if (this == &obj) {
        return *this;
    }
    _target = obj._target;
    _issigned = obj._issigned;
    return *this;
}

AForm::~AForm() {}

const string &AForm::getName() const {
    return _name;
}

const string &AForm::getTarget() const {
    return _target;
}

bool AForm::getSigned() const {
    return _issigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::setTarget(const string &target) {
    _target = target;
}

void AForm::setSigned(bool issigned) {
    _issigned = issigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
    }
    _issigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!_issigned) {
        throw AForm::FormNotSignedException();
    } else if (executor.getGrade() > _execGrade) {
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

const char *AForm::FormNotExecutableException::what() const throw() {
    return "Form is not executable";
}

std::ostream &operator << (std::ostream &out, const AForm &aform) {
    out << "Form name: " << aform.getName() << std::endl;
    out << "Target: " << aform.getTarget() << std::endl;
    out << "Signed: " << aform.getSigned() << std::endl;
    out << "Sign grade: " << aform.getSignGrade() << std::endl;
    out << "Execution grade: " << aform.getExecGrade() << std::endl;
    return out;
}
