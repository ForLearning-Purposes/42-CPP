#include "../include/Zombie.hpp"
#include <sstream>

//It must allocate N Zombie objects in a single allocation. Then, it must initialize the
//zombies, giving each of them the name passed as a parameter. The function returns a
//pointer to the first zombie
Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        std::stringstream ss;
        ss << name << i + 1;
        zombies[i].setName(ss.str());
        zombies[i].announce();
    }
    //return the address of the first zombie
    return zombies;
}