#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "A WrongCat is created\n";
}

WrongCat::WrongCat(const WrongCat& orig) : WrongAnimal(orig)
{
	(*this) = orig;
	std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& orig)
{
	if (this != &orig)
	{
		WrongAnimal::operator=(orig);
	}
	std::cout << "WrongCat Copy Assignment Operator called\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat is destroyed\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Miauu! (but wrong)\n";
}
