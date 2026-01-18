# include "Character.hpp"

Character::Character()
{
	this->_name = "";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << CYAN << "Character default constructor called" << RESET << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << CYAN << "Character parameterized constructor called" << RESET << std::endl;
}

Character::Character(const Character &orig) : _name(orig._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (orig._inventory[i])
			this->_inventory[i] = orig._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Copying the Character " << this->getName() << " ;)" << std::endl;
}

Character &Character::operator=(const Character &orig)
{
	if (this != &orig)
	{
		this->_name = orig._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			// Una vez sabemos que esta todo limpio, solo se asigna
			if (orig._inventory[i])
				this->_inventory[i] = orig._inventory[i]->clone();
		}
	}
	std::cout << "The Character provided has been assigned to the new one " << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "Deleting the Character " << this->_name << "\n";
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

// METHODS ---- ------------------------------------------

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	// Se recorre todos las posiciones para ver si hay algun hueco libre
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			// Significa que no hay nada en esa posicion
			this->_inventory[i] = m;
			std::cout << "Equipping " << m->getType() << " to " << this->getName() << std::endl;
			return ;
		}
	}
	// En el caso de que no encuentre ninguna posicion libre:
	std::cout << "The inventory is FULL. Unequip a Materia to be able to equip it " << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
	{
		std::cout << " The Materia you are trying to unequip in index [" << idx << "] is not available. :(" << std::endl;
		return ;
	}
	if (this->_inventory[idx]) 
	{
		std::cout << " That Materia " << this->_inventory[idx]->getType() << "in the index  [" << idx << "] has been unequipped." << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
	{
		std::cout << " The Materia you are trying to use in index [" << idx << "] is not available. :(" << std::endl;
		return ;
	}
	std::cout << this->getName() << " is using [" << this->_inventory[idx]->getType() << "] on " << target.getName() << std::endl;
	this->_inventory[idx]->use(target);
}

// GETTERS

AMateria* Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4)
		return NULL;
	return this->_inventory[idx];
}
