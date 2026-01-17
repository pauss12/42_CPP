#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << YELLOW << "---------- CREACION TROOPY COMO DIAMOND TRAP --------------- " << RESET << std::endl;
	DiamondTrap*	troopy = new DiamondTrap("Troopy");
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY HIGH FIVE --------------- " << RESET << std::endl;
	troopy->highFivesGuys();
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY TELLS WHO HE IS --------------- " << RESET << std::endl;
	troopy->whoAmI();
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY ATTACKS  --------------- " << RESET << std::endl;
	troopy->attack("target");
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY GUARDS GATE --------------- " << RESET << std::endl;
	troopy->guardGate();
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY IS BEING REPAIRED --------------- " << RESET << std::endl;
	troopy->beRepaired(10);
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY TAKES DAMAGE --------------- " << RESET << std::endl;
	troopy->takeDamage(5);
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY ATTACKS --------------- " << RESET << std::endl;
	troopy->attack("target2");
	std::cout << std::endl;

	std::cout << YELLOW << "---------- TROOPY BEING DELETED --------------- " << RESET << std::endl;
	delete troopy;
	std::cout << std::endl;
	return (0);
}