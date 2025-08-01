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

std::string Contact::checkSetters(std::string value)
{
	if (value.empty())
	{
		print_error("Null value provided");
		return "";
	}
	if (value.length() > 255)
	{
		print_error("Value exceeds maximum length of 255 characters");
		return "";
	}
	if (value.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != std::string::npos)
	{
		print_error("Value contains invalid characters");
		return "";
	}
	if (value.find("  ") != std::string::npos)
	{
		print_error("Value contains consecutive spaces");
		return "";
	}
	return (value);
}

void	Contact::setFirstName()
{
	std::string firstName;

	firstName = "";
	while (1)
	{
		std::getline(std::cin, firstName);
		if (std::cin.eof())
		{
			std::cout << PURPLE "\nEOF signal detected" RESET << std::endl;
			exit(1);
		}
		if (!checkSetters(firstName).empty())
			break ;
		std::cout << "Enter a valid first name: ";
	}
	this->firstName = firstName;
}

void	Contact::setLastName()
{
	std::string lastName;

	lastName = "";
	while (1)
	{
		std::getline(std::cin, lastName);
		if (std::cin.eof())
		{
			std::cout << PURPLE "\nEOF signal detected" RESET << std::endl;
			exit(1);
		}
		if (!checkSetters(lastName).empty())
			break ;
		std::cout << "Enter a valid last name: ";
	}
	this->lastName = lastName;
}

void	Contact::setNickname()
{
	std::string nickname;

	nickname = "";
	while (1)
	{
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << PURPLE "\nEOF signal detected" RESET << std::endl;
			exit(1);
		}
		if (!checkSetters(nickname).empty())
			break ;
		std::cout << "Enter a valid nickname: ";
	}
	this->nickname = nickname;
}

void	Contact::setPhoneNumber()
{
	std::string phoneNumber;

	phoneNumber = "";
	while (1)
	{
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
		{
			std::cout << PURPLE "\nEOF signal detected" RESET << std::endl;
			exit(1);
		}
		if (!checkSetters(phoneNumber).empty())
			break ;
		std::cout << "Enter a valid phone number: ";
	}
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret()
{
	std::string darkestSecret;

	darkestSecret = "";
	while (1)
	{
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
		{
			std::cout << PURPLE "\nEOF signal detected" RESET << std::endl;
			exit(1);
		}
		if (!checkSetters(darkestSecret).empty())
			break ;
		std::cout << "Enter a valid darkest secret: ";
	}
	this->darkestSecret = darkestSecret;
}


// Getters -----------------------------------------------------------------
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
