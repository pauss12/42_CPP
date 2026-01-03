#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	this->_type = "Dog";
	if (this->brain == NULL)
		this->brain = new Brain();
	std::cout << CYAN << "Dog Default Constructor called" <<  std::endl;
}

Dog::Dog(const Dog& orig) : Animal(orig), brain(new Brain(*orig.brain))
{
	*this = orig;
	if (this->brain)
	{
		delete this->brain;
		this->brain = new Brain(*orig.brain);
	}
	std::cout << CYAN << "Dog Copy Constructor called" <<  std::endl;
}

Dog& Dog::operator=(const Dog& orig) 
{
	if (this != &orig) 
	{
		Animal::operator=(orig);
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*orig.brain);
	}
	std::cout << CYAN << "Dog Copy Assignment Operator called" <<  std::endl;
	return (*this);
}

Dog::~Dog() 
{
	std::cout << PURPLE << "Dog Destructor called" <<  std::endl;
	if (this->brain != NULL)
		delete this->brain;
}

void Dog::makeSound() const 
{
	std::cout << GREEN << "Woof!" << RESET << std::endl;
}


// FUNCIONES PARA EL CEREBRO E IDEAS ----------------------------------------------
Brain* Dog::getBrain() const 
{
	return (this->brain);
}


void Dog::setIdea(int index, const std::string& idea) 
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
	std::cout << LIGHT_BLUE << "Dog ----- " << RESET << PURPLE << "Idea set at index " << index << ": " << idea << RESET << std::endl;
}

std::string Dog::getIdea(int index) const 
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

void Dog::selectRandomIdea(int index)
{
	int randomIndex;

	std::string ideas[10] = {
		"Chase the ball",
		"Bark at the mailman",
		"Dig a hole",
		"Roll in the grass",
		"Play fetch",
		"Guard the house",
		"Sniff everything",
		"Chase my tail",
		"Take a nap",
		"Beg for food"
	};
	randomIndex = rand() % 10;
	this->setIdea(index, ideas[randomIndex]);
}
