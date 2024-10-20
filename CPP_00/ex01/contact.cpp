#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
	return ;
}

Contact::~Contact()
{
	return ;
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickname()
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}

static void print_column(const char *text, int width)
{
	int len = strlen(text);
	if (len > width)
	{
		// Trunca y reemplaza el último carácter con un '.'
		for (int i = 0; i < width - 1; i++)
		{
			std::cout << text[i];
		}
		std::cout << ".";
	}
	else
	{
		// Alinea el texto a la derecha
		for (int i = 0; i < width - len; i++)
		{
			std::cout << " ";
		}
		std::cout << text;
	}
}

