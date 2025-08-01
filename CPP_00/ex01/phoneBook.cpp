#include "PhoneBook.hpp"

//CONSTRUCTOR Y DESTRUCTOR ---------------------------------------------------------------------
PhoneBook::PhoneBook()
{
	contactCount = 0;
	contactId = 0;

	for (int i = 0; i < 8; i++)
	{
		contacts[i] = Contact();
	}
	return;
}

PhoneBook::~PhoneBook()
{
	return ;
}

//ADD CONTACT -----------------------------------------------------------------------------------
void PhoneBook::addContact()
{
	std::string line;

	if (contactCount == 8)
	{
		std::cout << BLUE "The phone book is full. I am going to delete the first contact" RESET << std::endl << std::endl;
		contactId = 0;
	}
	if (std::cin.eof())
			return ;
	std::cout << "Insert first name ==> ";
	if (!std::getline(std::cin, line))
		return;
	contacts[contactId].setFirstName(line);
	std::cout << "Insert last name  ==> ";
	if (!std::getline(std::cin, line))
		return;
	contacts[contactId].setLastName(line);
	std::cout << "Insert nickname ==> ";
	if (!std::getline(std::cin, line))
		return;
	contacts[contactId].setNickname(line);
	std::cout << "Insert phone number ==> ";
	if (!std::getline(std::cin, line))
		return;
	contacts[contactId].setPhoneNumber(line);
	std::cout << "Insert darkest secret ==> ";
	if (!std::getline(std::cin, line))
		return;
	contacts[contactId].setDarkestSecret(line);
	std::cout << GREEN "Contact added successfully." RESET << std::endl << std::endl;
	if (contactCount < 8)
		contactCount++;
	contactId++;
}

//SEARCH CONTACT --------------------------------------------------------------------------------
void PhoneBook::searchContact()
{
	std::string line;
	int index;

	if (contactCount == 0)
	{
		std::cout << ORANGE "There are no contacts to search for." RESET << std::endl << std::endl;
		return;
	}
	if (std::cin.eof())
			return ;
	printContacts(contacts, contactCount);

	std::cout << std::endl;
	std::cout << "Enter the index of the contact you want to see (0-7)\n" << std::endl;
	if (!std::getline(std::cin, line))
		return ;
	if (line.empty() || !std::isdigit(line[0]) || line.length() > 1)
	{
		std::cout << RED "Invalid index\n" RESET << std::endl << std::endl;
		return;
	}
	index = std::atoi(line.c_str());
	if (index >= 0 && index < contactCount)
	{
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl << std::endl;
	}
	else
	{
		std::cout << RED "Invalid index\n" RESET << std::endl << std::endl;
	}
}

void PhoneBook::printContacts(Contact contacts[8], int contactCount)
{
	int column_width;

	column_width = 10;
	std::cout << std::right << std::setw(column_width) << "Index" << " | "
			  << std::setw(column_width) << "First Name" << " | "
			  << std::setw(column_width) << "Last Name" << " | "
			  << std::setw(column_width) << "Nickname" << std::endl;
	std::cout << std::string(50, '-') << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::right << std::setw(column_width) << i << " | ";
		PhoneBook::print_column(contacts[i].getFirstName().c_str(), column_width);
		std::cout << " | ";
		PhoneBook::print_column(contacts[i].getLastName().c_str(), column_width);
		std::cout << " | ";
		PhoneBook::print_column(contacts[i].getNickname().c_str(), column_width);
		std::cout << std::endl;
	}
}