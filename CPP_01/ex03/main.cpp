#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		std::cout << std::endl << YELLOW << "----- CREATING HUMAN A -----" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << std::endl << YELLOW << "----- CREATING HUMAN B -----" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << std::endl << YELLOW << "----- CHECKING WEAPON TYPES -----" << RESET << std::endl;
		Weapon weapon1 = Weapon("crude spiked club");
		Weapon weapon2 = Weapon("some other type of club");

		const std::string& weapon1TypeNuevo = weapon1.getType();

		std::cout << "Referencia Nueva  1 ==> " << &weapon1TypeNuevo << std::endl;

		const std::string& weapon2TypeNuevo = weapon1.getType();

		std::cout << std::endl;
		std::cout << "Referencia Nueva  2 ==> " << &weapon2TypeNuevo << std::endl;
	}
	return (0);
}