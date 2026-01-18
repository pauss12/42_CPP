#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource 
{	
	private:
		AMateria* _materiasSource[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &orig);
		MateriaSource &operator=(const MateriaSource &rhs);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
