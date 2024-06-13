#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const string target);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm &operator = (const RobotomyRequestForm &obj);
        virtual ~RobotomyRequestForm();

        void execute(const Bureaucrat &executor) const;
        AForm *clone(const string &target) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
