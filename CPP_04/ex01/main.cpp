#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

	// Arrays de 10 Animales intercalados

	Animal* animals[10];
	std::cout << std::endl << YELLOW << "----- CREATING ANIMALS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// GIVING THEM RANDOM IDEAS FROM A LIST
	std::cout << std::endl << YELLOW << "----- GIVING RANDOM IDEAS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		int randomIndex = rand() % 10;
		animals[i]->setIdeas(0, ideas[randomIndex]);
	}

	std::cout << std::endl << YELLOW << "----- MAKING SOUND AND SHOWING TYPES -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << GRAY << animals[i]->getType() << " " << RESET << std::endl;
		animals[i]->makeSound();
	}

	std::cout << std::endl << YELLOW << "----- FREEING MEMORY -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return (0);
}