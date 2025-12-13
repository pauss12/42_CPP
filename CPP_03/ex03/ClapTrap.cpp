/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:37:53 by pmendez-          #+#    #+#             */
/*   Updated: 2025/12/13 18:34:39 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	setName("");
	setEnergyPoints(10);
	setHitPoints(10);
	setAttackDamage(0);
	std::cout << BLUE << "ClapTrap " << this->getName() << " has been created with default constructor" << RESET <<  std::endl;
}
	
ClapTrap::ClapTrap(std::string name)
{
	setName(name);
	setEnergyPoints(10);
	setHitPoints(10);
	setAttackDamage(0);
	std::cout << BLUE << "ClapTrap " << this->getName() << " has been created with name constructor" << RESET <<  std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &orig)
{
	*this = orig;
	std::cout << BLUE << "ClapTrap " << this->getName() << " has been created with copy constructor" << RESET <<  std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& orig)
{
	//Se comprueba si es la misma direccion de memoria
	if (this != &orig)
	{
		setName(orig.getName());
		setHitPoints(orig.getHitPoints());
		setEnergyPoints(orig.getEnergyPoints());
		setAttackDamage(orig.getAttackDamage());
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << PURPLE << "ClapTrap " << this->getName() << " has been destroyed" << RESET << std::endl;
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

// FUNCTIONS -----------------------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << GREEN << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ClapTrap " << this->getName() << " has no energy points or hit points left to attack." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << RED << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage and is now destroyed!" << RESET << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << YELLOW << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage and now has " << this->getHitPoints() << " hit points left." << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << LIGHT_GREEN << "ClapTrap " << this->getName() << " has been repaired by " << amount << " points and now has " << this->getHitPoints() << " hit points." << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ClapTrap " << this->getName() << " has no energy points or hit points left to repair." << RESET << std::endl;
}
