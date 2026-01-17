# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
	ClapTrap("Default '_clap_name'"),
	ScavTrap(),
	FragTrap()
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << BLUE << "DiamondTrap " << this->getName() << " has been created with default constructor" << RESET <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap()
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << BLUE << "DiamondTrap " << this->getName() << " has been created" << RESET <<  std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" <<  std::endl;
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