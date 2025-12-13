/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:37:06 by pmendez-          #+#    #+#             */
/*   Updated: 2025/12/13 17:29:02 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &orig)
{
	*this = orig;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& orig)
{
    //Se comprueba si es la misma direccion de memoria
    if (this != &orig)
    {
		this->_name = orig._name;
		this->_hitPoints = orig._hitPoints;
		this->_energyPoints = orig._energyPoints;
		this->_attackDamage = orig._attackDamage;
    }
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << PURPLE << "ClapTrap " << this->_name << " has been destroyed" << RESET << std::endl;
}

// FUNCTIONS -----------------------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << GREEN << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ClapTrap " << this->_name << " has no energy points or hit points left to attack." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << RED << "ClapTrap " << this->_name << " has taken " << amount << " points of damage and is now destroyed!" << RESET << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << YELLOW << "ClapTrap " << this->_name << " has taken " << amount << " points of damage and now has " << this->_hitPoints << " hit points left." << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << LIGHT_GREEN << "ClapTrap " << this->_name << " has been repaired by " << amount << " points and now has " << this->_hitPoints << " hit points." << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ClapTrap " << this->_name << " has no energy points or hit points left to repair." << RESET << std::endl;
}
