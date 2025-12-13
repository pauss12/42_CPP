# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &orig);
		DiamondTrap& operator=(const DiamondTrap &orig);
		~DiamondTrap(void);
		using ScavTrap::attack;
		void	whoAmI(void);
};

# endif