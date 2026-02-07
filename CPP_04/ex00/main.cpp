#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* spike = new Dog();
	Animal* tom = new Cat();

	std::cout << tom->getType() << " " << std::endl;
	std::cout << tom->getType() << " " << std::endl;
	tom->makeSound();
	spike->makeSound();
	animal->makeSound();

	delete animal;
	delete spike;
	delete tom;

	// const WrongAnimal*	meta = new WrongAnimal();
	// std::cout << "\n\n";
	// const WrongAnimal*	i = new WrongCat();
	
	// std::cout << "\n\n";
	// std::cout << i->getType() << " \n" << std::endl;
	// std::cout << "\n\n";
	// meta->makeSound();
	// std::cout << "\n\n";
	// i->makeSound();
	// std::cout << "\n\n";

	// delete meta;
	// delete i;

	return (0);
}