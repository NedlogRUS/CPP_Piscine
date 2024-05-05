#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat {
    private:
        const string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator = (const Bureaucrat &obj);
        ~Bureaucrat();
        const string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif //BUREAUCRAT_HPP
