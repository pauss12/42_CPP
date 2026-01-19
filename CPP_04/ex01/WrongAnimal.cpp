#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongUnknown";
	std::cout << YELLOW << "WrongAnimal Default Constructor called" <<  std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << YELLOW << "WrongAnimal Parameterized Constructor called" <<  std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& orig)
{
	*this = orig;
	std::cout << YELLOW << "WrongAnimal Copy Constructor called" <<  std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& orig)
{
	if (this != &orig)
		this->_type = orig._type;
	std::cout << YELLOW << "WrongAnimal Copy Assignment Operator called" <<  std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << YELLOW << "WrongAnimal Destructor called" <<  std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << RED << "The WrongAnimal makes a wrong sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

