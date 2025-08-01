
# include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		std::cout << ORANGE << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << RESET << std::endl;
		return (1);
	}

	Replace replace(argv[1], argv[2], argv[3]);
	replace.CreateNewFile();

	return (0);
}