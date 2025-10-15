/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:50:12 by pmendez-          #+#    #+#             */
/*   Updated: 2025/10/15 20:50:14 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Utils.hpp"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:

		Contact();
		~Contact();

		void	setFirstName();
		void	setLastName();
		void	setNickname();
		void	setPhoneNumber();
		void	setDarkestSecret();

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		std::string	checkSetters(std::string value, int isPhoneNumber);
};

#endif
