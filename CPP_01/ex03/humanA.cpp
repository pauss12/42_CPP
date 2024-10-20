#include "HumanA.hpp" 

// Constructor, initializes the name with the name parameter and the weapon with the Weapon constructor
HumanA::HumanA(std::string name, Weapon &Weapon): weapon(Weapon)
{
    this->name = name;
}

// Destructor
HumanA::~HumanA()
{
    return ;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

Weapon &HumanA::getWeapon()
{
    return (this->weapon);
}