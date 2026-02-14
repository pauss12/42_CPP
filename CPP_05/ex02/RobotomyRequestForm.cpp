#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", false, 72, 45), _target(target)
{
	std::cout << BLUE << "The Robotomy Request Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been created" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << BLUE << "The Robotomy Request Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been copied" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "The Robotomy Request Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been destroyed" << RESET << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::cerr << RED << "The bureaucrat's grade is too low to execute the form" << RESET << std::endl;
		return;
	}

	std::cout << "** Making Drilling Noises **" << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << GREEN << "[ " << this->_target << " ] has been robotomized successfully" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "[ " << this->_target << " ] has failed to robotomize" << RESET << std::endl;
	}
}