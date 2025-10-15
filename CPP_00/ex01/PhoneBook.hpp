/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:06:47 by pmendez-          #+#    #+#             */
/*   Updated: 2025/10/15 21:06:49 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};

#endif
