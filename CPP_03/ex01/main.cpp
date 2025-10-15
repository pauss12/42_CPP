
# include "ClapTrap.hpp"

int main(void)
{
	// Con un solo objeto, se prueba que las funciones funcionan correctamente
	ClapTrap a("CL4P-TP");
	a.attack("Target1");

	a.takeDamage(5);
	a.beRepaired(3);
	a.takeDamage(10);
	a.beRepaired(5);
	
	return (0);
}