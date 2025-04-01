#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <cstdlib>

/*
•RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

/*
********************************************************************************************************************************************************************
*/

// Constructors and destructors:

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "\nDefault constructor called for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "\nConstructor with target called for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
    std::cout << "\nCopy constructor called for RobotomyRequestForm" << std::endl;
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    std::cout << "\nCopy assignment operator called for RobotomyRequestForm" << std::endl;
    if (&copy == this) {
        return *this;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "\nDestructor called for RobotomyRequestForm" << std::endl;
}

/*
********************************************************************************************************************************************************************
*/

// Getters and setters:

const std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

//AForm getters

const std::string RobotomyRequestForm::getAFormName() const {
    return AForm::getName();
}

bool RobotomyRequestForm::getAFormSigned() const {
    return AForm::getSigned();
}

int RobotomyRequestForm::getAFormSignGrade() const {
    return AForm::getSignGrade();
}

int RobotomyRequestForm::getAFormExecGrade() const {
    return AForm::getExecGrade();
}

/*
********************************************************************************************************************************************************************
*/

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    if (executor.getGrade() > AForm::getExecGrade()) {
        std::cout << executor.getName() << " couldn't execute " << this->getAFormName() << std::endl;
        return;
    }
    executeAction();
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Drilling noises..." << std::endl;
    srand(time(0));
    int random = rand() % 2;
    if (random == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << this->_target << "." << std::endl;
    }
}

void RobotomyRequestForm::printAForm() const {
    AForm::printForm();
}

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& rhs) {
    os << "\n***RobotomyRequestForm:\nTarget: " << rhs.getTarget() << std::endl;
    return os;
}