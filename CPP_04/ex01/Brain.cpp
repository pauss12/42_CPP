#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& orig) {
	std::cout << "Brain copy constructed" << std::endl;
	*this = orig;
}

Brain& Brain::operator=(const Brain& orig) 
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &orig) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = orig.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brain with ideas destructed" << std::endl;
	delete[] ideas;
}
