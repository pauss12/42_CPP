#include "Zombie.hpp"

int main(int argc, char **argv)
{
	(void)argv;

	if (argc == 1)
	{
		Zombie foo("Foo");
		foo.announce();

		std::cout << std::endl;
		Zombie *memo = newZombie("Paula");
		memo->announce();
		delete (memo);
		std::cout << std::endl;

		randomChump("Nombre Random");
	}
	else
		std::cout << "This program does not need arguments" << std::endl;
	return (0);
}