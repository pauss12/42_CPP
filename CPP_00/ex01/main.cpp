/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:50:25 by pmendez-          #+#    #+#             */
/*   Updated: 2025/10/15 20:50:26 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, command);

		if (std::cin.eof())
			return (0);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << RED "Invalid command" RESET << std::endl;
	}
	return (0);
}
