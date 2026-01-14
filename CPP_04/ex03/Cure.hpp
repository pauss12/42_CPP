#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>

# include "AMateria.hpp"

class Cure : public AMateria
{
	protected:
		std::string _type;

	public:
		Cure();
		Cure(std::string const &type);
		Cure(Cure const & src);
		~Cure();
		Cure &operator=(Cure const & orig);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
