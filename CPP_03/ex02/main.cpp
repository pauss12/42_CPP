#include "FragTrap.hpp"

int main(void)
{
	FragTrap	ft1("Fraggy");
	FragTrap	ft2(ft1);
	FragTrap	ft3;

	ft3 = ft1;

	ft1.attack("Target1");
	ft1.takeDamage(50);
	ft1.beRepaired(30);
	ft1.highFivesGuys();

	return (0);
}