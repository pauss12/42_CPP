#include "Zombie.hpp"

int main()
{
	std::cout << std::endl << YELLOW << "----- CREATING ZOMBIE CALLED PAULA -----" << RESET << std::endl;
	Zombie zombie1("Paula");
	zombie1.announce();

	std::cout << std::endl << YELLOW << "----- CREATING ZOMBIE WITHOUT NAME AM THEN ASSIGNING TO FRANK -----" << RESET << std::endl;
	Zombie zombie2;
	zombie2.setName("Frank");
	zombie2.announce();

	std::cout << std::endl << YELLOW << "----- CREATING A HORDE OF 5 ZOMBIES -----" << RESET <<  std::endl;
	Zombie *zombiesArmy = zombieHorde(5, "Zombie ");
	if (!zombiesArmy)
	{
		std::cout << RED << "Error: Zombie horde creation failed." << RESET << std::endl;
		return (1);
	}

	for (int i = 0; i < 5; i++)
		zombiesArmy[i].announce();

	std::cout << std::endl << YELLOW << "----- DELETING ZOMBIE HORDE -----" << RESET << std::endl;
	delete [] zombiesArmy;

	std::cout << std::endl << YELLOW << "----- TRYING TO ANNOUNCE ZOMBIES WITH NO NAME -----" << RESET << std::endl;
	Zombie zombie3;
	zombie3.announce();
	
	return (0);
}