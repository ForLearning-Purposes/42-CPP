#include "../include/Zombie.hpp"

//This function creates a zombie, names it, and returns it
//so you can use it outside of the function scope
Zombie* newZombie( std::string name )
{
    Zombie *zombie = new Zombie(name);
    if (zombie == NULL)
    {
        std::cout << "Failed to create a new Zombie in newZombie function." << std::endl;
        return NULL;
    }
    zombie->setName(name);
    return zombie;
}
/*
So in the newZombie function, we create a new Zombie object on the heap and return it.
It needs to be created on the heap because we want to use it outside of the function scope.
And we can't return a stack object because it will be destroyed when the function ends.
This is because the stack memory is deallocated when the function ends.
*/