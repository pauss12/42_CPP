#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << RED << "Error: Number of zombies must be greater than 0." << RESET << std::endl;
		return nullptr;
	}
	Zombie *zombiesArmy = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombiesArmy[i].setName(name + std::to_string(i + 1));
	
	return (zombiesArmy);
}