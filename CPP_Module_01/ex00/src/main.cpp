#include "../include/Zombie.hpp"
#include <iostream>

int main(void)
{
    // this is a heap zombie
    Zombie *heapZombie = newZombie("Zombie1");
    if (heapZombie == NULL)
    {
        std::cout << "Failed to create a new Zombie in main function." << std::endl;
        return 1;
    }
    delete heapZombie;
    // this is a stack zombie
    randomChump("Zombie2");
    return 0;
}