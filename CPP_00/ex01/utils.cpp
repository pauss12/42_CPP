
# include "PhoneBook.hpp"

void PhoneBook::print_column(const char *text, int width)
{
	int len;

    len = strlen(text);
    std::cout << len << std::endl;
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