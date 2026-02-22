#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << RED << "ERROR" << RESET << std::endl;
		std::cout << ORANGE << "Usage: " << argv[0] << " <literal>" << RESET << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}