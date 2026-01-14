#include "AMateria.hpp"

AMateria::AMateria() : _type("") 
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) : _type(src._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & orig)
{
	if (this != &orig)
	{
		_type = orig._type;
	}
	std::cout << "AMateria assignment operator called" << std::endl;
	return (*this);
}

AMateria::~AMateria() 
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << LIGHT_BLUE << "* there is no AMateria instance to use. Is not instantiated *" << RESET << std::endl;

}

