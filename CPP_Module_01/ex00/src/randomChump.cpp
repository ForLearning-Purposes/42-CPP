#include "../include/Zombie.hpp"
#include <iostream>

//This function creates a zombie, names it, and makes it announce itself.
void randomChump( std::string name )
{
    Zombie zombie = Zombie(name);
    zombie.announce();
    return;
}
/*
So in the randomChump function, we create a new Zombie object on the stack and make it announce itself.
We can create a stack object because we don't need to use it outside of the function scope.
And it will be destroyed when the function ends.
*/