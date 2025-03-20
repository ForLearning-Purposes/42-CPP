#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        Brain();
        Brain(const Brain &src);
        Brain &operator=(const Brain &src);
        ~Brain();
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
    private:
        std::string ideas[100];
};

#endif