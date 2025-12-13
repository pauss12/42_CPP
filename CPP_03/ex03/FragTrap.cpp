# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BLUE << "FragTrap " << this->_name << " has been created with default constructor" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BLUE << "FragTrap " << this->_name << " has been created with name constructor" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &orig) : ClapTrap(orig)
{
	*this = orig;
	std::cout << BLUE << "FragTrap " << this->_name << " has been created with copy constructor" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &orig)
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

FragTrap::~FragTrap(void)
{
	std::cout << PURPLE << "FragTrap " << this->_name << " has been destroyed" << RESET << std::endl;
}

// FUNCTIONS -----------------------------------
void FragTrap::highFivesGuys(void)
{
	std::cout << LIGHT_BLUE << "FragTrap " << this->_name << " says HIGH FIVE GUYS!" << RESET << std::endl;
}
