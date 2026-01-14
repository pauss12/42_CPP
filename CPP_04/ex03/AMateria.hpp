#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		AMateria & operator=(AMateria const & orig);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif