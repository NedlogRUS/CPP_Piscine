#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;

class Form {
    private:
        const string _name;
        bool _signed;
        int _signGrade;
        int _execGrade;
    public:
        Form();
        Form(const string name, int signGrade, int execGrade);
        Form(const Form &obj);
        Form &operator = (const Form &obj);
        ~Form();
        const string &getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, const Form &form);

#endif //FORM_HPP
