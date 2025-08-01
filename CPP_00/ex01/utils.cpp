
# include "PhoneBook.hpp"

void print_column(const char *text, int width)
{
	int len;

	if (width <= 0)
		return ;
	if (text == nullptr)
	{
		std::cout << std::string(width, ' ');
		return ;
	}
    len = strlen(text);
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

//