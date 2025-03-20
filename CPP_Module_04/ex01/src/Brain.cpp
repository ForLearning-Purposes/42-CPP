#include "../include/Brain.hpp"
#include <algorithm>

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    std::fill_n(ideas, 100, "");
    // for (int i = 0; i < 100; i++) {
    //     this->ideas[i] = "";
    // }
}


Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy) {
    std::cout << "Brain assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    else {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = copy.getIdea(i);
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        return "**In getIdea() Index out of bounds";
    }
    else
        return ideas[index];
    return "";
}

void Brain::setIdea(int index, std::string idea) {
    if (index < 0 || index >= 100) {
        std::cout << "**In setIdea() Index out of bounds" << std::endl;
        return;
    }
    else
        ideas[index] = idea;
}