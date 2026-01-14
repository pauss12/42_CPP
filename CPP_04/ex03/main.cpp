#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << std::endl << YELLOW << "----- AMateria instance -----" << RESET << std::endl;
	std::cout << "It is commented due to the abstract nature of AMateria." << std::endl;
	// AMateria* materia = new AMateria();

	std::cout << std::endl << YELLOW << "----- Ice instance -----" << RESET << std::endl;
	AMateria* ice = new Ice();
	AMateria *cure = new Cure();
	// ice->use(*ice);
	delete ice;
	delete cure;

	return (0);
}