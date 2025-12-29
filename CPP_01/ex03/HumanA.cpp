#include "HumanA.hpp" 

//? NO TERMINO DE ENTENDER EL :weapon(Weapon) 
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
    std::cout << CYAN << this->name << RESET << " attacks with their " << PURPLE << this->weapon.getType() << RESET << std::endl;
}
