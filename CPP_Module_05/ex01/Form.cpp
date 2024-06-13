#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
}

Form::Form(const string name, int signGrade, int execGrade) : _name(name), _signed(false) {
    if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    }
    _signGrade = signGrade;
    _execGrade = execGrade;
}

Form::Form(const Form &obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {
}

Form &Form::operator = (const Form &obj) {
    if (this == &obj) {
        return (*this);
    }
    _signed = obj._signed;
    _signGrade = obj._signGrade;
    _execGrade = obj._execGrade;
    return (*this);
}

Form::~Form() {}

const string &Form::getName() const {
    return (_name);
}

bool Form::isSigned() const {
    return (_signed);
}

int Form::getSignGrade() const {
    return (_signGrade);
}

int Form::getExecGrade() const {
    return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw GradeTooLowException();
    }
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

const char *Form::FormNotSignedException::what() const throw() {
    return ("Form is not signed");
}

std::ostream &operator << (std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is " << (form.isSigned() ? "" : "not ") << "signed";
    return (out);
}
// Path: CPP_Module_05/ex01/main.cpp