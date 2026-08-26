#include "AForm.hpp"

// ###################### CONSTRUCTORS #################################
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << BLUE << "The default Form has been created! " << RESET << std::endl;
}


AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name.empty() ? "Default" : name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (name.empty())
		std::cout << ORANGE << "WARNING" << RESET << std::endl << "The form has been named as 'Default' " << std::endl;
	else if (gradeToExecute < 1)
		throw AForm::GradeTooHighException("Cannot create Form: Bureaucrat grade to execute is too high!");
	else if (gradeToExecute > 150)
		throw AForm::GradeTooLowException("Cannot create Form: Bureaucrat grade to execute is too low!");
	else if (gradeToSign < 1)
		throw AForm::GradeTooHighException("Cannot create Form: Bureaucrat grade to sign is too high!");
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException("Cannot create Form: Bureaucrat grade to sign is too low!");
	else
		std::cout << LIGHT_BLUE << "The parameter Form with [ " << this->getName() << " ] as name, has been created!" << RESET << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name.empty() ? "Default" : src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
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
AForm::GradeTooHighException::GradeTooHighException(const char *errorMessage) : _errorMessage(errorMessage) {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (_errorMessage);
}

AForm::GradeTooLowException::GradeTooLowException(const char *errorMessage) : _errorMessage(errorMessage) {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (_errorMessage);
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
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException("Bureaucrat grade to sign is too low!");
	this->_isSigned = true;
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
