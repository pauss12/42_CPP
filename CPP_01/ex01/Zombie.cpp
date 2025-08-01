#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << CYAN << this->name << RESET << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << PURPLE << this->name << RESET << ": BraiiiiiiinnnzzzZ..."  << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}