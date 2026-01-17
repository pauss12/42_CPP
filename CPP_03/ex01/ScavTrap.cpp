/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:29:14 by pmendez-          #+#    #+#             */
/*   Updated: 2026/01/17 17:14:12 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << ROSE << "ScavTrap " << this->getName() << " has been created with default constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << ROSE << "ScavTrap " << this->getName() << " has been created with name constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &orig) : ClapTrap(orig)
{
	setName(orig._name);
	setHitPoints(orig._hitPoints);
	setEnergyPoints(orig._energyPoints);
	setAttackDamage(orig._attackDamage);
	std::cout << ROSE << "ScavTrap " << this->getName() << " has been created with copy constructor" << RESET <<  std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap &orig)
{
	//Se comprueba si es la misma direccion de memoria
	if (this != &orig)
	{
		setName(orig._name);
		setHitPoints(orig._hitPoints);
		setEnergyPoints(orig._energyPoints);
		setAttackDamage(orig._attackDamage);
	}
	std::cout << ROSE << "ScavTrap " << this->getName() << " has been created with assignment operator " << RESET << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << PURPLE << "ScavTrap " << this->getName() << " has been destroyed" << RESET << std::endl;
}

// FUNCTIONS -----------------------------------
void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->_energyPoints--;
		std::cout << GREEN << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ScavTrap " << this->getName() << " has no energy points or hit points left to attack." << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << LIGHT_BLUE << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << RESET << std::endl;
}
