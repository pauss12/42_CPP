#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	std::cout << "Weapon " << type << " created" << std::endl;
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

const std::string &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}