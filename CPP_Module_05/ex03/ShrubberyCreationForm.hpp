#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &obj);
        virtual ~ShrubberyCreationForm();

        void execute(const Bureaucrat &executor) const;
        AForm *clone(const string &target) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
