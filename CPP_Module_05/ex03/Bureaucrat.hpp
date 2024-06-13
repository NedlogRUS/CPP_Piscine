#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

using std::string;
using std::cout;
using std::endl;

class AForm;

class Bureaucrat {
    private:
        const string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator = (const Bureaucrat &obj);
        virtual ~Bureaucrat();
        const string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form) const;
        void executeForm(const AForm &form) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif //BUREAUCRAT_HPP
