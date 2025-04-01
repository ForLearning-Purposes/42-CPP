#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

/*
•ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.
*/

/*
********************************************************************************************************************************************************************
*/

// Constructors and destructors:

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "\nDefault constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "\nConstructor with target called for ShrubberyCreationForm" << std::endl;
    (void)target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {
    std::cout << "\nCopy constructor called for ShrubberyCreationForm" << std::endl;
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    std::cout << "\nCopy assignment operator called for ShrubberyCreationForm" << std::endl;
    if (&copy == this) {
        return *this;
    }
    //this->_grade = copy._grade;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "\nDestructor called for ShrubberyCreationForm" << std::endl;
}

/*
********************************************************************************************************************************************************************
*/

// Getters and setters:

const std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}


//AForm getters

const std::string ShrubberyCreationForm::getAFormName() const {
    return AForm::getName();
}

bool ShrubberyCreationForm::getAFormSigned() const {
    return AForm::getSigned();
}

int ShrubberyCreationForm::getAFormSignGrade() const {
    return AForm::getSignGrade();
}

int ShrubberyCreationForm::getAFormExecGrade() const {
    return AForm::getExecGrade();
}

/*
********************************************************************************************************************************************************************
*/

void ShrubberyCreationForm::printAForm() const {
    AForm::printForm();
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    if (executor.getGrade() > AForm::getExecGrade()) {
        std::cout << executor.getName() << " couldn't execute " << this->getAFormName() << std::endl;
        return;
    }
    executeAction();
}

void ShrubberyCreationForm::executeAction() const {
    std::cout << "Creating shrubbery in " << this->_target << "_shrubbery" << std::endl;
    
    std::string fileName = this->getTarget() + "_shrubbery";
    std::ofstream file(fileName.c_str(), std::ios::out);
    if (file.fail()) {
        std::cerr << "Error creating file" << std::endl;
        return;
    }
    //ASCII tree
    file << "      ^            ^            ^            ^      \n";
    file << "     ^^^          ^^^          ^^^          ^^^     \n";
    file << "    ^^^^^        ^^^^^        ^^^^^        ^^^^^    \n";
    file << "   ^^^^^^^      ^^^^^^^      ^^^^^^^      ^^^^^^^   \n";
    file << "  ^^^^^^^^^    ^^^^^^^^^    ^^^^^^^^^    ^^^^^^^^^  \n";
    file << " ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^  ^^^^^^^^^^^ \n";
    file << "      |            |            |            |      \n";
    file << "      |            |            |            |      \n";
    file << "                  Have a nice day!                  \n";
    file.close();
}

/*
********************************************************************************************************************************************************************
*/

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& rhs) {
    (void)rhs;
    os << "\n***ShrubberyCreationForm:\nTarget: " << rhs.getTarget() << std::endl;
    return os;
}