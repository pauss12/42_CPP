#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << BLUE << "The Presidential Pardon Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been created" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << BLUE << "The Presidential Pardon Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been copied" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "The Presidential Pardon Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been destroyed" << RESET << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException("The bureaucrat's grade is too low to execute the form");
	else if (!this->getIsSigned())
		throw AForm::GradeTooLowException("The form is not signed yet");

	std::cout << GREEN << "[ " << this->_target << " ] has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}