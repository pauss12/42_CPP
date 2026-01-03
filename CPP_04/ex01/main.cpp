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
	std::cout << std::endl << YELLOW << "----- ASSIGNING RANDOM IDEAS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			static_cast<Dog*>(animals[i])->selectRandomIdea(i);
		else
			static_cast<Cat*>(animals[i])->selectRandomIdea(i);
	}

	std::cout << std::endl << YELLOW << "----- MAKING SOUND AND SHOWING TYPES -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << GRAY << animals[i]->getType() << " " << RESET << std::endl;
		animals[i]->makeSound();
	}

	std::cout << std::endl << YELLOW << "----- SHOWING IDEAS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			std::cout << GRAY << "Dog: " << static_cast<Dog*>(animals[i])->getIdea(i) << RESET << std::endl;
		else
			std::cout << GRAY << "Cat: " << static_cast<Cat*>(animals[i])->getIdea(i) << RESET << std::endl;
	}

	// Intentar ver una idea fuera del rango
	std::cout << std::endl << YELLOW << "----- SHOWING IDEAS OUT OF RANGE-----" << RESET << std::endl;
	std::cout << GRAY << "Dog: " << static_cast<Dog*>(animals[0])->getIdea(100) << RESET << std::endl;
	std::cout << GRAY << "Cat: " << static_cast<Cat*>(animals[1])->getIdea(100) << RESET << std::endl;

	//Intentar ver una idea que no se ha asignado, hemos asignado
	std::cout << std::endl << YELLOW << "----- SHOWING IDEAS NOT ASSIGNED -----" << RESET << std::endl;
	std::cout << GRAY << "Dog: " << static_cast<Dog*>(animals[0])->getIdea(10) << RESET << std::endl;
	std::cout << GRAY << "Cat: " << static_cast<Cat*>(animals[1])->getIdea(10) << RESET << std::endl;

	std::cout << std::endl << YELLOW << "----- FREEING MEMORY -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return (0);
}