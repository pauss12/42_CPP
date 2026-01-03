#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "";
	std::cout << BLUE << "Weapon Default Constructor called" << RESET << std::endl;
}

Weapon::Weapon(std::string type)
{
	if (type.empty())
		std::cout << RED << "Invalid weapon type" << RESET << std::endl;
	else
	{
		std::cout << BLUE << "Weapon " << type << RESET << " created" << std::endl;
		this->type = type;
	}
}

Weapon::~Weapon()
{
	std::cout << BLUE << "Weapon " << this->type << RESET << " destroyed" << std::endl;
}

// El primer const se refiere a que no se puede cambiar el tipo de arma dentro de la funcion del getters
// Mientras tanto, el const detras, significa que no se puede modificar la instancia del objeto 
const std::string& Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	if (type.empty())
		std::cout << RED << "Invalid weapon type" << RESET << std::endl;
	else
		this->type = type;
}