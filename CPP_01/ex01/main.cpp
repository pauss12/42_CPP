#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Paula");
	zombie1.announce();

	Zombie zombie2;
	zombie2.setName("Frank");
	zombie2.announce();

	Zombie *zombiesArmy = zombieHorde(5, "Zombie ");
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		zombiesArmy[i].announce();

	std::cout << std::endl;

	delete [] zombiesArmy;
	return (0);
}