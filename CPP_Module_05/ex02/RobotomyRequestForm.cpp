#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const string target) : AForm("RobotomyRequestForm", 72, 45) {
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &obj) {
    if (this == &obj) {
        return *this;
    }
    AForm::operator=(obj);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    AForm::execute(executor);
    cout << "*drilling noises*" << endl;
    if (rand() % 2) {
        cout << getTarget() << " has been robotomized successfully" << endl;
    } else {
        cout << getTarget() << " robotomization failed" << endl;
    }
}
