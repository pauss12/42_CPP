#include "PhoneBook.hpp"

//CONSTRUCTOR Y DESTRUCTOR ---------------------------------------------------------------------
PhoneBook::PhoneBook()
{
	contactCount = 0;

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

	// If the contactCount is less than 8, the user can add a new contact.
	if (contactCount > 8)
	{
		std::cout << "The phone book is full. I am going to delete the first contact" << std::endl;
		contactCount = 0;
	}

	// Ask the user to enter the contact information.
	std::cout << "Insert first name" << std::endl;
	if (!std::getline(std::cin, line))
		return;

	contacts[contactCount].setFirstName(line);

	std::cout << "Insert last name" << std::endl;
	if (!std::getline(std::cin, line))
		return;
	contacts[contactCount].setLastName(line);

	std::cout << "Insert nickname" << std::endl;
	if (!std::getline(std::cin, line))
		return;
	contacts[contactCount].setNickname(line);

	std::cout << "Insert phone number" << std::endl;
	if (!std::getline(std::cin, line))
		return;
	contacts[contactCount].setPhoneNumber(line);

	std::cout << "Insert darkest secret" << std::endl;
	if (!std::getline(std::cin, line))
		return;
	contacts[contactCount].setDarkestSecret(line);

	std::cout << "Contact added successfully." << std::endl;

	contactCount++;
}

//SEARCH CONTACT --------------------------------------------------------------------------------
void PhoneBook::searchContact()
{
	// If there are no contacts, the user cannot search for a contact.
	if (contactCount == 0)
	{
		std::cout << "There are no contacts to search for.\n" << std::endl;
		return;
	}

	// Display the saved contacts as a list of 4 columns : index, first name, last name and nickname.
	// ◦ Each column must be 10 characters wide.A pipe character(’|’) separates them.The text must be right - aligned.If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot(’.’).
	printContacts(contacts, contactCount);

	// Ask the user to enter the index of the contact he wants to see.
	std::string line;
	std::cout << "Enter the index of the contact you want to see\n"
			  << std::endl;
	if (!std::getline(std::cin, line))
		return;

	// If the index is valid, display the contact information.
	int index = std::atoi(line.c_str());
	if (index >= 0 && index < contactCount)
	{
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "Invalid index\n"
				  << std::endl;
	}
}

//FUNCIONES PARA IMPRIMIR LA LISTA DE CONTACTOS -----------------------------------------------------
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

void PhoneBook::printContacts(Contact contacts[8], int contactCount)
{
	// Display the saved contacts as a list of 4 columns : index, first name, last name and nickname.
	// ◦ Each column must be 10 characters wide.A pipe character(’|’) separates them.The text must be right - aligned.If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot(’.’).

	int contact_count = 4; // Número de contactos
	int column_width = 10; // Ancho de las columnas

	// Imprimir encabezado de la tabla
	std::cout << std::right << std::setw(column_width) << "Index" << " | "
			  << std::setw(column_width) << "First Name" << " | "
			  << std::setw(column_width) << "Last Name" << " | "
			  << std::setw(column_width) << "Nickname" << std::endl;
	std::cout << std::string(44, '-') << std::endl;

	// Imprimir los contactos en formato de tabla
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::right << std::setw(column_width) << i << " | ";
		print_column(contacts[i].getFirstName().c_str(), column_width);
		std::cout << " | ";
		print_column(contacts[i].getLastName().c_str(), column_width);
		std::cout << " | ";
		print_column(contacts[i].getNickname().c_str(), column_width);
		std::cout << std::endl;
	}
}