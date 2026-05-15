#include "iter.hpp"

void add_and_print(int &n)
{
	std::cout << std::endl << CYAN << "El Valor antes del cambio es ==> " << n << RESET << std::endl;
	n = n + 1;
	std::cout << ROSE << "El Valor despues del cambio es ==> " << n << RESET << std::endl;
}

void up_and_print(std::string &str)
{
	std::cout << std::endl << CYAN << "El Valor antes del cambio es ==> " << str << RESET << std::endl;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		else if (std::isupper(str[i]))
			str[i] = std::tolower(str[i]);
		
	}
	std::cout << ROSE << "El Valor despues del cambio es ==> " << str << RESET << std::endl;
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
		iter(tab, 4, up_and_print);
	}

	return (0);
}
