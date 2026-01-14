#ifndef Ice_HPP
#define Ice_HPP

#include <string>
#include <iostream>

# include "AMateria.hpp"

class Ice : public AMateria
{
	protected:
		std::string _type;

	public:
		Ice();
		Ice(std::string const &type);
		Ice(Ice const & src);
		~Ice();
		Ice &operator=(Ice const & orig);
	
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif