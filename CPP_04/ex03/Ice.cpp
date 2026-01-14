#include "Ice.hpp"

Ice::Ice() : AMateria("ice"), _type("ice") 
{
	std::cout << CYAN << "Ice default constructor called" << RESET << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type), _type(type) 
{
	std::cout << ORANGE << "Ice parameterized constructor called" << RESET << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src), _type(src._type) 
{
	std::cout << BLUE << "Ice copy constructor called" << RESET << std::endl;
}

Ice &Ice::operator=(Ice const & orig)
{
	if (this != &orig)
	{
		AMateria::operator=(orig);
		_type = orig._type;
	}
	std::cout << LIGHT_GREEN << "Ice assignment operator called" << RESET << std::endl;
	return (*this);
}

Ice::~Ice() 
{
	std::cout << PURPLE << "Ice destructor called" << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	std::cout << ROSE << "Ice clone constructor called" << RESET << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << LIGHT_BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}

