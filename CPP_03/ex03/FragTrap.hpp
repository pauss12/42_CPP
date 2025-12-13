#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &orig);
		~FragTrap(void);
		
		void highFivesGuys(void);
		FragTrap& operator=(const FragTrap &orig);
	
};

# endif