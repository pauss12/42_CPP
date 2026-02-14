#include "AForm.hpp"

// ###################### CONSTRUCTORS #################################
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << BLUE << "The default Form has been created! " << RESET << std::endl;
}


AForm::AForm(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute) : _name(name.empty() ? "Default" : name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (name.empty())
		std::cout << ORANGE << "WARNING" << RESET << std::endl << "The form has been named as 'Default' " << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
	std::cout << LIGHT_BLUE << "The parameter Form with [ " << this->getName() << " ] as name, has been created!" << RESET << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name.empty() ? "Default" : src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << CYAN << "The copy constructor has been called, it has given to the Form the name: " << src.getName() << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& orig)
{
	if (this != &orig)
	{
		_isSigned = orig._isSigned;
		std::cout << BLUE << "The Form with assignment operator has been created! " << RESET << std::endl;
	}
	return (*this);
}

// ###################### DESTRUCTORS ##################################
AForm::~AForm()
{
	if (this->getName().empty())
		std::cout << PURPLE << "The form with no NAME has been deleted " << RESET << std::endl;
	else
		std::cout << PURPLE << "The form with [" << this->getName() << "] has been deleted " << RESET << std::endl;
}


// ###################### EXCEPTIONS ###################################
const char *AForm::GradeTooHighException::what() const throw()
{
	std::cout << "The Form class has thrown an exception: " << std::endl << std::endl;
	static const char* msg = RED "ERROR\n" RESET "Grade too HIGH";
	return (msg);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too LOW");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

// ###################### GETTERS ######################################
const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}


//  ###################### FUNCTION BE SIGNED ##########################
void AForm::beSigned(const Bureaucrat &bureaucrat, bool calledByBureaucrat)
{
	if (this->_name.empty())
	{
		std::cout << RED << "ERROR" << RESET << " [" << bureaucrat.getName() << "] cannot sign [" << this->getName() << "] because it has no name." << std::endl;
		return ;
	}
	if (this->_isSigned)
	{
		std::cout << YELLOW << "Form [" << this->getName() << "] is already signed." << RESET << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		if (calledByBureaucrat)
			this->_isSigned = true;
		else
			std::cout << GREEN << "[" << bureaucrat.getName() << "] signed [" << this->getName() << "]" << RESET << std::endl;
	}
	else
	{
		if (calledByBureaucrat)
			throw AForm::GradeTooLowException();
		else
			std::cout << RED << "ERROR" << std::endl << RESET << "[" << bureaucrat.getName() << "] cannot sign [" << this->getName() << "] because their grade is too low." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, AForm const& form)
{
	os << GREEN << "📋 FORM INFORMATION" << RESET << std::endl
		<< "┌──────────────────────────────────────┐" << std::endl
		<< "│ Name:                    " << form.getName() << std::endl
		<< "│ Signed:                  " 
		<< (form.getIsSigned() ? GREEN "✅ Yes" RESET : RED "❌ No" RESET) << std::endl
		<< "│ Grade to Sign:           " << form.getGradeToSign() << std::endl
		<< "│ Grade to Execute:        " << form.getGradeToExecute() << std::endl
		<< "└──────────────────────────────────────┘" << RESET << std::endl;

	return (os);
}
