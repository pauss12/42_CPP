#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* animals[10];

	// ANIMAL ARRAY CREATION ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- CREATING ANIMALS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// GIVING THEM RANDOM IDEAS FROM A LIST ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- ASSIGNING RANDOM IDEAS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			static_cast<Dog*>(animals[i])->selectRandomIdea(i);
		else
			static_cast<Cat*>(animals[i])->selectRandomIdea(i);
	}

	// TESTING SOUNDS AND SHOWING TYPES ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- MAKING SOUND AND SHOWING TYPES -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << GRAY << animals[i]->getType() << " " << RESET << std::endl;
		animals[i]->makeSound();
	}

	// SHOWING ALL IDEAS ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- SHOWING IDEAS -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			std::cout << GRAY << "Dog: " << static_cast<Dog*>(animals[i])->getIdea(i) << RESET << std::endl;
		else
			std::cout << GRAY << "Cat: " << static_cast<Cat*>(animals[i])->getIdea(i) << RESET << std::endl;
	}

	// CHECK AN IDEA OUT OF RANGE ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- SHOWING IDEAS OUT OF RANGE-----" << RESET << std::endl;
	std::cout << GRAY << "Dog: " << static_cast<Dog*>(animals[0])->getIdea(100) << RESET << std::endl;
	std::cout << GRAY << "Cat: " << static_cast<Cat*>(animals[1])->getIdea(100) << RESET << std::endl;

	// CHECK AN IDEA NOT ASSIGNED ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- SHOWING IDEAS NOT ASSIGNED -----" << RESET << std::endl;
	std::cout << GRAY << "Dog: " << static_cast<Dog*>(animals[0])->getIdea(10) << RESET << std::endl;
	std::cout << GRAY << "Cat: " << static_cast<Cat*>(animals[1])->getIdea(10) << RESET << std::endl;

	// CHECK DEEP COPY DOG ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- DEEP COPY TEST DOG -----" << RESET << std::endl;
	Dog dog1;
	dog1.setIdea(0, "Original Dog Idea");
	Dog dog2 = dog1;
	std::cout << GRAY << "Dog2: " << dog2.getIdea(0) << RESET << std::endl;

	dog1.setIdea(0, "Modified Dog Idea");
	std::cout << GRAY << "Dog1: " << dog1.getIdea(0) << RESET << std::endl;
	std::cout << GRAY << "Dog2: " << dog2.getIdea(0) << RESET << std::endl;

	// CHECK DEEP COPY CAT ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- DEEP COPY TEST CAT -----" << RESET << std::endl;
	Cat cat1;
	cat1.setIdea(0, "Original Cat Idea");
	Cat cat2 = cat1;
	std::cout << GRAY << "Cat2: " << cat2.getIdea(0) << RESET << std::endl;

	cat1.setIdea(0, "Modified Cat Idea");
	std::cout << std::endl << GRAY << "----------------- Cat1 ==>  " << cat1.getIdea(0) << RESET << std::endl;
	std::cout << GRAY << "----------------- Cat2 ==>  " << cat2.getIdea(0) << RESET << std::endl;

	// CHECK IF ANIMAL HAS IDEAS ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- ANIMAL IDEAS TEST -----" << RESET << std::endl;
	Animal animal;
	animal.setIdeas(0, "Animal Idea");
	std::cout << GRAY << "Animal: " << animal.getIdeas(0) << RESET << std::endl;

	// FREEING MEMORY ------------------------------------------------------------------------------------------------------------------
	std::cout << std::endl << YELLOW << "----- FREEING MEMORY -----" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return (0);
}