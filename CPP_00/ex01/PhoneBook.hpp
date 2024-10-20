#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;

	public:

		// CONSTRUCTOR --------------------------------------------------
		PhoneBook();

		// DESTRUCTOR --------------------------------------------------
		~PhoneBook();

		void	addContact();
		void	searchContact();

	// METHODS ---------------------------------------------------
	void printContacts(Contact contacts[8], int contactCount);
};

#endif