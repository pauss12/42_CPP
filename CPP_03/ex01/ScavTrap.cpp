# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << CYAN << "ScavTrap " << this->_name << " has been created with default constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << CYAN << "ScavTrap " << this->_name << " has been created with name constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &orig) : ClapTrap(orig)
{
	*this = orig;
	std::cout << CYAN << "ScavTrap " << this->_name << " has been created with copy constructor" << RESET <<  std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap &orig)
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

ScavTrap::~ScavTrap(void)
{
	std::cout << PURPLE << "ScavTrap " << this->_name << " has been destroyed" << RESET << std::endl;
}

// FUNCTIONS -----------------------------------
void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << GREEN << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "ScavTrap " << this->_name << " has no energy points or hit points left to attack." << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << LIGHT_BLUE << "ScavTrap " << this->_name << " is now in Gate keeper mode." << RESET << std::endl;
}
