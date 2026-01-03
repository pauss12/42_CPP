#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombiesArmy;

	if (N <= 0)
	{
		std::cout << RED << "Error: Number of zombies must be greater than 0" << RESET << std::endl;
		return (NULL);
	}
	zombiesArmy = new Zombie[N];
	if (zombiesArmy == NULL)
	{
		std::cout << RED << "Error: Memory allocation failed." << RESET << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << (i + 1);
		zombiesArmy[i].setName(name + oss.str());
	}
	return (zombiesArmy);
}
