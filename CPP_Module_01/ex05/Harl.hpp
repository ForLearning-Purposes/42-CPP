#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

/*
The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. He doesn’t
think twice!
*/
class Harl {
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

int complainLevel(std::string level);

# endif