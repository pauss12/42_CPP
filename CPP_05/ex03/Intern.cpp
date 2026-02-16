#include "Intern.hpp"

Intern::Intern()
{
	std::cout << CYAN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << BLUE << "Intern copy constructor called" << RESET << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		std::cout << LIGHT_BLUE << "Intern assignment operator called" << RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << PURPLE << "Intern destructor called" << RESET << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string	forms[3] = { "shrubbery", "robotomy", "presidential" };
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << GREEN "Intern creates: " << formName << RESET << std::endl;
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
				default:
					break ;
			}
		}
	}
	std::cout << RED "ERROR " << RESET<< "Intern couldn't create form of type: " << formName << RESET << std::endl;
	return (NULL);
}