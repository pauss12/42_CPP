
# include "utils.hpp"

void print_column(std::string text, int width)
{
	int len;

	if (width <= 0)
		return ;
	if (text.empty())
	{
		std::cout << std::string(width, ' ');
		return ;
	}
    len = text.length();
	if (len > width)
	{
		for (int i = 0; i < width - 1; i++)
		{
			std::cout << text[i];
		}
		std::cout << ".";
	}
	else
	{
		for (int i = 0; i < width - len; i++)
		{
			std::cout << " ";
		}
		std::cout << text;
	}
}

void print_error(std::string error)
{
	std::cerr << RED << "Error: " RESET << std::endl << error << std::endl << std::endl;
}

