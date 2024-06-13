#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const string target);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &obj);
        virtual ~PresidentialPardonForm();

        void execute(const Bureaucrat &executor) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
