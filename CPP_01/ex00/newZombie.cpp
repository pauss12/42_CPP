#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	if (!zombie)
	{
		std::cerr << RED << "Failed to create Zombie" << RESET << std::endl;
		return (NULL);
	}
	return (zombie);
}