#include "Zombie.hpp"

int main()
{
	//Probar la clase Zombie
	Zombie zombie1("Zombie1");
	zombie1.announce();

	std::cout << std::endl;

	//Probar la clase Zombie con el constructor por defecto
	Zombie zombie2;
	zombie2.setName("Zombie2");
	zombie2.announce();

	std::cout << std::endl;

	//Probar la función zombieHorde
	Zombie *zombiesArmy = zombieHorde(5, "Zombie ");
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		zombiesArmy[i].announce();

	std::cout << std::endl;

	delete [] zombiesArmy;
	return (0);
}