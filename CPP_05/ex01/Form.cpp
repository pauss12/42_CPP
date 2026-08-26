#include "Form.hpp"

// ###################### CONSTRUCTORS #################################
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << BLUE << "The default Form has been created! " << RESET << std::endl;
}


Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name.empty() ? "Default" : name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (name.empty())
		std::cout << ORANGE << "WARNING" << RESET << std::endl << "The form has been named as 'Default' " << std::endl;
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException("Grade to execute is too high!");
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException("Grade to execute is too low!");
	if (gradeToSign < 1)
		throw Form::GradeTooHighException("Grade to sign is too high!");
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException("Grade to sign is too low!");
	else
		std::cout << LIGHT_BLUE << "The parameter Form with [ " << this->getName() << " ] as name, has been created!" << RESET << std::endl;
}

Form::Form(const Form &src) : _name(src._name.empty() ? "Default" : src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << CYAN << "The copy constructor has been called, it has given to the Form the name: " << src.getName() << RESET << std::endl;
}

Form& Form::operator=(const Form& orig)
{
	if (this != &orig)
	{
		_isSigned = orig._isSigned;
		std::cout << BLUE << "The Form with assignment operator has been created! " << RESET << std::endl;
	}
	return (*this);
}

// ###################### DESTRUCTORS ##################################
Form::~Form()
{
	if (this->getName().empty())
		std::cout << PURPLE << "The form with no NAME has been deleted " << RESET << std::endl;
	else
		std::cout << PURPLE << "The form with [" << this->getName() << "] has been deleted " << RESET << std::endl;
}


// ###################### EXCEPTIONS ###################################
Form::GradeTooHighException::GradeTooHighException(const char *errorMessage) : _errorMessage(errorMessage) {}

const char *Form::GradeTooHighException::what() const throw()
{
	return (_errorMessage);
}

Form::GradeTooLowException::GradeTooLowException(const char *errorMessage) : _errorMessage(errorMessage) {}

const char *Form::GradeTooLowException::what() const throw()
{
	return (_errorMessage);
}

// ###################### GETTERS ######################################
const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

// ####################### FUNCTION BE SIGNED ##########################
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException("Bureaucrat grade to sign is too low!");
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form const& form)
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
