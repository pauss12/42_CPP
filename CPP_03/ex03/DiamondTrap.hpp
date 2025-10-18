# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
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