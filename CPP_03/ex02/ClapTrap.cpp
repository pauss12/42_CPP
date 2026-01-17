/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:37:53 by pmendez-          #+#    #+#             */
/*   Updated: 2026/01/17 17:16:34 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	setName("");
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
	std::cout << CYAN << "ClapTrap " << this->getName() << " has been created with default constructor" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	setName(name);
	setHitPoints(10);
	setEnergyPoints(10);
	setAttackDamage(0);
	std::cout << CYAN << "ClapTrap " << this->getName() << " has been created with name constructor" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &orig)
{
	setName(orig._name);
	setHitPoints(orig._hitPoints);
	setEnergyPoints(orig._energyPoints);
	setAttackDamage(orig._attackDamage);
	std::cout << CYAN << "ClapTrap" << this->getName() << " has been created with copy constructor " << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& orig)
{
	//Se comprueba si es la misma direccion de memoria
	if (this != &orig)
	{
		setName(orig._name);
		setHitPoints(orig._hitPoints);
		setEnergyPoints(orig._energyPoints);
		setAttackDamage(orig._attackDamage);
	}
	std::cout << CYAN << "ClapTrap " << this->getName() << " has been created with assignment operator " << RESET << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << PURPLE << "ClapTrap " << this->getName() << " has been destroyed" << RESET << std::endl;
}

// FUNCTIONS -----------------------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		setEnergyPoints(this->_energyPoints - 1);
		std::cout << GREEN << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ClapTrap " << this->getName() << " has no energy points or hit points left to attack." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() <= amount)
	{
		setHitPoints(0);
		std::cout << RED << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage and is now destroyed!" << RESET << std::endl;
	}
	else
	{
		setHitPoints(this->_hitPoints - amount);
		std::cout << YELLOW << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage and now has " << this->getHitPoints() << " hit points left." << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() > 0 && this->getHitPoints() > 0)
	{
		setHitPoints(this->_hitPoints + amount);
		setEnergyPoints(this->_energyPoints - 1);
		std::cout << LIGHT_GREEN << "ClapTrap " << this->getName() << " has been repaired by " << amount << " points and now has " << this->getHitPoints() << " hit points." << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ClapTrap " << this->getName() << " has no energy points or hit points left to repair." << RESET << std::endl;
}

// GETTERS ------------------------------------
std::string ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

// SETTERS ------------------------------------

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}
