#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;
		int		contactId;

	public:

		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
		void	printContacts(Contact contacts[8], int contactCount);
		void	print_column(const char *text, int width);
};

#endif