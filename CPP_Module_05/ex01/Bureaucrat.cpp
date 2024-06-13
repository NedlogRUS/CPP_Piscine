#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        return (*this);
    }
    _grade = obj._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

const string &Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
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
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}

void Bureaucrat::signForm(bool isSigned, const string &formName) const {
    if (isSigned) {
        cout << _name << " signs " << formName << endl;
    } else {
        cout << _name << " cannot sign " << formName << " because ";
        if (_grade > 150) {
            cout << "grade is too low" << endl;
        } else {
            cout << "grade is too high" << endl;
        }
    }
}
