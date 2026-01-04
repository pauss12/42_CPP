#include "HumanA.hpp" 

HumanA::HumanA() : weapon(*(new Weapon()))
{
	this->name = "";
}

HumanA::HumanA(std::string name, Weapon &Weapon): weapon(Weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << GREEN << this->name << RESET << " has been destroyed." << std::endl;
	return ;
}

void HumanA::attack()
{
	if (this->weapon.getType().empty())
	{
		std::cout << RED << "Cannot attack with an empty weapon type" << RESET << std::endl;
		return;
	}
	std::cout << CYAN << this->name << RESET << " attacks with their " << PURPLE << this->weapon.getType() << RESET << std::endl;
}
