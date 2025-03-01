#include "../include/Zombie.hpp"
#include <iostream>

int main(void)
{
    int N = 5;
    Zombie *zombies = zombieHorde(N, "Zombie");
    if (zombies == NULL)
    {
        std::cout << "Failed to create a new Zombie horde in main function." << std::endl;
        return 1;
    }
    std::cout << "\nZombie returned from zombieHorde function: " << zombies->getName() << "\n" << std::endl;
    delete[] zombies;
    return 0;
}