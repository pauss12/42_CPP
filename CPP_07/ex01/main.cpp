#include "iter.hpp"

void add_and_print(int &n)
{
	std::cout << std::endl << CYAN << "El Valor antes del cambio es ==> " << n << RESET << std::endl;
	n = n + 1;
	std::cout << ROSE << "El Valor despues del cambio es ==> " << n << RESET << std::endl;
}

int main(void)
{
	{
		int tab[] = {0, 1, 2, 3, 4};
		iter(tab, 5, add_and_print);
	}

	// Otro test
	{
		std::string tab[] = {"Hola", "Mundo", "Desde", "CPP"};
		iter(tab, 4, add_and_print);
	}

	return (0);
}
