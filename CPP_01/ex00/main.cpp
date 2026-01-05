#include "Zombie.hpp"

int main(int argc, char **argv)
{
	(void)argv;

	if (argc == 1)
	{
		Zombie *memo = newZombie("Paula");
		memo->announce();
		delete (memo);
		randomChump("Nombre Random");
	}
	else
		std::cout << ORANGE "This program does not need arguments" << RESET << std::endl;
	return (0);
}