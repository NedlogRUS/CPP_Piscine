#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

using std::string;

class Bureaucrat;

class AForm {
    private:
        const string _name;
        string _target;
        bool _issigned;
        int const _signGrade;
        int const _execGrade;
    public:
        AForm();
        AForm(const string name, int const signGrade, int const execGrade);
        AForm(const AForm &obj);
        virtual AForm &operator = (const AForm &obj);
        virtual ~AForm();

        virtual const string &getName() const;
        virtual const string &getTarget() const;
        virtual bool getSigned() const;
        virtual int getSignGrade() const;
        virtual int getExecGrade() const;
        virtual void setTarget(const string &target);
        virtual void setSigned(bool issigned);
        virtual void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const = 0;
        virtual AForm *clone(const string &target) const = 0;


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
        class FormNotExecutableException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, const AForm &aform);

#endif //AFORM_HPP
