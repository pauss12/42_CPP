#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl	harl;

	harl = Harl();
	if (argc < 2)
	{
		std::cout << RED "ERROR" RESET << std::endl;
		std::cout << ORANGE "Usage: ./harl < MESSAGE LEVEL >" RESET << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}