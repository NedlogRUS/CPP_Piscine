#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &obj) {
    if (this == &obj) {
        return *this;
    }
    _grade = obj._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

const string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(AForm &form) const {
    if (form.getSigned()) {
        cout << _name << " cannot sign " << form.getName() << " because it is already signed." << endl;
    } else if (form.getSignGrade() < _grade) {
        cout << _name << " cannot sign " << form.getName() << " because bureaucrat's grade is too low." << endl;
    } else {
        cout << _name << " signs " << form.getName() << endl;
        form.beSigned(*this);
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    if (!form.getSigned()) {
        cout << _name << " cannot execute " << form.getName() << " because it is not signed." << endl;
    } else if (form.getExecGrade() < _grade) {
        cout << _name << " cannot execute " << form.getName() << " because bureaucrat's grade is too low." << endl;
    } else {
        cout << _name << " executes " << form.getName() << endl;
        form.execute(*this);
    }
}