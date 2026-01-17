# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
	ClapTrap("Default '_clap_name'"),
	ScavTrap(),
	FragTrap()
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap " << this->getName() << " has been created with default constructor" <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap(),
	_name(name)
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap " << this->getName() << " has been created" <<  std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << PURPLE << "DiamondTrap " << this->getName() << " has been destroyed" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &orig)
{
	if (this != &orig)
	{
		setName(orig._name);
		setHitPoints(orig._hitPoints);
		setEnergyPoints(orig._energyPoints);
		setAttackDamage(orig._attackDamage);
	}
	std::cout << "DiamondTrap " << this->getName() << " has been created with assignment operator " << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig) : 
	ClapTrap(orig),
	ScavTrap(orig),
	FragTrap(orig)
{
	setName(orig._name);
	setHitPoints(orig._hitPoints);
	setEnergyPoints(orig._energyPoints);
	setAttackDamage(orig._attackDamage);
	std::cout << BLUE << "DiamondTrap " << this->getName() << " has been created with copy constructor" << RESET << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->getName() << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string	DiamondTrap::getName(void) const 
{
	return (this->_name);
}