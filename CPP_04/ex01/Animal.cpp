#include "Animal.hpp"

Animal::Animal() : _type("Unknown") 
{
	// std::cout << CYAN << "Animal Default Constructor called" <<  std::endl;
}

Animal::Animal(const Animal& orig) 
{
	*this = orig;
	// std::cout << BLUE << "Animal Copy Constructor called" <<  std::endl;
}

Animal& Animal::operator=(const Animal& orig) 
{
	if (this != &orig)
		this->_type = orig._type;
	return (*this);
}

Animal::~Animal() 
{
	// std::cout << PURPLE << "Animal Destructor called" <<  std::endl;
}

void Animal::makeSound() const 
{
	std::cout << GREEN << "The Animal makes a sound!" << std::endl;
}

std::string Animal::getType() const 
{
	return this->_type;
}