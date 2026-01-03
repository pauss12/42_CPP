#include "Cat.hpp"

/**
 * Para poder crear el Gato, primero tienes que crear el Animal.
 * Si no hay Animal, no puede haber Gato.
 * */
Cat::Cat() : Animal(), brain(new Brain())
{
	this->_type = "Cat";
	if (this->brain == NULL)
		this->brain = new Brain();
	std::cout << CYAN << "Cat Default Constructor called" <<  std::endl;
}

Cat::Cat(const Cat& orig) : Animal(orig), brain(new Brain(*orig.brain))
{
	(*this) = orig;
	if (this->brain)
	{
		delete this->brain;
		this->brain = new Brain(*orig.brain);
	}
	std::cout << CYAN << "Cat Copy Constructor called" <<  std::endl;
}

Cat&	Cat::operator=(const Cat& orig)
{
	if (this != &orig) 
	{
		Animal::operator=(orig);
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*orig.brain);
	}
	std::cout << BLUE << "Cat Copy Assignment Operator called" <<  std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << ROSE << "Cat destructor called" << std::endl;
	if (this->brain != NULL)
		delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << GREEN << "Miauu!" << RESET << std::endl;
}

// FUNCIONES PARA EL CEREBRO E IDEAS ----------------------------------------------
Brain* Cat::getBrain() const 
{
	return (this->brain);
}

void Cat::setIdea(int index, const std::string& idea) 
{
	if (index < 0 || index >= 100)
	{
		std::cout << RED << "You entered a wrong index to set idea" << RESET << std::endl;
		return;
	}
	if (idea.empty() || this->brain == NULL)
	{
		std::cout << RED << "Invalid idea or brain is not initialized" << RESET << std::endl;
		return;
	}
	this->brain->setIdea(index, idea);
	std::cout << CYAN << "Cat ----- " << RESET << PURPLE << "Idea set at index " << index << ": " << idea << RESET << std::endl;
}

void Cat::selectRandomIdea(int index)
{
	int randomIndex;

	std::string ideas[10] = {
		"Chase the mouse",
		"Climb the tree",
		"Scratch the furniture",
		"Sleep in the sun",
		"Meow at the door",
		"Play with a ball of yarn",
		"Watch birds from the window",
		"Hide in a box",
		"Lick my paws",
		"Demand food"
	};
	
	// Coge una random
	randomIndex = rand() % 10;
	this->setIdea(index, ideas[randomIndex]);
}

std::string Cat::getIdea(int index) const 
{
	if (index < 0 || index >= 100)
	{
		std::cout << RED << "You entered a wrong index to get idea" << RESET << std::endl;
		return "";
	}
	if (brain && brain->getIdea(index) != "")
		return (brain->getIdea(index));
	std::cout << RED << "No idea found at index " << index << RESET << std::endl;
	return "";
}
