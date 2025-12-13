#include "Dog.hpp"

Dog::Dog() : Animal() 
{
	this->_type = "Dog";
	std::cout << CYAN << "Dog Default Constructor called" <<  std::endl;
}

Dog::Dog(const Dog& orig) : Animal(orig) 
{
	*this = orig;
	std::cout << CYAN << "Dog Copy Constructor called" <<  std::endl;
}

Dog& Dog::operator=(const Dog& orig) 
{
	if (this != &orig) 
	{
		Animal::operator=(orig);
	}
	std::cout << CYAN << "Dog Copy Assignment Operator called" <<  std::endl;
	return *this;
}

Dog::~Dog() 
{
	std::cout << CYAN << "Dog Destructor called" <<  std::endl;
}

void Dog::makeSound() const 
{
	std::cout << "Woof!" << std::endl;
}
