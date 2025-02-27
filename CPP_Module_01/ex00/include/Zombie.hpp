#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        void announce(void);
    private:
        std::string name;
};

#endif