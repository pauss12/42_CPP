#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
	public:
		Dog();
		Dog(const Dog& orig);
		Dog& operator=(const Dog& orig);
		virtual ~Dog();

		virtual void makeSound() const;
};

#endif