#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << BLUE << "The Shrubbery Creation Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been created" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << BLUE << "The Shrubbery Creation Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been copied" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "The Shrubbery Creation Form with name [ " << this->getName() << " ] and target [ " << this->_target << " ] has been destroyed" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException("The bureaucrat's grade is too low to execute the form");
	else if (!this->getIsSigned())
		throw AForm::GradeTooLowException("The form is not signed yet");

	std::ofstream outfile((this->_target + "_shrubbery").c_str());

	if (!outfile.is_open()) {
		std::cerr << "ERROR: Cannot create shrubbery file" << std::endl;
		return;
	}

	int height = 5;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < height - i; ++j) {
			outfile << " ";
		}
		for (int j = 0; j < i * 2 + 1; ++j) {
			outfile << "*";
		}
		outfile << std::endl;
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < height - 1; ++j) {
			outfile << " ";
		}
		outfile << "|||" << std::endl;
	}

	outfile.close();

	std::cout << GREEN << "The Shrubbery Creation Form has been executed" << RESET << std::endl;
}