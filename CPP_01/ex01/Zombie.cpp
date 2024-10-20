#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie constructor called" << std::endl;
	this->name = "";
}

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie constructor called" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destructor called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}