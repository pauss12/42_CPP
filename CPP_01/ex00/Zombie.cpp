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
	std::cout << CYAN << this->name << RESET << " -- deleted" << std::endl;
}

void	Zombie::announce(void)
{
	if (this->name.empty() || this->name.length() == 0)
		std::cout << RED << "This Zombie has no Name, it cannot be announced" << RESET << std::endl;
	else
		std::cout << PURPLE << this->name << RESET << ": BraiiiiiiinnnzzzZ..."  << std::endl;
}

void Zombie::setName(std::string name)
{
	if (name.empty())
		std::cout << RED << "Invalid Zombie name" << RESET << std::endl;
	else
		this->name = name;
}