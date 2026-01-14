#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter {

	private:
		std::string _name;
		AMateria* _inventory[4];
		
	public:
		Character();
		Character(std::string name);
		Character(const Character &orig);
		Character &operator=(const Character &orig);
		virtual ~Character();

		// En el caso de las funciones, como habria que sobreescribirlas, si que hay que volver a ponerlas
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
