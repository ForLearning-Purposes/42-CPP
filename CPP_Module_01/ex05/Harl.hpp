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

# endif