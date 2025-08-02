
# include "Replace.hpp"

static int check_arguments(std::string filename, std::string lookFor, std::string replaceWith)
{
	if (filename.empty())
	{
		std::cout << RED "Error" RESET << std::endl << "Filename is empty" << std::endl;
		return (1);
	}
	if (lookFor.empty())
	{
		std::cout << RED "Error" RESET << std::endl << "lookFor is empty" << std::endl;
		return (1);
	}
	if (replaceWith.empty())
	{
		std::cout << RED "Error" RESET << std::endl << "replaceWith is empty" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::string filename;
	std::string lookFor;
	std::string replaceWith;

	if (argc != 4)
	{
		std::cout << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		std::cout << ORANGE << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << RESET << std::endl;
		return (1);
	}
	filename = argv[1];
	lookFor = argv[2];
	replaceWith = argv[3];
	if (check_arguments(filename, lookFor, replaceWith) == 1)
		return (1);
	Replace replaced(filename, lookFor, replaceWith);
	replaced.CreateNewFile();

	return (0);
}