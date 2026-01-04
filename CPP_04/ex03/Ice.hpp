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
		Ice(Ice const & src);
		virtual ~Ice();
		Ice & operator=(Ice const & rhs);
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif