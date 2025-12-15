#include "Cat.hpp"

/**
 * Para poder crear el Gato, primero tienes que crear el Animal.
 * Si no hay Animal, no puede haber Gato.
 * */
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << CYAN << "Cat Default Constructor called" <<  std::endl;
}

Cat::Cat(const Cat& orig) : Animal(orig)
{
	(*this) = orig;
	std::cout << CYAN << "Cat Copy Constructor called" <<  std::endl;
}

Cat&	Cat::operator=(const Cat& orig)
{
	if (this != &orig)
	{
		Animal::operator=(orig);
	}
	std::cout << CYAN << "Cat Copy Assignment Operator called" <<  std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << CYAN << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miauu!" << std::endl;
}