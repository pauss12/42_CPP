#include "HumanB.hpp"

HumanB::HumanB()
{
	this->name = "";
	this->weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << GREEN << this->name << RESET << " has been destroyed." << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << CYAN << this->name << RESET << " attacks with their " << PURPLE << this->weapon->getType() << RESET << std::endl;
	else
		std::cout << ORANGE << this->name << " is unarmed and cannot attack." << RESET << std::endl;
}
