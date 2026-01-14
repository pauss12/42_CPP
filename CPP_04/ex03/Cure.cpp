#include "Cure.hpp"

Cure::Cure() : AMateria("cure"), _type("cure") 
{
	std::cout << CYAN << "Cure default constructor called" << RESET << std::endl;
}

Cure::Cure(std::string const &type) : AMateria(type), _type(type) 
{
	std::cout << ORANGE << "Cure parameterized constructor called" << RESET << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src), _type(src._type) 
{
	std::cout << BLUE << "Cure copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(Cure const & orig)
{
	// No hay necesidad de hacer nada aquí, ya que AMateria ya maneja la asignación
	std::cout << LIGHT_GREEN << "Cure assignment operator called" << RESET << std::endl;
	(void)orig;
	return (*this);
}

Cure::~Cure() 
{
	std::cout << PURPLE << "Cure destructor called" << RESET << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << ROSE << "Cure clone constructor called" << RESET << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << LIGHT_BLUE << "* heals " << target.getName() << " ’s wounds *" << RESET << std::endl;
}

