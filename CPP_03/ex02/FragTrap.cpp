# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << BLUE << "FragTrap " << this->_name << " has been created with default constructor" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << BLUE << "FragTrap " << this->getName() << " has been created with name constructor" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &orig) : ClapTrap(orig)
{
	setName(orig._name);
	setHitPoints(orig._hitPoints);
	setEnergyPoints(orig._energyPoints);
	setAttackDamage(orig._attackDamage);
	std::cout << BLUE << "FragTrap " << this->_name << " has been created with copy constructor" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &orig)
{
	//Se comprueba si es la misma direccion de memoria
	if (this != &orig)
	{
		setName(orig._name);
		setHitPoints(orig._hitPoints);
		setEnergyPoints(orig._energyPoints);
		setAttackDamage(orig._attackDamage);
	}
	std::cout << BLUE << "FragTrap " << this->getName() << " has been created with assignment operator " << RESET << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << PURPLE << "FragTrap " << this->getName() << " has been destroyed" << RESET << std::endl;
}

// FUNCTIONS -----------------------------------
void FragTrap::highFivesGuys(void)
{
	std::cout << LIGHT_BLUE << "FragTrap " << this->getName() << " is requesting a high five!" << RESET << std::endl;
}
