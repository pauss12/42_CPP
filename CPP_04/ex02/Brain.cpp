#include "Brain.hpp"

Brain::Brain() {
	std::cout << LIGHT_BLUE << "Brain constructed" << RESET << std::endl;
}

Brain::Brain(const Brain& orig) {
	std::cout << LIGHT_GREEN << "Brain copy constructed" << RESET << std::endl;
	for (int i = 0; i < 100 ; i++)
	{
		this->ideas[i] = orig.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& orig) 
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &orig) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = orig.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() 
{
	std::cout << ORANGE << "Brain with ideas destructed" << RESET << std::endl;
}


// GETTERS AND SETTERS --------------------------------------------------
void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return "";
}