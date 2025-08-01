#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Zombie1");
	zombie1.announce();

	std::cout << std::endl;

	Zombie zombie2;
	zombie2.setName("Zombie2");
	zombie2.announce();

	std::cout << std::endl;

	Zombie *zombiesArmy = zombieHorde(5, "Zombie ");
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		zombiesArmy[i].announce();

	std::cout << std::endl;

	delete [] zombiesArmy;
	return (0);
}