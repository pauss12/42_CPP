#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	std::cout << BLUE << "Weapon " << type << RESET << " created" << std::endl;
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << BLUE << "Weapon " << this->type << RESET << " destroyed" << std::endl;
}

const std::string Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}