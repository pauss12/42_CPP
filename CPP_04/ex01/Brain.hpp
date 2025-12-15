#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {

	private:
		std::string *ideas;

	public:
		Brain();
		Brain(const Brain& orig);
		Brain& operator=(const Brain& orig);
		~Brain();
	
};

#endif