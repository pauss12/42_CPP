# include "DiamondTrap.hpp"

//? No entiendo porque en FragTrap, scavTrap tiene que ser virtual

DiamondTrap::DiamondTrap() : 
    ClapTrap("Default '_clap_name'"),
    ScavTrap(),
    FragTrap()
{
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	std::cout << BLUE << "DiamondTrap " << this->getName() << " has been created with default constructor" << RESET <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
    ClapTrap(name + "_clap_name"),
    ScavTrap(),
    FragTrap()
{
    this->_name = name;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
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
		this->_name = orig._name;
		this->_hitPoints = orig._hitPoints;
		this->_energyPoints = orig._energyPoints;
		this->_attackDamage = orig._attackDamage;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig) : 
	ClapTrap(orig),
	ScavTrap(orig),
	FragTrap(orig)
{
	*this = orig;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}



